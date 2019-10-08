#Closest pair of points in an Euclidean Plane.
#! ^ represents exponentiation.
#Consider an euclidean plane which contains N points given by their coordinates.
#The euclidean distance between 2 points A(x1, y1) and B(x2, y2) is equal to sqrt((x1-x2)^2 + (y1-y2)^2) and shall be expressed as d(A, B) from now on.
#We have to determine the distance between distance between the 2 closest points.
#One straightforward solution is to consider every pair of points A and B and calculate d(A, B) for every one of them.
#However, this approach has an O(n^2) time complexity.
#An efficient solution follows the divide & conquer paradigm and has an O(n*log2(n)) time complexity.
#Let P be a subset of the given points. If |P| (cardinal of P) < 4, we will consider all |P|/2 pairs and remember the minimum.
#If |P| >= 4, we will use a divide & conquer approach as it follows:
#    1. divide: determine a vertical line, let's call it a, which "cuts" the subset in 2 smaller ones, let's say PL (left) and PR (right), as close in size as possible.
#    2. conquer: 2 recursive calls to determine the closest pair of points in PL and PR.
#    3. combine: let's assume that D = min distance between 2 points. D is either determined by one of the 2 recursive calls, or is satisfied by a point in PL and one in PR [1].
#       We can observe that if we have a possible D from the recursive calls, we can find [1] if the distance between every point and line a is < D, so the 2 points shall be contained in a region of length 2*D.
#       In order to determine if 2 points which satisfy [1] exist, we can do the following:
#            - build another array, let's call it Q, ordered by the y coordinate.
#            - for each point q in Q we try to find points k in Q such as d(q, k) < D and return the one for which d(q, k) is minimum.
#Below, you will find a very simple implementation in Python.
#You can find the C++ implementation (which is a bit faster) of the same algorithm here: https://github.com/sahilbansal17/Competitive_Coding/blob/master/Algorithms/Divide-and-Conquer/closest_pair_of_points.cpp
#For precision, in the implementation below I chose to work with the squares of the distances.
#Test data:
#N = 10
#Points: X Y
#26 77
#12 37
#14 18
#19 96
#71 95
#91 9
#98 43
#66 77
#2 75
#94 91
#expected result: 18.681542

import math

def brute(p, c=float("inf")):
    if len(p) < 2: return c
    else:
        f = p[0]
        del p[0]
        return brute(p, min([c, min([dist(f, x) for x in p])]))

def divide(p):
    mid = len(p)//2;
    minimum = min([brute(p[:mid]), brute(p[mid:])]) # determines
    near_mid = list(filter(lambda point: point.x > p[mid].x - minimum and point.x < p[mid].x + minimum, p))
    return min([brute(near_mid), minimum])

class point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def sqr(x):
    return x*x

def dist(a, b):
    return sqr(a.x - b.x) + sqr(a.y - b.y)

N = int(input("Give the number of points (N): "))
p = []

for i in range(N):
    x, y = [int(x) for x in input("x y: ").split()]
    p.append(point(x, y))

P = sorted(p, key=lambda point: point.x)

print("%.6f" % math.sqrt(divide(P)))
