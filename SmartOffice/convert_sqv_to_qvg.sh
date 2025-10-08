#!/bin/bash

# Path to the svg2qvg executable
SVG2QVG="../../qskinny/build/bin/svg2qvg"  # Adjust this if svg2qvg is located elsewhere

# Input directory containling SVG files
INPUT_DIR="./assets/svg"   # Change to your actual SVG folder

# Output directory for QVG files
OUTPUT_DIR="./assets/qvg"

# Create output directory if it doesn't exist
mkdir -p "$OUTPUT_DIR"

# Loop through all SVG files in the input directory
for svg_file in "$INPUT_DIR"/*.svg; do
    # Get the base filename without extension
    base_name=$(basename "$svg_file" .svg)

    # Define output file path
    qvg_file="$OUTPUT_DIR/$base_name.qvg"

    echo "Converting $svg_file → $qvg_file"
    "$SVG2QVG" "$svg_file" "$qvg_file"

    # Check if conversion succeeded
    if [ $? -eq 0 ]; then
        echo "Success: $qvg_file created"
    else
        echo "Failed: $svg_file"
    fi
done

echo "Conversion complete!"
