#Solution for CamelCase on HackerRank
#Link: https://www.hackerrank.com/challenges/camelcase/problem
#Submitted by @joshbouzy on instagram :)

def camelcase(s):
    count = 0
    for l in s:
        if l.isupper() == True:
           count+=1
    return count + 1