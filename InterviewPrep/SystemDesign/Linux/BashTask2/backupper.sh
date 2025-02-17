#!/bin/bash

read -p "Enter the file you want to backup: " target_file

if [ ! -f "$target_file" ]; then
    echo "File not found"
    exit 1
fi

dir_path="$(dirname "$target_file")"
if [ -d "$dir_path" ]; then
    if [ -d "$dir_path/backup" ]; then
        echo "Found a backup folder"
    else
        echo "Making a backup folder"
        mkdir "$dir_path/backup"
    fi
else
    echo "Path to file not found"
    exit 1
fi

filename="${target_file##*/}"
name="${filename%.*}"
extension="${filename##*.}"  
timestamp=$(date +"%Y-%m-%d_%H-%M-%S")

backup_file="${name}_${timestamp}.${extension}"
cp "$target_file" "$dir_path/backup/$backup_file"

echo "Backup created: $dir_path/backup/$backup_file"
