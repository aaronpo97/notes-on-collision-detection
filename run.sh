#!/bin/bash

# Check if a filename is provided as an argument
if [ $# -eq 0 ]; then
    echo "Please provide a filename as an argument."
    exit 1
fi

filename=$1

# declare a variable to keep track of the number of times the file has been checked
count=0

# Add a while loop to continuously check if the file exists
while [[ ! -f "$filename" && $count -lt 2 ]]; do
    # Increment the count
    count=$((count + 1))
    make
    # Add a sleep command to wait for 5 seconds before checking again
    sleep 4
done

# Check if the file exists before trying to open it
if [ -f "$filename" ]; then
    # Open the file depending on the operating system
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        xdg-open "$filename"
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        open "$filename"
    elif [[ "$OSTYPE" == "cygwin" ]]; then
        cygstart "$filename"
    elif [[ "$OSTYPE" == "msys" ]]; then
        start "$filename"
    else
        echo "Cannot determine how to open the file on this OS."
    fi
else
    echo "File not found after checking twice."
fi
