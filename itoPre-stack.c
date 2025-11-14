#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

// Precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Reverse string
void reverse(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Step 1: Reverse the infix expression
    reverse(infix);

    // Step 2: Replace '(' with ')' and ')' with '('
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // Step 3: Convert reversed infix to postfix
    top = -1;  // reset stack
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {           // operand
            postfix[j++] = c;
        }
        else if (c == '(') {        // left parenthesis
            push(c);
        }
        else if (c == ')') {        // right parenthesis
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            pop();
        }
        else {                      // operator
            while (top != -1 && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';

    // Step 4: Reverse postfix → prefix
    strcpy(prefix, postfix);
    reverse(prefix);

    printf("Prefix: %s\n", prefix);

    return 0;
}
