import struct, sys
import os

def unpack_bytes(n, data_bytes):
    # Ensure we have exactly `n` bytes; if the read returned fewer bytes
    # (file truncated), pad the missing bytes with zeros so unpack won't fail.
    # Then extend to 4 bytes (little-endian) for struct.unpack('<I', ...).
    if not isinstance(data_bytes, (bytes, bytearray)):
        data_bytes = bytearray(data_bytes)
    # Pad to requested length if short
    if len(data_bytes) < n:
        data_bytes = bytearray(data_bytes) + (b'\x00' * (n - len(data_bytes)))
    # For 24-bit values, append one zero byte to make 32-bit little-endian
    if n == 3:
        data_bytes = bytearray(data_bytes) + b'\x00'
    # Ensure we have at least 4 bytes to unpack
    if len(data_bytes) < 4:
        data_bytes = bytearray(data_bytes) + (b'\x00' * (4 - len(data_bytes)))
    return struct.unpack('<I', bytes(data_bytes[:4]))[0]

def infer_start_address_from_lst(pgz_file_path):
    """Try to infer _start address from arcade.lst if available."""
    # arcade.lst should be in the same directory as the pgz file
    pgz_dir = os.path.dirname(pgz_file_path)
    if not pgz_dir:
        pgz_dir = '.'
    
    # Try multiple possible locations
    possible_paths = [
        os.path.join(pgz_dir, 'arcade.lst'),         # Same directory as pgz
        'arcade.lst',                                  # Current directory
        os.path.join(pgz_dir, '.builddir', 'arcade.lst'),  # Fallback to project structure
    ]
    
    for lst_path in possible_paths:
        if not os.path.exists(lst_path):
            continue
        
        try:
            with open(lst_path, 'r') as lstf:
                for line in lstf:
                    # Look for symbol table entry: 00000318 g       .text  00000000 _start
                    # Match lines ending with exactly _start (space-separated, not as substring)
                    parts = line.strip().split()
                    if len(parts) >= 5 and parts[-1] == '_start':
                        addr_hex = parts[0]
                        try:
                            return int(addr_hex, 16)
                        except ValueError:
                            pass
        except Exception:
            pass
    
    return None

def read_pgz_file(file_path):
    with open(file_path, 'rb') as file:
        # Read the file type signature (first byte)
        signature = file.read(1)
        
        # Determine the address and size format
        if signature == b'Z':
            address_size_format = 3	    # 24 bit
            print('Signature: "Z"  24-bit addresses\n')
        elif signature == b'z':
            address_size_format = 4     # 32 bit
            print('Signature: "z"  32-bit addresses \n')
        else:
            print("Invalid PGZ file. Signature 'Z' not found.")
            return 
        
        # Read segments
        segment_number = 1
        while True:
            address = unpack_bytes(address_size_format,bytearray(file.read(address_size_format)))
            #print(f'Adr: {address:06x}')
            size = unpack_bytes(address_size_format,bytearray(file.read(address_size_format)))

            if size == 0:
                # Final segment with size $000000 indicates the starting address of the executable
                # If address is zero (from truncated read), try to infer from .lst file
                if address == 0:
                    inferred = infer_start_address_from_lst(file_path)
                    if inferred is not None:
                        print(f"Inferred start address from .builddir/arcade.lst: {hex(inferred)}")
                        address = inferred
                    else:
                        print("Warning: start address is 0x0 (invalid). Could not infer from .builddir/arcade.lst.")
                
                print(f"Segment {segment_number}: Starting address of the executable: {hex(address)}")
                break

            print(f"Segment {segment_number}: Address: ${address:06x}, Size: ${size:06x}  ({size})")

            # Read data of the segment
            data = file.read(size)
            # Process or display data as needed
            # For example, you can print the data in hex format: print(f"Data: {data.hex()}")
            segment_number += 1
        print()

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Add pgz argument to command.")
    else:    
        pgz_file_path = sys.argv[1]
        read_pgz_file(pgz_file_path)
