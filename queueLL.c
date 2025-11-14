#include <stdio.h>
#include <stdlib.h>

// #define MAX 100

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void insertFront(int val){
    

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next= NULL;

    if((front == NULL) && (rear == NULL)){
        front=rear =newNode;
    }

    newNode->next = front;
    front = newNode;
}

void insertRear(int val){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data= val;
    newNode->next= NULL;
    if((front == NULL) && (rear == NULL)){
        front=rear=newNode;
    }
    rear->next=newNode;
    rear=newNode;
    rear->next=NULL;
}

int deleteFront(){
    int val = -1;
    if((front == NULL) && (rear == NULL)){
        printf("Queue is empty");
    }
    struct node *temp;
    if(front == rear){
        temp = front;
        val = temp->data;
        front = rear = NULL;
        free(temp);
        
    } else{
        temp=front;
        front = front->next;
        val = temp->data;
        free(temp);
        
    }
    return val;
}

int deleteRear(){
    if((front == NULL) && (rear == NULL)){
        printf("Queue is empty");
    }
    struct node *temp;
    if(front == rear){
        temp = front;
        int val = temp->data;
        front = rear = NULL;
        free(temp);
        return val;
    } else{
        temp=front;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        rear = temp;
        temp = temp->next;
        int val = temp->data;
        rear->next = NULL;
        free(temp);
        return val;
    }

    return -1;
}

void display(){
    struct node * temp = NULL;
    if(front != NULL){
        temp = front;
        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}

int main(){
    int choice, n, val;

    while(1){
        printf("\n1 to inser\n");
        printf("\n2 to insertend\n");
        printf("\n3 to deletefront\n");
        printf("\n4 to deleteRear\n");
        printf("\n5 to display\n");
        printf("\n6 to exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:{
                printf("\nEnter the value to be inserted.");
                scanf("%d", &val);
                insertFront(val);
                break;
            }
            case 2:{
                printf("\nEnter the value to be inserted.");
                scanf("%d", &val);
                insertRear(val);
                break;
            }
            case 3:{
                int val = deleteFront();
                printf("\nDeleted value is %d", val);
                break;
            }
            case 4:{
                int val = deleteRear();
                printf("\nDeleted value is %d", val);
                break;
            }
            case 5:{
                display();
                break;
            }
            case 6:{
                exit(0);
                break;
            }
            default:
                printf("Invalid Choice");
                break;
            
        }
    }
    return 0;
}