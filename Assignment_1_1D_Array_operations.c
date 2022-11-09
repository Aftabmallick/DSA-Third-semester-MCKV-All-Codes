/*Write a menu driven program in C language to implement the following operations in a 1D array.
a. Find maximum and minimum elements from the array along with their positions.
b. Insert an element at a given position.
c. Remove an element from a given position.
d. Display the array.*/

#include<stdio.h>
#include<stdlib.h>
int main(){
	int *a,i,n,min,max,p,z,c,x,v;
   	char ch;
    printf("Enter size of array : ");
    scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
    printf("Enter elements in array : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    while(1){
    printf("(1 - max min, 2-Insert, 3-Remove, 4-Display, 5-Exit)\nEnter[1-5] :");
    scanf(" %c",&ch);
    
	
 	switch(ch){
	 
	 case '1':
    min=max=a[0];
    for(i=1; i<n; i++)
    {
        if(min>a[i])
			min=a[i];   
		if(max<a[i])
			max=a[i];       
    }
    printf("minimum of array is : %d\n",min);
    printf("\nmaximum of array is : %d\n",max);
	break;
	
	case '2':
	
    printf("Enter position[1-%d]: ",n);
    scanf("%d",&p);
    printf("Enter value to insert : ");
    scanf("%d",&v);
    for(i=n-1;i>=p-1;i--){
    	a[i+1]=a[i];
    	
	}
    a[p-1]=v;
	n++;
    
    break;
	case '3':
    	printf("Enter position to delete :");
    	scanf("%d",&c);
    	
    	for(i=c-1;i<n-1;i++){
    		a[i]=a[i+1];
    		
    		
		}
		n--;
		break;
		case '4':
			
		for(i=0;i<n;i++){
    		printf("%d ",a[i]);
    		
		}
		printf("\n");
		break;
		case '5':
			exit(0);
	}
}
}


