# take no of statements as input 
n = int(input())

# value of x initially
x = 0

# take statements as input and process them 
for i in range(n):
    command = input()
    # print(command)
    
    # if 2nd character of string is +, then x is to be incremented
    # otherwise x is to be decremented 
    if(command[1] == '+'):
        x += 1
    else:
        x -= 1

# print the value of x
print(x)        