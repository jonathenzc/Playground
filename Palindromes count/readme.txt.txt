Palindromes count
===============

Question:
---------
Given a string, your task is to print to the standard output (stdout) the total number of palindromic sequences.

Expected complexity
---------
O(N)

Example 
-----------
input:
s: abaaac
output:
10

Solution:
------------
I didn't come out with the complexity O(N) but O(N^2)

I used dynamic programming.

bool isPalindrome[i][j]: substring from i to j is palindrome

So isPalindrome[i][j]=true if s[i] is equal to s[j] and isPalindrome[i+1][j-1] = true;

Here is the trick one. You can't just using i and j travel through the array 

Because eg. 0990 is palindrome until 99 is palindrome but 0990 is visited before 99.

So I use a variable called subLen for travelling through.
