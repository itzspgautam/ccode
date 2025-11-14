#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
int t = -1;

void push(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = NULL;
    newNode->data = val;

    newNode->next = top;
    top = newNode;
    t++;
}

int pop(){
    struct node *temp = NULL;
    if(top ==NULL){
        return -1;
    }
    if(top->next == NULL){
        int val = top->data;
        temp = top;
        free(temp);
        t--;
        return val;
    }else{
        temp = top;
        int val = top->data;
        top=top->next;
        t--;
        free(temp);
        return val;

    }
}

int peek(){
    if(top != NULL){
        return top->data;
    } else {
        printf("stack underflow");
        return -1;
    }
}

void display(){
    struct node *temp = top;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp= temp->next;
    }
}

int main()
{

    int choice, n;
    
    while (1)
    {
        printf("\n1 for push\n");
        printf("2 for pop\n");
        printf("3 for peek\n");
        printf("4 for display\n");
        printf("5 for exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int val;
            scanf("%d", &val);
            push(val);
            break;
        }
        case 2:
        {
            int val = pop();
            if (val >= 0)
            {
                printf("value poped %d", val);
            }
            break;
        }
        case 3:
        {
            int val = peek();
            if (val >= 0)
            {
                printf("value at top %d", val);
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
