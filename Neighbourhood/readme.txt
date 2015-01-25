Neighbourhood
===============

Question:
---------
Uber needs to connect a rider with a car as fast as possible. To achieve that, the system needs to accurately predict demand to make sure you get a car when you want one. Predicting demands requires knowledge about the locations from which most orders are likely to occur.

Given a neighbourhood represented as the coordinates of a convex polygon and a list of trip destinations

Your task is to
-----------
write a function that prints to the standard output (stdout) the number of trips that ended in the given neighbourhood
Note that your function will receive the following arguments:

neighbourhood
which is an array of strings representing the coordinates of the polygon
the convex polygon coordinates are presented in clockwise order
each string contains the x,y coordinates of one vertex, separated by comma

trips
which is an array of strings representing the coordinates of the trips destinations
each string contains the x,y coordinates of one destination, separated by comma

Example 
-----------
input:
neighbourhood: ["1,3","4,5","3,1"]
trips: ["1,1","2,3","3,3","4,2"]

output:
2

The only trips that ended in the neighbourhood are (2,3) and (3,3).



Solution:
------------
To be abstract this question is to count how many points are in the convex polygon. To each point I need to judge whether it is in the convex polygon. 

There are many ways to judge whether a point is in the convex polygon. 

My solution is to build a vector set which is the point to be judged to other points in the convex polygon and with this vector set I calculate their angles to see if the sum of those angles equals to 2Pi( 360 )