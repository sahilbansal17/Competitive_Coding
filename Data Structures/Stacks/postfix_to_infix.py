# python3 program to find infix for a given postfix. 
def isOperand(x): 
	return ((x >= 'a' and x <= 'z') or
			(x >= 'A' and x <= 'Z')) 

#finding infix 
def getInfix(exp) : 

	s = [] 

	for i in exp:	 
		 
		if (isOperand(i)) :		 
			s.insert(0, i) 
			
		# we are assuming that input is a valid postfix and expect an operator. 
		else: 
		
			op1 = s[0] 
			s.pop(0) 
			op2 = s[0] 
			s.pop(0) 
			s.insert(0, "(" + op2 + i +
							op1 + ")") 
			 
	return s[0] 

# Driver Code 
if __name__ == '__main__': 

	exp = "ab*c+"
	print(getInfix(exp.strip())) 

 
