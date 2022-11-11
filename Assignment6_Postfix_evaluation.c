/*6. Write a C program to evaluate a postfix expression using stack.
*/
//this code is written for expression under length 10
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define MAXSIZE 10//change stack length here
int stck[MAXSIZE],tos=-1;
//pushing element in stack
void push(int x)
{
    if(tos==MAXSIZE-1)
        printf("\nStack Overflow");
    else
    {
        tos++;
        stck[tos]=x;
    }
}
//Evaluateing and poping
int pop()
{
    int y=-1;
    if(tos==-1)
        printf("\n Stack empty");
    else
    {
        y=stck[tos];
        tos--;
    }
    return y;
}
int main()
{
    char p[100];
    int i=0,val,x,y,z;
    printf("\nEnter the Postfix expression\n");
    gets(p);
    while (p[i]!='\0')
    {
        if(isalpha(p[i]))
        {
            printf("\nEnter the value for operand %c = ",p[i]);
            scanf("%d",&val);
            push(val);
        }
        else
        {
            x=pop();
            y=pop();
            switch (p[i])
            {
                case '+':
                    z=y+x;
                    break;
                case '-':
                    z=y-x;
                    break;
                case '*':
                    z=y*x;  
                    break;
                case '/':
                    z=y/x;
                    break;
                case '^':
                    z=pow(y,x);  
                    break;
                case '%':
                    z=y%x; 
                    break;
            }
            push(z);
        }
        i++;
    }
    //display
    printf("\nThe evaluted result of postfix expression = %d ",stck[tos]);
    return 0;
}
