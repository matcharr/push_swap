#!/bin/sh

echo "Testing just ra on 3 1 2:"
printf "ra\n" | ./checker 3 1 2

echo "\nTesting just ra on 2 3 1:"
printf "ra\n" | ./checker 2 3 1

echo "\nTesting just ra on 1 2 3:"
printf "ra\n" | ./checker 1 2 3