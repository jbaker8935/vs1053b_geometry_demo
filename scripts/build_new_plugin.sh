python3 -c "
import re

# Read the file
with open('./assets/Geom_Plugin_Build.plg', 'r') as f:
    content = f.read()

# Find the plugin array
start = content.find('const unsigned short plugin[] = {')
end = content.find('};', start)
array_text = content[start:end+2]

# Extract hex values
values = re.findall(r'0x[0-9a-fA-F]{4}', array_text)

# Convert to bytes, little endian
data = b''
for val in values:
    num = int(val, 16)
    data += num.to_bytes(2, byteorder='little')

# Write to file
with open('./plugin.bin', 'wb') as f:
    f.write(data)

print(f'Wrote {len(data)} bytes to plugin.bin')
"
cp ./plugin.bin ./assets/plugin.bin
cp ./plugin.bin ./build/assets/plugin.bin
cp ./plugin.bin ./src/assets/plugin.bin

make clean && make -j

