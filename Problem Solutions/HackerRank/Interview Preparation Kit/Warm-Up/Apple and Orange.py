#Solution for Apple and Orange on HackerRank
#Link: https://www.hackerrank.com/challenges/apple-and-orange/problem
#Submitted by @joshbouzy on instagram :)

def countApplesAndOranges(s, t, a, b, apples, oranges):
    leftBoundary = s
    rightBoundary = t
    appleTree = a
    orangeTree = b
    appleArray = []
    orangeArray = []
    applesInRange = 0
    orangesInRange = 0

    for x in apples:
        x = x + appleTree
        appleArray.append(x)

    for y in oranges:
        y = y + orangeTree
        orangeArray.append(y)

    for p in appleArray:
        if leftBoundary <= p <= rightBoundary:
            applesInRange+=1

    for r in orangeArray:
        if leftBoundary <= r <= rightBoundary:
            orangesInRange+=1

    print(applesInRange)
    print(orangesInRange)
