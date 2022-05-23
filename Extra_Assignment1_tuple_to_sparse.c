/*E-1 Write a C program which takes input three tuple representation of sparse matrix and generate the 
corresponding sparse matrix.
*/
#include<stdio.h>
int main(){
	int tp[100][100],i,j,r,c,n0count,a[100][100],ir,ic;
	printf("Enter tuple matrix: \n");
	scanf("%d %d %d",&tp[0][1],&tp[0][2],&tp[0][3]);
	r=tp[0][1];
	c=tp[0][2];
	n0count=tp[0][3];
	for(i=1;i<=n0count;i++){
		for(j=1;j<=3;j++){
			scanf("%d",&tp[i][j]);
		}
	}
	for(i=1;i<=n0count;i++){
		ir=tp[i][1];
		ic=tp[i][2];
		a[ir][ic]=tp[i][3];
	}
	printf("\nmatrix form: \n");
	for(i=0;i<n0count;i++){
		for(j=0;j<3;j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
}
