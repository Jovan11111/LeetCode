#! /bin/bash

read -p "Enter the path to the folder you want to organize: " root_dir

if [ -d "$root_dir" ]; then
    echo "Found a path to the directory."
else
    $echo "Path to directory not found."
    exit 1
fi

for file in "$root_dir"/*; do

    if [ -d "$file" ]; then
        echo "Found a directory, skipping..." $file
        continue
    fi
    extension="${file##*.}"
    if [ -d "$root_dir/$extension" ]; then
        echo "Adding to the existing extension folder " $extension
    else
        echo "Making new extension folder " $extension
        mkdir "$root_dir/$extension"
        echo "Adding to the extension folder " $extension
    fi

    mv "$file" "$root_dir/$extension/"
done
