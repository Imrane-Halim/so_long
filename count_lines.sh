#!/bin/bash

total=0
# Use a for loop to iterate over the files
for FILE in $(find . -type f -name "*.c"); do
    # Use wc -l to count lines
    count=$(wc -l < "$FILE")
    echo "$FILE has $count lines"
    total=$((total + count)) # Update total
done
echo "TOTAL LINES COUNTED: $total"