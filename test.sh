#!/bin/bash

# Test script for push_swap

# Compile the programs
make

# Test with invalid input
echo "Testing with invalid input:"
./push_swap 1 2 a 4
echo "Expected: Error"

# Test with duplicates
echo "Testing with duplicates:"
./push_swap 1 2 2 4
echo "Expected: Error"

# Test with already sorted input
echo "Testing with already sorted input:"
./push_swap 1 2 3 4 5
echo "Expected: (no output)"

# Test with small input
echo "Testing with small input (3 numbers):"
./push_swap 3 1 2
echo "Expected: Some operations"

# Test with checker
echo "Testing with checker:"
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
echo "Expected: OK"

# Test with random large input
echo "Testing with random large input:"
ARG=$(seq 1 100 | sort -R | tr '\n' ' ')
NUM_OPS=$(./push_swap $ARG | wc -l)
echo "Number of operations: $NUM_OPS"
echo "Expected: Less than 700 operations"

# Test with checker and random large input
echo "Testing with checker and random large input:"
./push_swap $ARG | ./checker $ARG
echo "Expected: OK"

echo "All tests completed!"