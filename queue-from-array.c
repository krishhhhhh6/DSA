#include<stdio.h>
#define N
int queue[N];
int front=-1;
int rear=-1;
void enqueue()
{
    int x;
    printf("enter the element:");
    scanf("%d",&x);
    if (rear==N-1){
        printf("overflow");}
    else if (front==-1 && rear ==-1){
            front=rear=0;
            queue[rear]=x;
        }
        else{
            rear++;
            queue[rear]=x;
        }
    }
void dequeue()
{
    if (front==-1 && rear==-1){
        printf("under flow");}
    else if (front==rear ){
        front=rear=-1;
    }
    else {
        printf("%d",queue[front]);
        front++;
    }
    }
void display()
{
    if (front==-1 && rear==-1){
        printf("under flow");}
        else{
            for (int i=front;i<rear+1;i++) {
                printf("%d",queue[i]);
            }
        }
        
}
void peek()
{
    if (front==-1 && rear==-1){
        printf("under flow");}
        else {
            printf("%d",queue[front]);
        }

}
int main() 
{
    int choice;
    while (1) {
        printf("\n1->For enqueue \n2->For dequeue \n3->for display \n4->for peek \nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
            enqueue();
        else if (choice == 2)
            dequeue();
        else if (choice == 3)
            display();
        else if (choice == 4)
            peek();
        else
            printf("Wrong choice entered !!\n");
    }
    return 0;
}

