/*12. Write a C program to search an element in an array using linear search technique.*/
#include<stdio.h>
int main(){
	int array[100],s,i,n;
	printf("Enter no of element in array");		//linear search
	scanf("%d",&n);
	printf("Enter %d elementsin array: ",n);
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	printf("Enter no to search: ");
	scanf("%d",&s);
	for(i=0;i<n;i++){
		if(array[i]==s){
			printf("%d is present at location %d",s,i+1);
			break;
		}
	}
	if(i==n){
		printf("%d isn't present in the array.",s);
	}
}
