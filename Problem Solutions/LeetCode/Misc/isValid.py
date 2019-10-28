"""
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
"""

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        L = list(s)
        try:
            for i in range(0, len(L)):
                if L[i] == '[' or L[i] == '{' or L[i] =='(':
                    stack.append(L[i])
                elif L[i]  == ']' and stack[-1] == '[':
                    stack.pop()
                elif L[i]  == '}' and stack[-1] == '{':
                    stack.pop()
                elif L[i]  == ')' and stack[-1] == '(':
                    stack.pop()
                else:
                    stack.append(L[i])
            if stack == []:
                return True
            else:
                return False
        except IndexError:
            return False
        