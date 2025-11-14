// stack using array
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char x)
{
    if (top <= MAX)
    {
        top++;
        stack[top] = x;
    }
    else
    {
        printf("Stack overflow!");
        return;
    }
}

char pop()
{
    if (top >= 0)
    {
        char val = stack[top];
        top--;
        return val;
    }
    else
    {
        printf("stack underflow");
        return -1;
    }
}

char peek()
{
    if (top >= 0)
    {
        int val = stack[top];
        return val;
    }
    else
    {
        printf("stack is empty");
        return -1;
    }
}

int size()
{
    return top;
}

void display()
{

    if (top >= 0)
    {
        for (int i = top; i >= 0; i--)
        {
            printf("element at position %d", stack[i]);
        }
    }
}

int precedence(char c)
{
    switch (c)
    {
    case '^':
        return 3;
    case '*':
    case '/':
    case '%':
        return 2;
    case '+':
    case '-':
        return 1;
    }
}

void infixToPostfix(char *infix, char *postfix)
{
    int k = 0;
    for (int i = 0; i < strlen(infix); i++)
    {
        char c = infix[i];
        if (isdigit(c))
        {
            postfix[k++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[k++] = pop();
            }
            char brac = pop();
        }
        else
        {
            while (top != -1 && precedence(c) >= precedence(peek()))
            {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while (top != -1)
    {
        postfix[k++] = pop();
    }

    printf("\n%s\n", infix);
    printf("\n%s\n", postfix);
}

int main()
{
    int choice, n;
    char infix[] = "(7+3)*(5-2)/4";
    char postfix[MAX];
    while (1)
    {
        printf("1 for push\n");
        printf("2 for pop\n");
        printf("3 for peek\n");
        printf("4 for display\n");
        printf("5 for size\n");
        printf("6 for exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            char val;
            scanf("%c", &val);
            push(val);
            break;
        }
        case 2:
        {
            char val = pop();
            if (val >= 0)
            {
                printf("value poped %c", val);
            }
            break;
        }
        case 3:
        {
            char val = peek();
            if (val >= 0)
            {
                printf("value at top %c", val);
            }
            break;
        }
        case 4:
        {
            display();
            break;
        }
        case 5:
        {
            char val = size();
            if (val >= 0)
            {
                printf("value at top %c", val);
            }
            break;
        }
        case 6:
        {
            infixToPostfix(infix, postfix);
            break;
        }
        case 7:
        {
            exit(0);
            break;
        }
        default:
        {
            printf("Invalid choice");
            break;
        }
        }
    }

    return 0;
}
