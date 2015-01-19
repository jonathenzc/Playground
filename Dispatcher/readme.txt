Dispatcher
===============

Question:
---------
Uber needs to connect the rider with their closest available car.
Given the city map, the positions of available cars (identified by numeric IDs) and the position of a customer
Expected complexity

Your task is to
write a function that prints to the standard output (stdout) the ID of the closest possible car to the customer if there are multiple cars at the same minimum distance print the one with the smallest ID
Note that your function will receive the following arguments:
*city_map
	which is an array of strings representing roads
	each road is represented as the two intersection IDs it connects and the length of the road, separated by commas (e.g. ¡°3,4,12¡± - the road connects intersection 3 and 4 and has length 12)
	all roads are bidirectional

*cars
which is an array of integer numbers representing the intersection IDs where each available car is positioned
the ID of the car is given by the position it appears in the array

*customer
which is an integer number representing the intersection ID where the customer is waiting
---------

Example 
-----------
input:
city_map: ["1,2,1", "2,3,2", "1,3,1", "3,4,1"]
cars: [2,1]
customer: 4

output:
2

Explanation:
The car positioned at intersection 1 is the closest to the customer. It's ID is 2 because it is the second one from the cars array.

Solution:
------------
This question is kind of single source shortest path. To be abstract, customer is the source node, city_map is a directional graph. Get the shortest path from customer node to other nodes and go through the array cars to find the closet car.

My shortest path algorithm is BellmanFord and struct edge to store the whole graph so the complexity is O(eloge).
