
#include <stdbool.h>

bool isValid(char* s) {
    char stack[10000];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            top++;
            stack[top] = ch;
        }
        else {
            if (top == -1) {
                return false;
            }

            char opening = stack[top];
            top--;

            if (ch == ')' && opening != '(') {
                return false;
            }
            if (ch == '}' && opening != '{') {
                return false;
            }
            if (ch == ']' && opening != '[') {
                return false;
            }
        }
    }

    return top == -1;
}
