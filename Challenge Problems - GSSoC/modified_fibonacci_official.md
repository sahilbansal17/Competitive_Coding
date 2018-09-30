PROBLEM:NTH FIBONACCI NUMBER

The Fibonacci numbers are the numbers in the following integer sequence

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 141, …

In mathematical terms, the sequence F(n) of Fibonacci numbers is defined by the recurrence relation

F(n) = F(n – 1) + F(n – 2)

where F(0) = 0 and F(1) = 1.

Now the problem is to find the Nth Fibonacci Numbers where N can be very Large.

Solution:

This article is little bit lengthy but hopefully you will read till last line. Be patient, every second spent will be worth it.

So, here we go…..

There are 2 or 3 ways to solve the given problem which are

1) Using recursion.

2) Using dynamic programming (O(n) complexity and O(1) space as only last 2 terms needs to be stored)

3) Fast matrix exponentiation.

So, let’s discuss the 3rd one.

Matrix Exponentiation is a useful tool in solving not just the questions related to Fibonacci numbers but other linear recurrence equations too.

The equation: f(n) = af(n-1) + bf(n-2) can be disguised and thrown at you in numerous ways.

I’m going to use a familiar problem to show you how.

SAMPLE PROBLEM

We have the following types of rectangles with us: 1. size 1 X 1 2. size 2 X 1

In how many ways can we form a rectangle of size N X 1 by putting the mentioned types of rectangles side by side.

To form rectangle of size 1 X 1 there is only one way. That is to use one rectangle of size 1 X 1.

To form rectangle of size 2 X 1 there are two ways: the first is to use a 2 X 1 rectangle directly and the second way is to put two 1 X 1 rectangles side by side.

To form rectangle of size 3 X 1 there are 3 ways. For 4 X 1, there are 5 ways..

Lets analyze this problem in a recursive manner:

Let f(n) be the number of ways to form an N X 1 rectangle.

An N X 1 rectangle can be formed either by adding a 1 X 1 rectangle to the end of an (N-1) X 1 rectangle

OR

by adding a 2 X 1 rectangle to the end of an (N-2) X 1 rectangle

Therefore, the number of ways to form N X 1 rectangle = (number of ways to form (N-1) X 1 rectangle) + (number of ways to form (N-2) X 1 rectangle)

f(n) = f(n-1) + f(n-2) ; with f(0)=1 and f(1)=1

Its the Fibonacci series!!

( f(0)=1 because there is 1 way to form a 0 X 1 rectangle: do not use any rectangle )

Let’s look at a variation.

SAMPLE PROBLEM:

We have the following types of rectangles with us:

size 1 X 1 of two different types: red- and blue-colored
size 2 X 1
In how many ways can we form a rectangle of size N X 1 by putting the mentioned types of rectangles side by side.

An N X 1 rectangle can be formed either by adding a 2 X 1 rectangle to the end of an (N-2) X 1 rectangle

OR

by adding a blue 1 X 1 rectangle to the end of an (N-1) X 1 rectangle

OR

by adding a red 1 X 1 rectangle to the end of an (N-1) X 1 rectangle

So, there are two ways to obtain N X 1 rectangle from an (N-1) X 1 rectangle, and only one way to get it from an (N-2) X 1 rectangle.

The equation becomes f(n) = 2f(n-1) + 1f(n-2) ; with f(0)=1 and f(1)=2

In general, if we have 1 X 1 rectangles of X different colors and 2 X 1 rectangles of Y different colors, we can make an N X 1 rectangle in f(n) ways, f(n) = Xf(n-1) + Yf(n-2); with f(0)=1 and f(1)=X

We can add another twist…

SAMPLE PROBLEM:

We have the following types of rectangles with us:

size 1 X 1 of X different colors

size 2 X 1 of Y different colors

size 3 X 1 of Z different colors

In how many ways can we form a rectangle of size N X 1 by putting the mentioned types of rectangles side by side.

In this case the number of ways to construct an N X 1 rectangle = f(n) = X * f(n-1) + Y * f(n-2) + Z * f(n-3) ; with f(0)=1, f(1)=X,f(2)=X+Y

All of the above variations can be solved using Matrix Exponentiation. We just need to find the exponentiation matrix carefully.

SO THESE WERE THE EXAMPLES ON WHICH MATRIX EXPONENTIATION CAN BE APPLIED .

NOW LETS SEE HOW MATRIX EXPONENIATION WORKS…..

Let’s first understand what a recurrence relation is. You probably know about the Fibonacci Series. It is a sequence of numbers in which the first number is 0, the second number is 1 and all subsequent numbers are determined using the formula:

f(n) = f(n-1) + f(n-2)

An equation such as the one above, in which one term of a sequence is defined using the previous terms, is called a Recurrence relation. Therefore, relations like f(n)=f(n-3) + f(n-2) + f(n-1) [ Tribonacci Series ]

or

f(n)=3f(n-1) + 7f(n-2) [ an arbitrary example ] etc. are recurrence relations.

Matrix exponentiation is a faster method that can be used to find the nth element of a series defined by a recurrence relation.

We’ll take Fibonacci series as an example.(from here the actual solution starts)

In matrix exponentiation, we first convert the addition in a recurrence relation to multiplication. The advantage of doing this will become clear as you read on.

So the question is: How can we convert the addition in a recurrence relation to multiplication. The answer is matrices!

The general recurrence relation for a series in which a term depends on the previous 2 terms is:

f(n) = af(n-1) + bf(n-2)

( For Fibonacci, a=1 and b=1 )

The matrix form of this equation is:

| f(n) | = | p q | X | f(n-1) |

| f(n-1) | | r s | | f(n-2) |

For convenience let

| p q | = Z

| r s |

Therefore, we get

f(n) = p * f(n-1) + q * f(n-2)

and

f(n-1) = r * f(n-1) + s * f(n-2)

For each recurrence relation, the values of p,q,r and s will be different.

On solving the above equations for the Fibonacci sequence we get, p=1, q=1, r=1 and s=0.

So, the Z matrix for Fibonacci sequence is

| 1 1 |

| 1 0 |

and the matrix form for f(n) = f(n-1) + f(n-2) is:

| f(n) | = | 1 1 | X | f(n-1) |

| f(n-1) | | 1 0 | | f(n-2) |

So ,general formula for generating the Z matrix of f(n)=a1f(n-1)+a2f(n-2)+a3f(n-3)+a4f(n-4)………+ak*f(n-k) is

|a1 a2 a3 . . ak|

|1 0 0 0 0 0|

|0 1 0 0 0 0|

|0 0 1 0 0 0|

|. . . . . . |

|0 0 0 0 1 0|

Now let’s get to the method for finding the nth element.

Initially we have the matrix,

| f(2) |

| f(1) |

Using the matrix form of Fibonacci series given above, if we have to find the next Fibonacci number, i.e. f(3), we will multiply Z matrix by the above matrix:

| 1 1 | X | f(2) | = | f(3) |

| 1 0 | | f(1) | | f(2) |

If we again multiply Z with

| f(3) | ,we’ll get | f(4) |

| f(2) | | f(3) |

So, we have the following equation for the nth Fibonacci number.

| f(n) | = Z^(n-2) X | f(2) |

| f(n-1) | | f(1) |

So, we have successfully changed the addition in the recurrence equation to multiplication. But now what??

We have an algorithm called Binary Exponentiation that can perform the operation base^power in O(log n) time.

Because now our job is to find Z^(n-2), we can do this by using Binary Exponentiation in O(log n) time.

Z^(n-2) will then be multiplied by

| f(2) | and we’ll get | f(n) |

| f(1) | | f(n-1) |

For the recurrence relation: f(n) = f(n-1) + 2f(n-2) + 3f(n-3), we have

| f(n) | | p q r | | f(n-1) |

| f(n-1) | = | s t u | X | f(n-2) |

| f(n-2) | | v w x | | f(n-3) |

Write out the equations for f(n), f(n-1) and f(n-2) from the above matrix equation and you’ll find that the Z matrix is:

| 1 2 3 |

| 1 0 0 |

| 0 1 0 |

