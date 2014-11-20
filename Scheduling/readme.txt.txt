Scheduling
===============

Question:
---------
A professional receives multiple service requests in a day, but not all of them can be fulfilled due to time conflicts.

You are given a list of service requests. Each of them is defined by two timestamps representing the start time and the completion time.
Your task is to write a function that prints to the standard output (stdout) the maximum number of service requests the professional can fulfill in one day without overlapping

Note that your function will receive the following arguments:
req_start
array of integer numbers representing the timestamp when each service must begin
req_end
array of integer numbers representing the corresponding timestamp when each service must be completed

e.g. service i must begin at req_start[i] and finish at req_end[i]

Data constraints
the number of requests will not exceed 50,001


Example 
-----------
input:
req_start:[4,1,5,6]
req_end:[5,4,7,8]

output:
3

times are (4,5),(1,4),(5,7),(6,8)

Solution:
------------
The complexity of my solution is O(nlogn) cause I do sorting. 

Make a map for request start and end.(Note some requests are like the same endtime but different starttime)
and sort endTime.

Suppose max_req[] the array of max request and max_req[i] means the max num of request which endTime is i
so max_req[i] = max(currentMax, using the starttime of i to find last endTime);

For example

......................4   10.........
                 1   2      
it's the time axis. max_req[10] = max(currentMax, max_req[2]+1)