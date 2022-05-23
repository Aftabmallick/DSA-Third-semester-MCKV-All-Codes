/*3. Write a C program to solve the Tower of Hanoi problem for n disks (n should be taken as keyboard 
input) using recursion.*/
#include<stdio.h>
#include<stdlib.h>
void toh(int,char,char,char);
int main()
{
	
	int n;
	printf("Enter the number of disks:");
	scanf("%d",&n);
	printf("\nThe sequence of moves involved in the Tower of Hanoi are:");
	toh(n,'A','C','B');
	return 0;
}
void toh(int n,char source,char destination,char space)
{
	
	if (n>0)
	{
		toh(n - 1,source,space,destination);
	    printf("\nMove disk %d from source %c to destination %c",n,source,destination);
	    toh(n-1,space,destination,source);
		
	}
}
