Skyscrapers
===============

Question:
---------
The Wall Street in New York is known for its breathtaking skyscrapers. But the raining season is approaching, and the amount of water that will fall over the buildings is going to be huge this year. Since every building is stuck to the buildings to its left and to its right (except for the first and the last one), the water can leak from a building only if the height of the building is higher than the height of the building to its left or to its right (the height of the edges of Wall Street is 0). All the buildings have the width of 1 meter.
You are given the heights (in meters) of the buildings on Wall Street from left to right, and your task is to print to the standard output (stdout) the total amount of water (in cubic meters) held over the buildings on Wall Street.

complexity
---------
O(N)

Example 
-----------
input:
heights: 9 8 7 8 9 5 6
output:
5

Solution:
------------
Using an array Left to represent the biggest height on the left side of the buildings and an array Right to the right side.

Here is a dynamic programming function£º
left[i] = max(left[i-1],heights[i-1])
right[i] = max(right[i+1],heights[i+1])

The volume of water a building can hold is min(left[i],right[i]) - height[i].