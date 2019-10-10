#Solution for Bon Appétit on HackerRank
#Link: https://www.hackerrank.com/challenges/bon-appetit/problem
#Submitted by @joshbouzy on instagram :)

def bonAppetit(bill, k, b):
    actual = (sum(bill) - bill[k])/2
    if actual == b:
        print("Bon Appetit")
    else:
        print(int(b - actual))