/*10. Write a menu driven C program to implement insertion and deletion operations of a doubly linked 
list*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next,*prev;
};
struct node *new_node,*temp,*p;
struct node *start=NULL;
void create_list();
void insert_at_end();
void insert_after_given_value();
void display_list();

int main(){
	int n;
	while(1){
		printf("\n1.Create List.\n");
		printf("2.Insert At End.\n");
		printf("3.Insert After Given Value.\n");
		printf("4.Display List\n");
		printf("5.Exit\n");
		printf("\nEnter Choice:\t");
		scanf("%d",&n);
		switch(n){
			case 1:
				create_list();
				break;
			case 2:
				insert_at_front();
				break;
			case 3:
				insert_after_given_value();
				break;
			case 4:
				display_list();
				break;
			case 5:
				exit(0);
		}
	}
	
}
void create_list(){
	char c='y';
	while(c=='y'||c=='Y'){
		insert_at_end();
		printf("Want to create another node?[Y/y for yes ]\t");
		scanf(" %c",&c);
	}	
}
void insert_at_end(){
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("Enter Value:\t");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	new_node->prev=NULL;
	if(start==NULL){
		start=new_node;
	}
	else{
		temp=start;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new_node;
		new_node->prev=temp;
	}
}
void insert_after_given_value(){
	int val_for_search;
	printf("\nEnter value to be searched: \t");
	scanf("%d",&val_for_search);
	temp=start;
	while(temp!=NULL){
		if(temp->data ==val_for_search){
			new_node=(struct node *)malloc(sizeof(struct node));
			printf("\nEnter value :\t");
			scanf("%d",&new_node->data);
			new_node->prev=temp;
			new_node->next=temp->next;
			
			if(temp->next!=NULL){
			
				temp->next->prev=new_node;
			}
			temp->next=new_node;
			return;
			
		}
		temp=temp->next;
		
	}
	printf("\nValue isn't in the list.\n");
	
}

void display_list(){
	temp =start;
	while(temp!=NULL){
		printf(" %d ----> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");	
}

