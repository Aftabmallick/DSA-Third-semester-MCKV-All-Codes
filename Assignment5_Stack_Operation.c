/*5. Write a menu driven C program to implement a stack operation (Push, Pop, and Display) using array.*/
//This program is written for stack of size 3
#include<stdio.h>
#include<stdlib.h>
#define max 3 //You can change stack size 
int top=-1,s[max];
//Pushing Elements in Stack
void push(int n)
{
    if(top==max-1)
    {
        puts("stack is over flown");
        return;
    }
    else
    {
        top=top+1;
        s[top]=n;
    }
}
//Deleteing element from stack(pop)
void pop()
{
    int del;
    if(top==-1)
    {
        puts("stack is underflown");
        return;
    }
    else
    {
        del=s[top];
        printf("\n poped element is %d",del);
        top=top-1;
    }
}
//Visualizing Elements of Stack
void display()
{
    int i;
    if(top==-1)
        puts("stack is empty");
    else
    {
        for(i=top;i>=0;i--)
            printf("\t%d",s[i]);
    }
}
int main()
{
    int opt,n;
    do
    {
        printf("\n 1.Push");
        printf("\n 2.Pop");
        printf("\n 3.Display");
        printf("\n 4.Exit ");
        printf("\n\nEnter your choice :: ");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            printf("\n Enter any element to push :: ");
            scanf("%d",&n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    }
    while(1);

    return 0;
}
