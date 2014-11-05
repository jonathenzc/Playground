Unique Sequence
===============

Question:
---------
Given an array of integer numbers
Your task is to write a function that prints to the standard output the length of the longest sequence of consecutive elements that doesn¡¯t contain any duplicate numbers.
Note that your function will receive the following arguments:
numbers: the array of integer numbers mentioned above

Data constraints
---------
the length of the array will not exceed 10,000

Example 
-----------
input:
numbers:[1,2,3,3,1,2,3,6,9,5,7,7]

output:
7

Solution:
------------
A simple solution is to traverse the array and compare the length of substring with the max when current number is found before. The complexity is O(N^2)

To improve the time efficiency I use a hash(map in C++) to record the index in the form of <number, index>¡£