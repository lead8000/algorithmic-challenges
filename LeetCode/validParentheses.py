class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        
        for bracket in s:
            if bracket == '(' or bracket == '[' or bracket == '{':
                stack.append(bracket)
            elif len(stack) > 0 and \
                ((stack[-1] == '(' and bracket == ')') or \
                 (stack[-1] == '[' and bracket == ']') or \
                 (stack[-1] == '{' and bracket == '}')):
                stack.pop()
            else:
                return False
        
        return len(stack) == 0
    
print(Solution().isValid("]"))