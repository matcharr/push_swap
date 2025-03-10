#!/bin/sh

echo "Testing different operations on 3 1 2:"
echo "Using sa then ra:"
printf "sa\nra\n" | ./checker 3 1 2

echo "\nUsing ra then sa:"
printf "ra\nsa\n" | ./checker 3 1 2

echo "\nUsing sa then ra then ra:"
printf "sa\nra\nra\n" | ./checker 3 1 2