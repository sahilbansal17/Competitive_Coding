#Name: Dinithi Wickramaratne

#this program evaluates, the next greater element for every element in a given list of elements
#next greater element of an element x is, the first element that appears to the right of x and is greater than x
#if a next greater element is not found, -1 is printed 

#implementation of the stack
class Stack:

    def __init__(self):
        self.items = []

    #checks whether the stack is empty
    def isEmpty(self):
        return len(self.items)==0

    #add an element to the stack
    def push(self,item):
        self.items.append(item)

    #removes the element on the top of the stack and returns it
    def pop(self):
        return self.items.pop()

    #returns the element at the top of the stack
    def peak(self):
        return self.items[len(self.items)-1]

#this function finds the next greater element for each element of a given list
def findNextGreater(arr):

    #if a list with no elements is given, an error message is shown
    if(len(arr)==0):
        print("Error: List has no elements")
        return
    
    print("The next greatest elements are: ")

    #this stack is used to keep track of the indexes of the elements
    stack_indexes = Stack()

    #the index of the first element, 0 is pushed to  stack_indexes 
    stack_indexes.push(0)

    #this variable is used to store the next greater element temporarily
    next_greater_element = 0

    #check for every element in the list, starting from the element at index 1
    for i in range(1,len(arr)):
        #check if the element at the top of the stack is greater than the current element
        #if true, push the index of the element(i) to the stack
        if arr[i]<arr[stack_indexes.peak()]:
            stack_indexes.push(i)

        #element at the top of the stack is less than the current element
        else:
            #while the stack is not empty and the element at the top of the stack is less than the current element,
            #assign the greater element of the peak as the current element and pop the peak element from the stack
            while(stack_indexes.isEmpty()==False and arr[stack_indexes.peak()]<arr[i]):
                next_greater_element = arr[i]
                stack_indexes_top = stack_indexes.pop()
                print("Index "+str(stack_indexes_top)+" : "+str(arr[stack_indexes_top])+" --> "+str(next_greater_element))

            #push the current element and index to the stack
            stack_indexes.push(i)

    #the remaining elements in the stack have no greater elements
    #print their next greater element as -1
    while(stack_indexes.isEmpty() is False):
        stack_indexes_top = stack_indexes.pop()
        print("Index "+str(stack_indexes_top)+" : "+str(arr[stack_indexes_top])+" --> "+str(-1))

#number of test cases                
test_cases = int(input("Enter the number of test cases "))
while test_cases>0:
    #length of the list
    arr_length = int(input("Enter the number of elements of the array "))
    arr = []
    for i in range (arr_length):
        arr.append(int(input()))
    findNextGreater(arr)
    test_cases-=1
    print("----------------------------------------------------")
    

                
