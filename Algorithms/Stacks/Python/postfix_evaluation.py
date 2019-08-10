#Name: Dinithi Wickramaratne

#this program evaluates a postfix expression
#returns the final result of 

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

#this function evaluates the postfix expression
def evaluatePostfix(str):

    stack = Stack()
    #list of operators
    operators = ['+','-','*','/']

    #check for every character in the given string
    for i in str:
        #check whether the character is an operand
        if i not in operators:
            #push character to stack if it's an operand
            stack.push(i)
        #the character read is an operator
        else:
            #get the two values at the top of the stack
            operand1 = int(stack.pop())
            operand2 = int(stack.pop())
            #check what the operation to be applied is and apply it to the operands
            if i is '+':
                stack.push(operand2 + operand1)
            elif i is '-':
                stack.push(operand2 - operand1)
            elif i is '/':
                stack.push(operand2 / operand1)
            elif i is '*':
                stack.push(operand2 * operand1)
    #finally return the value left on the stack       
    return stack.pop()

#number of test cases
test_cases = int(input("Enter the number of test cases: "))
while(test_cases>0):
    postfix_string = input("Enter the postfix string: ") 
    print("Result is "+ str(evaluatePostfix(postfix_string)))
    test_cases-=1
