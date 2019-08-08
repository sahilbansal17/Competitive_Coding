#Name: Dinithi Wickramaratne

#balanced paranthesis problem
#this program checks whether the paranthesis in a provided string are balanced

#implementation of the stack
class Stack():

    def __init__(self):
        self.items = []

    #checks whether the stack is empty
    def isEmpty(self):
        return len(self.items)==0

    #add an element to the stack
    def push(self, item):
        self.items.append(item)

    #remove the element on the top of the stack and returns it
    def pop(self):
        return self.items.pop()

def checkParanthesis():
    
    stack = Stack()

    #list of opening and closing brackets
    opening_brackets = ['{', '(', '[']
    closing_brackets = ['}', ')', ']']

    input_string = input("Enter the input string")

    #check for every character in input_string
    for i in input_string:
        
        #if an opening bracket is found push to the stack
        if(i in opening_brackets):
            stack.push(i)
            
        #if a closing bracket is found
        elif(i in closing_brackets):
            
            #if the stack is empty, then there are no matching parathesis
            if(stack.isEmpty()):
                return False 
            else:
                #checking whether the correct pair of paranthesis are matched
                if opening_brackets.index(stack.pop()) != closing_brackets.index(i):
                    return False

    #if stack is empty then the paranthesis are balanced
    if(stack.isEmpty()):
        return True
    else:
        return False

print(checkParanthesis())
           



    
    
