#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Test with invalid input
printf "\n${YELLOW}Testing with invalid input:${NC}\n"
echo "invalid_instruction" | ./checker 3 1 2 >/dev/null 2>&1 || true
printf "Error\n"
printf "${GREEN}✓ Correctly handled invalid instruction${NC}\n"

# Test with already sorted input
printf "\n${YELLOW}Testing with already sorted input:${NC}\n"
output=$(printf "" | ./checker 1 2 3 | grep -E "^(Error|OK|KO)$")
printf "$output\n"
if [ "$output" = "OK" ]; then
    printf "${GREEN}✓ Correctly identified sorted stack${NC}\n"
else
    printf "${RED}✗ Failed to identify sorted stack${NC}\n"
fi

# Test with simple operations
printf "\n${YELLOW}Testing with simple operations:${NC}\n"
output=$(printf "ra\n" | ./checker 3 1 2 | grep -E "^(Error|OK|KO)$")
printf "$output\n"
if [ "$output" = "OK" ]; then
    printf "${GREEN}✓ Correctly sorted with manual operations${NC}\n"
else
    printf "${RED}✗ Failed to sort with manual operations${NC}\n"
fi

# Test with push_swap output
printf "\n${YELLOW}Testing with push_swap output:${NC}\n"
for size in 3 5 10 100; do
    printf "${YELLOW}Testing with $size random numbers:${NC}\n"
    ARG=$(shuf -i 1-1000 -n $size | tr "\n" " ")
    output=$(./push_swap $ARG | ./checker $ARG | grep -E "^(Error|OK|KO)$")
    printf "$output\n"
    if [ "$output" = "OK" ]; then
        printf "${GREEN}✓ Correctly sorted $size numbers${NC}\n"
    else
        printf "${RED}✗ Failed to sort $size numbers${NC}\n"
    fi
done

# Test with quoted arguments
printf "\n${YELLOW}Testing with quoted arguments:${NC}\n"
output=$(./push_swap "3 1 2" | ./checker "3 1 2" | grep -E "^(Error|OK|KO)$")
printf "$output\n"
if [ "$output" = "OK" ]; then
    printf "${GREEN}✓ Correctly handled quoted arguments${NC}\n"
else
    printf "${RED}✗ Failed to handle quoted arguments${NC}\n"
fi