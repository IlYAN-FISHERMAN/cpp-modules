#!/bin/bash

echo "Test 1: 42"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"  
echo

echo "Test 2: 42"
./RPN "7 7 * 7 -"  
echo

echo "Test 3: 0"
./RPN "1 2 * 2 / 2 * 2 4 - +"  
echo

echo "Test 4: 2"
./RPN "1 1 +"  
echo

echo "Test 5: Error"
./RPN "(1 + 1)"  
echo

echo "Test 6: Error"
./RPN "3 0 /"  
echo

echo "Test 7: Error"
./RPN "2 +"  
echo

echo "Test 8: 23"
./RPN "3 4 5 * +"  
echo

echo "Test 9: 27"
./RPN "3 4 5 + *"  
echo

echo "Test 10: 5"
./RPN "5"  
echo

echo "Test 11: 14"
./RPN "5 1 2 + 4 * + 3 -"  
echo

echo "Test 12: 33"
./RPN "9 2 + 3 *"  
echo

echo "Test 13: 4"
./RPN "5 3 - 2 *"  
echo

echo "Test 14: 10"
./RPN "2 3 * 4 +"  
echo

echo "Test 15: 77"
./RPN "3 4 + 5 6 + *"  
echo

echo "Test 16: Error"
./RPN ""  
echo

echo "Test 17: Error"
./RPN "3 4 $ 5"  
echo

echo "Test 18: Error"
./RPN "5 6 7 8 9 10 + + + + +"  
echo
