/*4. Write a C program to display the Fibonacci sequence for n terms using recursion.
*/
#include<stdio.h>
int f(int n)
	{
		if(n==0 || n==1) //first two terms
			return n;
		else
			return f(n-1) + f(n-2);
	}
int main()
	{
		int n,i;
		printf("Enter terms: ");
		scanf("%d", &n);
		for(i = 0; i < n; i++){
		
			printf("%d ", f(i)); //to display the Fibonacci sequence up to n-th term
			
		}
			return 0;
	}

