#! /bin/bash

read -p "Enter a log file you want to look for: " target_file

if [ ! -f $target_file ]; then
    echo "File doesn't exist"
    exit 1
fi

filename="${target_file##*/}"
extension="${filename##*.}"

if [ ! "$extension" = "log" ]; then
    echo "File is not a log file"
    exit 1
fi

read -p "Enter a word you want to find in the file: " target_word

read -p "Do you want the word to be case sensitive or not? [y]es/[n]o: " case_sensitivity

if [ "$case_sensitivity" = "y" ]; then
    occurencies=$(grep "$target_word" "$target_file")
    count=$(grep -c "$target_word" "$target_file")
    echo "The word was found " $count " times"
    echo "It occured it the following scenarios"
    echo $occurencies 
else    
    occurencies=$(grep -i "$target_word" "$target_file")
    count=$(grep -ic "$target_word" "$target_file")
    echo "The word was found " $count " times"
    echo "It occured it the following scenarios"
    echo $occurencies
fi
