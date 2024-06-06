def validare(s):
    stack = []
    for c in s:
        if c in "([{":
            stack.append(c)
        else:
            if (c == ')' and stack[-1] != '(') or (c == ']' and stack[-1] != '[') or (c == '}' and stack[-1] != '{'):
                return False
            stack.pop()
    return not stack

print(validare("({}[])"))
print(validare("{(})"))