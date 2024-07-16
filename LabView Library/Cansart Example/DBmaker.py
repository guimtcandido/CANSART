import os
import re

def extract_frame_data(file_path):
    frames = []
    with open(file_path, 'rb') as file:
        cleaned_content = file.read().replace(b'\x00', b'')
    content_str = cleaned_content.decode('utf-8', errors='ignore')
    struct_matches = re.findall(r'struct\s+(\w+)\s*{([^}]*)}', content_str, re.DOTALL)
    for struct_match in struct_matches:
        frame_name, frame_content = struct_match
        frame = {'ID': 0}
        fields = re.findall(r'uint8_t\s+(\w+)\s*=\s*(\d+);', frame_content)
        for field_name, field_value in fields:
            frame[field_name] = int(field_value)
        frames.append(frame)
    frame_array = []
    for frame in frames:
        frame_row = [frame.get('ID', 0)]
        for i in range(1, 9):
            frame_row.append(frame.get(f'DATA{i}', 0))
        frame_array.append(frame_row)
    return frame_array

#import re
#file_path = r"D:\7_Cloud\OneDrive\07_Eletronics\0001_Programming\0001_Projects\0001_USART_Protocol\0002_Firmware\Python_Script\cansart_db.h"
#
#def extract_frame_data():
#    frames = []
#    with open(file_path, 'rb') as file:
#        cleaned_content = file.read().replace(b'\x00', b'')
#    content_str = cleaned_content.decode('utf-8', errors='ignore')
#    struct_matches = re.findall(r'struct\s+(\w+)\s*{([^}]*)}', content_str, re.DOTALL)
#    for struct_match in struct_matches:
#        frame_name, frame_content = struct_match
#        frame = {'ID': 0}
#        fields = re.findall(r'uint8_t\s+(\w+)\s*=\s*(\d+);', frame_content)
#        for field_name, field_value in fields:
#            frame[field_name] = int(field_value)
#        frames.append(frame)
#    frame_array = []
#    for frame in frames:
#        frame_row = [frame.get('ID', 0)]
#        for i in range(1, 9):
#            frame_row.append(frame.get(f'DATA{i}', 0))
#        frame_array.append(frame_row)
#    return frame_array

# Example usage:
#file_path = r"D:\7_Cloud\OneDrive\07_Eletronics\0001_Programming\0001_Projects\0001_USART_Protocol\0002_Firmware\Python_Script\cansart_db.h"
#frames_array = extract_frame_data(file_path)
#for frame_row in frames_array:
#    print(frame_row)
