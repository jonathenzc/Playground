Heads_and_tails
===============

Question:
---------
Given a sequence of heads and tails. How many significant subsequences are in this sequence, where the number of heads are not less than the number of tails?
Your standard output should be the number of subsequences.

Expected complexity
---------
O(N*logN)

Example 
-----------
input:
data: [ 'H', 'T', 'H', 'T', 'T', 'H' ]
output:
11
Explanation:
{H} {H} {H}
{H, T} {T, H} {H, T} {T, H}
{H, T, H} 
{H, T, H, T} 
{H, T, T, H} 
{H, T, H, T, T, H} 


Solution:
------------
Create an array for counting the difference of H and T. For example with the array data above, 1st item is H, so we note 1. 2nd is T, so we note 0(1-1). Finally we get 1 0 1 0 -1 0。

We call this array is A. Our problem turns to check if A[j] - A[i]>=0 which means H in i+1 to j is not less than T.(Note: we need to add 0 to the first place)

But it's hard to calculate how many pair is A[j]>=A[i]. So we can change this problem to count how many pairs in A is qualified to A[j]<A[i] which is called reverse pair.

So finally our problem is turned to count how many pairs are in array A？

We can count reverse pair with the idea of merge sort.

In the process of merge, for example, we have 2 subarray s1 and s2. If s1[i] > s2[j] then the rest of S1 are all reverse pairs.
