from __future__ import division
import random


OPERATORS = set(['+', '-', '*', '/', '(', ')'])
PRIORITY = {'+': 1, '-': 1, '*': 2, '/': 2}


def postfix_to_infix(formula):
    stack = []
    prev_op = None
    for ch in formula:
        if ch not in OPERATORS:
            stack.append(ch)
        else:
            b = stack.pop()
            a = stack.pop()
            if prev_op and len(a) > 1 and PRIORITY[ch] > PRIORITY[prev_op]:
                # if previous operator has lower priority
                # add '()' to the previous a
                expr = '('+a+')' + ch + b
            else:
                expr = a + ch + b
            stack.append(expr)
            prev_op = ch
    return stack[-1]

# driver code
if __name__ == '__main__':
    print(postfix_to_infix(input()))

# '1346*+61*+2*3/+'
