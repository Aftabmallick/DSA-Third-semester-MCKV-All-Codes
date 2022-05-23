/*13. Write a C program to search an element in an array using binary search technique.*/
#include<stdio.h>
int main(){
	int array[100],s,i,n,mid,first,last,flag;
	printf("Enter no of elements in array : ");
	scanf("%d",&n);
	printf("Enter %d element in array: ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("Enter searching element: ");
	scanf("%d",&s);
	first =0;
	last=n-1;
	
	while(first<=last)
	{
		mid=(first +last)/2;
		if(array[mid]<s)
		{
			first=mid+1;                      																/*aforaftab*/
			
		}
		else if(array[mid]==s)
		{
			printf("%d found at location %d",s,mid+1);
			flag=1;
			break;
		}
	
		else
		{
			last=mid-1;
			
		}
	}
	if (flag !=1)
	printf("ERROR!! not found.");
	
}
