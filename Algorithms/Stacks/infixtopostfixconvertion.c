/* This Program converts infix expression to postfix expression */
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
// Top of the stack
int top = -1;
// Array representing stack
char stack[MAX_SIZE];
// Checks whether stack is empty or not
int isStackEmpty(void){
	return (top < 0) ? 1 : 0; 
}
// Checks whether stack is full or not
int isStackFull(void){
	return (top == MAX_SIZE) ? 1 : 0;
}
// Push elements in the stack
void pushStack(char item){
	if(isStackFull()){
		printf("Stack Overflow!\n");
		return;
	}
	top++;
	stack[top] = item;
}
// Pop elements in the stack
char popStack(void){
	if(isStackEmpty()){
		printf("Stack Underflow!\n");
		return -1;
	}
	char item = stack[top];
	top--;
	return item;
}
// Function to input the infix expression
void scanExp(char *str){
	char ch,i;
	for(i=0; (ch=getchar()) != '\n'; i++){
		str[i] = ch;
	}
	str[i] = '\0';
}

// Function to check whether the character is an operator
int isOperator(char ch){
	switch(ch){
		case '^':
		case '/':
		case '*':
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}

// Function converts the infix expression to postfix expression
void infix2postfix(char *infix, char *postfix){
	// Operator Predecence
	int operators[256];
	operators['^'] = 0;
	operators['*'] = 1;
	operators['/'] = 1;
	operators['+'] = 2;
	operators['-'] = 2;

	infix[strlen(infix)] = ')';

	int i, j;
	pushStack('(');
	for(i=0,j=0;!isStackEmpty();){
		if(!isOperator(infix[i]) && infix[i] != '(' && infix[i] != ')'){
			postfix[j]=infix[i];
			i++;
			j++;
		}else if(infix[i] == '('){
			pushStack(infix[i]);
			i++;
		}else if(isOperator(infix[i])){
			while(isOperator(stack[top]) && operators[stack[top]] <= operators[infix[i]]){
				char operator = popStack();
				postfix[j]=operator;
				j++;
			}
			pushStack(infix[i]);
			i++;
		}else if(infix[i] == ')'){
			char item;
			while((item=popStack()) != '('){
				postfix[j] = item;
				j++;
			}
			i++;
		}
	}
	postfix[j] = '\0';
}

int main(void){
	char infix[100], postfix[100];
	printf("Enter the infix expression : ");
	scanExp(infix);
	printf("Infix Expression : %s\n", infix);
	infix2postfix(infix, postfix);
	printf("Postfix Expression : %s\n", postfix);
	return 0;
}
