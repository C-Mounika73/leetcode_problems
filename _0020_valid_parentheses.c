/*
LeetCode 20 - Valid Parentheses

Problem:
Given a string containing only brackets '()', '{}', and '[]',
determine whether the brackets are properly matched and nested.

Approach:
Use a stack to store opening brackets. For each character:
- Push opening brackets onto the stack.
- For a closing bracket, pop the top element and verify it matches
  the corresponding opening bracket.
The string is valid only if all brackets are matched and the stack
is empty at the end.

Pattern: Stack

Time Complexity: O(n)
Space Complexity: O(n)
*/

bool isValid(char* s) {
    int top = -1;
    int n = strlen(s);

    char stack[n];

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;   // push
        } else {
            if (top == -1) {
                return false;
            }

            char open = stack[top--];   // pop

            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                return false;
            }
        }
    }

    return top == -1;
}