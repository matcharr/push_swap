#!/bin/sh

echo "Initial stack: 3 1 2"

# Test single operations
echo "Testing single operations:"
echo "After sa: should swap first two elements (should be 1 3 2)"
printf "sa\n" | ./checker 3 1 2
echo "After ra: should rotate stack up (should be 1 2 3)"
printf "ra\n" | ./checker 3 1 2
echo "After rra: should rotate stack down (should be 2 3 1)"
printf "rra\n" | ./checker 3 1 2

# Test with a different stack
echo "\nTesting with a different stack: 2 1 3"
echo "After sa: should swap first two elements (should be 1 2 3)"
printf "sa\n" | ./checker 2 1 3
echo "After ra: should rotate stack up (should be 1 3 2)"
printf "ra\n" | ./checker 2 1 3
echo "After rra: should rotate stack down (should be 3 2 1)"
printf "rra\n" | ./checker 2 1 3

# Test combinations
echo "\nTesting combinations:"
echo "sa then ra on 3 1 2 (should be 1 2 3)"
printf "sa\nra\n" | ./checker 3 1 2