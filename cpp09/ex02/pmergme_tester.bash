#!/bin/bash

# Check if PmergeMe exists and is executable
if ! [ -x "./PmergeMe" ]; then
    echo "Error: ./PmergeMe does not exist or is not executable."
    exit 1
fi

# Simple test function that generates a sequence of numbers and runs the PmergeMe program

# Test 1: Ordered list (0 to 15)
./PmergeMe "0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15" | grep Time && echo ""


# Test 2: Reversed ordered list (15 to 0)
./PmergeMe "15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0" | grep Time && echo ""


# Test 3: Randomly generated list of 16 numbers
./PmergeMe "$(jot -r 3000 1 100000 | tr '\n' ' ')" | grep Time && echo ""


# Test 4: List with some duplicates
./PmergeMe "3 3 1 1 0 0 5 5 4 4 2 2" | grep Time && echo ""


# Test 5: List of 50 numbers in random order
./PmergeMe "$(jot -r 3000 1 100000 | tr '\n' ' ')" | grep Time && echo ""


# Test 6: List with a larger range (0 to 100)
./PmergeMe "$(jot -r 3000 1 100000 | tr '\n' ' ')" | grep Time && echo ""


# Test 7: All numbers being the same
./PmergeMe "7 7 7 7 7 7 7 7 7 7" | grep Time && echo ""


# Test 8: Ordered list with a larger range (0 to 50)
./PmergeMe "0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50" | grep Time && echo ""


# Test 9: List of 10 numbers in random order
./PmergeMe "$(jot -r 3000 1 100000 | tr '\n' ' ')" | grep Time && echo ""


# Test 10: Very large range (0 to 1000) with random values
./PmergeMe "$(jot -r 3000 1 100000 | tr '\n' ' ')" | grep Time && echo ""


# Test 11: List with incremental values (1, 2, 3, ..., 100)
./PmergeMe "$(jot -r 3000 1 100000 | tr '\n' ' ')" | grep Time && echo ""



# Test 13: List with large number of elements (200 elements from 0 to 199)
./PmergeMe "$(jot -r 3000 1 100000 | tr '\n' ' ')" | grep Time && echo ""


# Test 14: List with 10 identical large numbers
./PmergeMe "1000 1000 1000 1000 1000 1000 1000 1000 1000 1000" | grep Time && echo ""


# Test 15: List with descending powers of 2
./PmergeMe "1024 512 256 128 64 32 16 8 4 2 1" | grep Time && echo ""


# Test 16: List with ascending powers of 2
./PmergeMe "1 2 4 8 16 32 64 128 256 512 1024" | grep Time && echo ""


# Test 17: List with large random values (negative and positive)
./PmergeMe "$(jot -r 3000 1 100000 | tr '\n' ' ')" | grep Time && echo ""


# Test 18: List of prime numbers up to 100
./PmergeMe "2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97" | grep Time && echo ""


# Test 19: List with 5 elements that are reverse sorted (5 4 3 2 1)
./PmergeMe "5 4 3 2 1" | grep Time && echo ""


# Test 20: List of 1000 elements in random order with numbers 0-999
./PmergeMe "$(jot -r 3000 1 100000 | tr '\n' ' ')" | grep Time && echo ""


# Test 21: Very large list (up to 2000 elements)
./PmergeMe "$(jot -r 3000 1 100000 | tr '\n' ' ')" | grep Time && echo ""


# Test 22: Random list of 100 elements between 0 and 100
./PmergeMe "$(jot -r 3000 1 100000 | tr '\n' ' ')" | grep Time && echo ""

