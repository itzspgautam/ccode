#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node *next;
};

struct Node *top = NULL;

// push onto linked list stack
void push(char x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

// pop from stack
char pop() {
    if (top == NULL)
        return '\0';

    struct Node *temp = top;
    char value = temp->data;

    top = top->next;
    free(temp);

    return value;
}

// peek at top of stack
char peek() {
    if (top == NULL)
        return '\0';
    return top->data;
}

// precedence function
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
    char infix[100], postfix[100];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {

        char c = infix[i];

        // operand → add to postfix
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // '(' → push
        else if (c == '(') {
            push(c);
        }
        // ')' → pop until '('
        else if (c == ')') {
            while (top != NULL && peek() != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }
        // operator
        else {
            while (top != NULL && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    // pop remaining operators
    while (top != NULL)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix: %s\n", postfix);

    return 0;
}
