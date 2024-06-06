import os

folder_path = "/Users/busiu/Desktop/Uczelnia/Projekt przejściowy/vSLAM/test/offlineTesty/img/"

# Get the list of files in the folder
files = os.listdir(folder_path)

# Sort the files in ascending order
files.sort(key=lambda x: int(os.path.splitext(x)[0]) if x != '.DS_Store' else float('inf'))

# Iterate over the files and rename them
for i, file_name in enumerate(files, start=1):
    # Get the file extension
    file_ext = os.path.splitext(file_name)[1]

    # Generate the new file name with leading zeros
    new_file_name = f"{str(i).zfill(3)}{file_ext}"

    # Construct the old and new file paths
    old_file_path = os.path.join(folder_path, file_name)
    new_file_path = os.path.join(folder_path, new_file_name)

    # Rename the file
    os.rename(old_file_path, new_file_path)
