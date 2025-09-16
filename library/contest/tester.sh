#!/bin/bash

# Ensure correct usage
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <input_generator.cpp> <programA.cpp> <programB.cpp>"
    exit 1
fi

GENERATOR=$1
PROG_A=$2
PROG_B=$3

# Derive binary names
GEN_BIN="gen_input"
BIN_A="prog_a"
BIN_B="prog_b"

# Compile all files
g++ "$GENERATOR" -o "$GEN_BIN" -fsanitize=undefined || { echo "Failed to compile $GENERATOR"; exit 1; }
g++ "$PROG_A" -o "$BIN_A" -fsanitize=undefined || { echo "Failed to compile $PROG_A"; exit 1; }
g++ "$PROG_B" -o "$BIN_B" -fsanitize=undefined || { echo "Failed to compile $PROG_B"; exit 1; }

echo "Compiled successfully. Running tests..."

i=1
while true; do
    echo "Test #$i"

    ./"$GEN_BIN" > input.txt || { echo "Failed to generate input"; exit 1; }

    ./"$BIN_A" < input.txt > output_a.txt
    ./"$BIN_B" < input.txt > output_b.txt

    if ! diff -q output_a.txt output_b.txt > /dev/null; then
        echo "Outputs differ at test #$i!"
        echo "Input:"
        cat input.txt
        echo "Output A:"
        cat output_a.txt
        echo "Output B:"
        cat output_b.txt
        break
    fi

    ((i++))
done