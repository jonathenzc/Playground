Price Experiment
===============

Question:
---------
Uber is a company based in San Francisco, California that makes a mobile application that connects passengers with drivers of luxury vehicles for hire.
Uber is doing experiments to better understand the relationship between price and demand for rides. One hypothesis is that lower prices will show an increase in demand for cars.
Their goal is to find the cost/demand point that is best for everyone.
Experimental data will show that the relation between the price discount and the uber revenue can be approximated by a mathematical function. Let¡¯s consider the following function:
y = 1/2 (¡Ì(-3x^2 + Ax + B) - x - 1)
where
x represents the discount,
y represents the uber revenue and
A, B are two constant positive integers

Your task is to
-----------
write a function that prints to the standard output (stdout) the discount value x that maximizes uber revenue y
please print the found value x truncated to two decimal places without rounding.
Note that your function will receive the following arguments:
a
the positive integer number A
b
the positive integer number B

Example 
-----------
input:
a:250
b:400

output:
20.04

Solution:
------------
I need to find x value when function y = 1/2 (¡Ì(-3x^2 + Ax + B) - x - 1) is in its minimum. So I use derivation to y and I get y' = 1/2((-6x + A)/2 * ¡Ì(-3x^2 + Ax + B) - 1). Let y' = 0 and get 48x^2 - 16Ax + A^2 - 4 * B = 0  (1).

Finally the two roots of the function(1) is (2A ¡À ¡Ì(A^2 + 12B))/ 12