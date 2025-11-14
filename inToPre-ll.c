#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node *next;
};

struct Node *top = NULL;

// push to LL stack
void push(char x) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

// pop from LL stack
char pop() {
    if (top == NULL) return '\0';

    struct Node *temp = top;
    char value = temp->data;

    top = top->next;
    free(temp);

    return value;
}

// peek stack
char peek() {
    if (top == NULL) return '\0';
    return top->data;
}

// precedence
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// reverse string
void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    char infix[100], postfix[100], prefix[100];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    // STEP 1: Reverse infix
    reverse(infix);

    // STEP 2: Swap parentheses
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // STEP 3: Convert reversed infix → postfix using LL stack
    top = NULL;
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {               // operand
            postfix[j++] = c;
        }
        else if (c == '(') {            // left paren
            push(c);
        }
        else if (c == ')') {            // right paren
            while (top != NULL && peek() != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }
        else {                           // operator
            while (top != NULL && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    // pop remaining operators
    while (top != NULL)
        postfix[j++] = pop();

    postfix[j] = '\0';

    // STEP 4: Reverse postfix → prefix
    strcpy(prefix, postfix);
    reverse(prefix);

    printf("Prefix: %s\n", prefix);

    return 0;
}
