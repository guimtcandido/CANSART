import re

def extract_frame_data(file_path):
    frames = []

    with open(file_path, 'r') as file:
        content_str = file.read()

    # Remove comments and extra spaces
    content_str = re.sub(r'/\*.*?\*/|//.*', '', content_str, flags=re.DOTALL).strip()

    # Match the struct definitions
    struct_matches = re.findall(r'struct\s+(\w+)\s*{([^}]*)}', content_str, re.DOTALL)

    print("Struct Matches Found:")
    print(struct_matches)

    for struct_name, struct_content in struct_matches:
        # Extract the ID from the struct name (e.g., 'frame10' -> 10)
        match = re.search(r'frame(\d+)', struct_name)
        if match:
            frame_id = int(match.group(1))
        else:
            frame_id = 0  # Default to 0 if ID is not found

        print(f"Processing struct: {struct_name}, ID extracted: {frame_id}")

        # Initialize the frame with ID and other fields set to 0
        frame = {'ID': frame_id}
        
        # Add placeholders for DATA1 to DATA8 and LENGHT, all set to 0
        for i in range(1, 9):
            frame[f'DATA{i}'] = 0
        frame['LENGHT'] = 0
        
        # Append the frame to the list
        frames.append(frame)

    # Build frame_array from the frames
    frame_array = []
    for frame in frames:
        # Create a frame_row with ID in the first column
        frame_row = [frame['ID']]
        frame_row.append(8)
        # Append DATA1 to DATA8 and LENGHT, all set to 0
        for i in range(2, 10):
            frame_row.append(frame.get(f'DATA{i}', 0))
        

        print(f"Constructed frame_row: {frame_row}")  # Debug print

        frame_array.append(frame_row)

    return frame_array





#r"C:\GITSTUFF\PERSONAL LIBS\CANSART\LabView Library\Cansart Example\cansart_db.h"
#import os
#import re
#
#def extract_frame_data(file_path):
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
