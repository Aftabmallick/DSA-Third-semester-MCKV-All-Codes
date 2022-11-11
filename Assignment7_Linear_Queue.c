/*7. Write a menu driven program to implement a Linear Queue using array*/
//this code is written for queue size 3
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 3
void insert();
void del();
void display();
int queue[MAXSIZE],rear=-1,front=-1;
int main()
{
    int c;
    while (1)
    {
        printf("1.Insert element to queue \n2.Delete element from queue \n3.Display all elements of queue \n4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
        } 
    }
}
void insert()
{
    int add;
    if(rear==MAXSIZE-1)
        printf("Queue Overflow \n");
    else
    {
        if(front==-1 && rear==-1)
            front = 0;
        printf("Inset the element in queue : ");
        scanf("%d",&add);
        rear+=1;
        queue[rear]=add;
    }
} 
void del()
{
    int remove;
    if(front==-1 && rear==-1)
        printf("Queue Underflow \n");
    else
    {
        remove=queue[front];	
        printf("Element deleted from queue is : %d\n",remove);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
		else
			front+=1;
    }
}
void display()
{
    int i;
    if(front ==-1 && rear==-1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for(i=front;i<=rear;i++)
            printf("%d ",queue[i]);
        printf("\n");
    }
}
