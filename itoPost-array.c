#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// push element into stack
void push(char x) {
    stack[++top] = x;
}

// pop element from stack
char pop() {
    return stack[top--];
}

// check precedence
int precedence(char x) {
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {

        char c = infix[i];

        // If operand, add to postfix
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }
        // If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    // Pop all remaining operators
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix: %s\n", postfix);

    return 0;
}
