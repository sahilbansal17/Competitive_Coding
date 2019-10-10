#Solution for Grading Students on HackerRank
#Link: https://www.hackerrank.com/challenges/grading/problem
#Submitted by @joshbouzy on instagram :)

def gradingStudents(grades):
    newGrades = []
    nextNum = 0

    for g in grades:
        if g >= 38:
            nextNum = g
            while (nextNum % 5) != 0:
                nextNum = nextNum + 1
            if (nextNum - g) < 3:
                newGrades.append(nextNum)
            else:
                newGrades.append(g)
        else:
            newGrades.append(g)
  
    return newGrades