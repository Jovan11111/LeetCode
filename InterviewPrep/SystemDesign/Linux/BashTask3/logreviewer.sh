#! /bin/bash

read -p "Enter a log file you want to analyze: " target_file

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

error_count=$(grep -c "ERROR" "$target_file")
debug_count=$(grep -c "DEBUG" "$target_file")
info_count=$(grep -c "INFO" "$target_file")
if [ "$error_count" -lt 10 ]; then
    error_ident_l="        "
    error_ident_r="         "
elif [ "$error_count" -lt 100 ]; then
    error_ident_l="        "
    error_ident_r="        "
else
    error_ident_l="        "
    error_ident_r="       "
fi

if [ "$debug_count" -lt 10 ]; then
    debug_ident_l="        "
    debug_ident_r="         "
elif [ "$debug_count" -lt 100 ]; then
    debug_ident_l="        "
    debug_ident_r="        "
else
    debug_ident_l="        "
    debug_ident_r="       "
fi

if [ "$info_count" -lt 10 ]; then
    info_ident_l="        "
    info_ident_r="         "
elif [ "$info_count" -lt 100 ]; then
    info_ident_l="        "
    info_ident_r="        "
else
    info_ident_l="        "
    info_ident_r="       "
fi

echo "-------------------------------|"
echo "|         LOG REVIEW           |"
echo "-------------------------------|"
echo "|   ERROR   |$error_ident_l$error_count$error_ident_r|"
echo "|   DEBUG   |$debug_ident_l$debug_count$debug_ident_r|"
echo "|   INFO    |$info_ident_l$info_count$info_ident_r|"
