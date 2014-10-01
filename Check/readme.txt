Check
===============

Question:
---------
Write a program that reads a chess table and reports which player, if any, is in check.

Input notes:
The input is a string of 64 symbols representing the chess table (first 8 symbols represent the first line of the chess table, the next 8 the second line and so on)
The symbols are as follows: P = pawn, R = rook, N = knight, B = bishop, Q = queen, K = king, . = empty
Uppercase symbols represent White's pieces, lowercase symbols Black's
The top of the board represents Black's starting position
It is guaranteed that there is exactly one king for each side, and that at most one player is in check
There are no other guarantees as to the number of pieces, i.e. a table can have more than 2 queens, 4 rooks etc.

Output notes:
Please print:
White if the white player is in check
Black if the black player is in check
None if none of the players are in check

Example 
-----------
Example input:
rnbqk.nr
pppp.ppp
........
..b.p..Q
..B.P...
........
PPPP.PPP
RNB.K.NR    
Example output:
None


Example input:
..k.b...
ppp.....
........
r....B..
........
......P.
.....P.P
.....RK.
Example output:
Black


Example input:
..r.....
....k...
....p...
..p.....
........
........
.....nPP
..B...RK
Example output:
White

Solution:
------------
At the beginning I planned to check for pawn, rook, bishop, knight, queen but it will check the same position repeatedly. Then I implemented it by checking row, column, oblique line, knight line.
