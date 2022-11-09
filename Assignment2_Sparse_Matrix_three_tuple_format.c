//Write a C program to represent a sparse matrix in three tuple format.
//code written for int datatype change accordingly
#include<stdio.h>
#include<stdlib.h>
int main(){
	
	int **a,**sp,r,c,i,j,n0count=0,z=1;
	
	printf("Enter no fo Rows and Columns: ");
	scanf("%d %d",&r,&c);
	a=(int**)malloc(r*sizeof(int));
	for ( i = 0; i < c; i++)
	{
		a[i]=(int*)malloc(c*sizeof(int));
	}
	sp=(int**)malloc(r*sizeof(int));
	for ( i = 0; i < c; i++)
	{
		sp[i]=(int*)malloc(c*sizeof(int));
	}
	printf("Enter %d matrix data : \n",r*c);
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&a[i][j]);
			
		}
		printf("\n");
	}
	printf("entered matrix is : \n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d ",a[i][j]);
			if(a[i][j]!=0){
				n0count++;
				
			}
		}
		printf("\n");
	}
	if(n0count>r*c/2){
		printf("Can not form sparse matrix: ");
		exit(0);
	}
	else{
		sp[0][0]=r;
		sp[0][1]=c;
		sp[0][2]=n0count;
		for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(a[i][j]!=0){
			
				sp[z][0]=i+1;
				sp[z][1]=j+1;
				sp[z][2]=a[i][j];
				z++;
	}
		
		}
	}
		printf("Tuple Matrix : \n");
		
		for(i=0;i<=n0count;i++){
			for(j=0;j<3;j++){
				printf("%d  ",sp[i][j]);
			}
			printf("\n");
		}
			
	}}
