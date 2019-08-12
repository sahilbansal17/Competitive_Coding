#Name: Dinithi Wickramaratne

#this program returns the final result of a prefix expression

#implementation of the stack
class Stack():

    def __init__(self):
        self.items = []

    #checks whether the stack is empty
    def isEmpty(self):
        return len(self.items) == 0

    #add an element to the stack
    def push(self,item):
        self.items.append(item)

    #removes the element on the top of the stack and returns it
    def pop(self):
        return self.items.pop()

#this function evaluates the prefix expression
#time complexity: O(n)
def evaluatePrefix(str):

    stack = Stack()
    #list of operators
    operators = ['+','-','*','/']

    #check for every character in the given string
    #since this is a prefix expression, start pushing elements to the stack from the end of the string
    #i is the index of the character that is currently considered
    for i in range(len(str)-1,-1,-1):
        #check whether the character is an operand
        if str[i] not in operators:
            #push character to stack if it's an operand
            stack.push(str[i])
        #the character read is an operator
        else:
            #get the two values at the top of the stack
            operand1 = int(stack.pop())
            operand2 = int(stack.pop())
            #check what the operation to be applied is and apply it to the operands
            if str[i] is '+':
                stack.push(operand1 + operand2)
            elif str[i] is '-':
                stack.push(operand1 - operand2)
            elif str[i] is '/':
                stack.push(operand1 / operand2)
            elif str[i] is '*':
                stack.push(operand1 * operand2)
    #finally return the value left on the stack       
    return stack.pop()

#number of test cases
test_cases = int(input("Enter the number of test cases: "))
while(test_cases>0):
    prefix_string = input("Enter the prefix string: ") 
    print("Result is "+ str(evaluatePrefix(prefix_string)))
    test_cases-=1

