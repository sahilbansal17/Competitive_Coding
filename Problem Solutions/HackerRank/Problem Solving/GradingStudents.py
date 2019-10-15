# Solution for Grading Students Problem in Problem Solving Section
# Link to the problem: https://www.hackerrank.com/challenges/grading/problem

n = int(input())
for i in range(n):
    num = int(input())
    first = int(num/10)
    second = num%10
    if(second == 0):
        checkNum = first*10
    elif(second > 5):
        checkNum = first*10 + 10
    else:
        checkNum = first*10 + 5
    if(num < 38):
        print(num)
    elif(checkNum - num < 3):
        print(checkNum)
    else:
        print(num)
