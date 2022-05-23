/*11. Write a C program to sort a list on n numbers using the following sorting technique:
a. Selection sort.
b. Insertion Sort.
c. Quick sort.
d. Merge Sort*/
#include<stdio.h>
#include<stdlib.h>
int n;
void SelectionSort(int *a);
void InsertionSort(int *a);
void MergeSort(int *a,int low,int high);
void merge(int *a,int low,int mid,int high);
void QuickSort(int *a,int beg,int end);
int partion(int *a,int beg,int end);
void swap(int* a,int* b);
void print(int *a);
int main(){
	int c,i,j,*a;
	while(1){
		
		printf("1.Selection Sort.\n2.Insertion Sort.\n3.Merge Sort.\n4.Quick Sort.\n5.Anything Else to Exit.\n:Enter option: ");
		scanf("%d",&c);
		if(c<=4){
		
		printf("Enter size of array: ");
		scanf("%d",&n);
		a=(int *)malloc(n*sizeof(int));
		printf("Enter array element: ");
		for(i=0;i<n;i++){
		scanf("%d",(a+i));
		}
		}
		switch(c){
			case 1:
				printf("Sorted array using Selection sort: ");
				SelectionSort(a);
				print(a);
				free(a);
				break;
			case 2:
				printf("Sorted array using Insertion sort: ");
				InsertionSort(a);
				print(a);
				free(a);
				break;
			case 3:
				printf("Sorted array using Merge sort: ");
				MergeSort(a,0);
				print(a);
				free(a);
				break;
			case 4:
				printf("Sorted array using Quick sort: ");
				QuickSort(a,0);
				print(a);
				free(a);
				break;
			default:
				exit(0);
			
		}
	}
}

void SelectionSort(int *a){
		int i,j,p;
		for(i=0;i<n-1;i++){
		p=i;
		for(j=i+1;j<n;j++){
			if(*(a+j)<*(a+p)){
				p=j;
			}
			
		}
		if(p!=i){
			    swap((a+i),(a+p));
			}
	}
}
void InsertionSort(int *a){
	int i,j,temp;
		for(i=1;i<n;i++){
		temp=*(a+i);
		j=i-1;
		while(j>=0 && *(a+j)>temp){
			*(a+(j+1))=*(a+j);
			j--;
		}
		*(a+(j+1))=temp;
	}
}
void MergeSort(int *a,int low,int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

void merge(int *a,int low,int mid,int high){
	int i,j,k,z,*b;
	i=low;
	j=mid+1;
	k=low;
	b=(int *)malloc(n*sizeof(int));
	while(i<=mid && j<=high){
		if(*(a+i)<*(a+j)){
		    *(b+k)=*(a+i);
		    k++;
		    i++;
		}
		else{
		    *(b+k)=*(a+j);
		    k++;
		    j++;
		}
	}
	while(i<=mid){
	     *(b+k)=*(a+i);
		 k++;
		 i++;
	}
	while(j<=high){
	    *(b+k)=*(a+j);
		k++;
		j++;
	}
	for(k=low;k<=high;k++){
	    
		*(a+k)=*(b+k);
	}
	free(b);
}

void QuickSort(int *a,int beg,int end){
	int part;
	if(beg<end){
		part=partion(a,beg,end);
		QuickSort(a,beg,part-1);
		QuickSort(a,part+1,end);
}
}

int partion(int *a,int beg,int end){
	int pivot,i,j;
	pivot=*(a+beg);
	i=beg;
	j=end;
	while(i<j){
	
		while(*(a+i)<=pivot)
	{
			i++;
	}
		while(*(a+j)>pivot)
	{
			j--;
	}
		if(i<j)
	{
			swap((a+i),(a+j));
	}
}
	swap((a+beg),(a+j));
	return j;

}
void swap(int* a,int* b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void print(int *a){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
	printf("\n");
}
