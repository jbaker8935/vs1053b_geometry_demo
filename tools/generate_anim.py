import json
import math

# output file binary format:
# [frame_count: uint16]
# for each frame:'
#   [drone_count: uint16]
#   for each drone:
#       [x: int16][y: int16][z: int16][yaw: uint8][pitch: uint8][roll: uint8]  // note input Z is up, must convert to Y up
# source yaw is in radians, convert to degrees and map to [0, 255]

WORLD_SCALE = 100.0 # scale positions to centimeters


if __name__ == "__main__":
    with open("assets/drone_export.json", "r") as f:
        anim_data = json.load(f)
    with open("assets/drone_anim.bin", "wb") as fout:
        frame_count = len(anim_data)
        # fout.write(frame_count.to_bytes(2, byteorder='little'))
        for f_dat in anim_data:
            # drone_count = len(f_dat['drones'])
            # fout.write(drone_count.to_bytes(2, byteorder='little'))
            for drone in f_dat['drones']:
                x = int(drone['x'] * WORLD_SCALE)  # scale to cm
                y = int(drone['z'] * WORLD_SCALE)
                z = int(drone['y'] * WORLD_SCALE)
                yaw = round((drone['yaw'] % math.tau) / math.tau * 256) % 256
                pitch = round((drone['pitch'] % math.tau) / math.tau * 256) % 256
                roll = round((drone['roll'] % math.tau) / math.tau * 256) % 256                               
                fout.write(x.to_bytes(2, byteorder='little', signed=True))
                fout.write(y.to_bytes(2, byteorder='little', signed=True))
                fout.write(z.to_bytes(2, byteorder='little', signed=True))
                fout.write(yaw.to_bytes(1, byteorder='little'))
                fout.write(pitch.to_bytes(1, byteorder='little'))  
                fout.write(roll.to_bytes(1, byteorder='little'))


    # additionally output a text file for frame 1 with converted values
    # prefer the frame whose 'frame' == 1, otherwise fallback to the first frame
    frame1 = None
    if anim_data:
        frame1 = next((f for f in anim_data if f.get('frame') == 1), anim_data[0])
    if frame1:
        with open("assets/drone_anim_frame1.txt", "w") as tf:
            tf.write("# name\tx\ty\tz\tyaw\tpitch\troll\n")
            for drone in frame1['drones']:
                x = int(drone['x'] * WORLD_SCALE)
                y = int(drone['z'] * WORLD_SCALE)
                z = int(drone['y'] * WORLD_SCALE)
                yaw = round((drone['yaw'] % math.tau) / math.tau * 256) % 256
                pitch = round((drone['pitch'] % math.tau) / math.tau * 256) % 256
                roll = round((drone['roll'] % math.tau) / math.tau * 256) % 256
                tf.write(f"{drone.get('name','')}\t{x}\t{y}\t{z}\t{yaw}\t{pitch}\t{roll}\n")
