class Stack:
    
     def __init__(self):
         self.container = []

     def isEmpty(self):
         return self.size() == 0

     def push(self, item):
         self.container.append(item)

     def pop(self):
         return self.container.pop()

     def peek(self):
         if self.isEmpty():
             raise Exception("Stack Underflow!")
         return self.container[-1]

     def size(self):
         return len(self.container)

     def show(self):
         return self.container

def main():
    st = Stack()
    st.push(1)
    st.push(2)
    print('Stack: {0}'.format(st.show()))
    t = st.pop()
    print('Popped Element: {0}'.format(t))
    print('Stack: {0}'.format(st.show()))

if __name__ == '__main__':
    main()