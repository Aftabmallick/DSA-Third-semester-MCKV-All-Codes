/*9. Write a menu driven C program to insert and delete element at following positions (BEGIN, END, 
AFTER GIVEN VALUE,) of a linked list and also reverse the same.*/
#include <stdio.h>
#include<stdlib.h>
//declearing node of struct datatype
struct node{
	int data; 
	struct node *next; 
};  
struct node *start=NULL;
struct node *new_node,*temp;
//Displaying elements of list
void display(){
	temp=start;
	while(temp!=NULL)
	{
		printf("%d----->",(*temp).data);
		temp=temp->next;
	}
	printf("NULL");	
}
//function for reversing linkedlist
void reverse(){
	struct node *prev=NULL;
	struct node *next;
	temp=start;
	while(temp!=NULL){
			next=temp->next;
			temp->next=prev;
			prev=temp;
			temp=next;
	}
	start=prev;
}
//function for deleting a node from linkedlist
void del_value(){
	int n,c=0;
	struct node *prev;
	printf("Enter value to be deleted next: ");
	scanf("%d",&n);
	temp=start;
	
	while(temp!=NULL){
		prev=temp;
		if((*temp).data==n){
		
		prev->next=temp->next->next;
		free(temp->next);
		c=0;
		return;
		}
		else
		c++;
		temp=temp->next;
		}
	if(c!=0){
		printf("Value not found.");
	}
}
//function for deleting a node from a given position
void del_position(){
	int pos,i;
	struct node *next;
	printf("Enter position: ");
	scanf("%d",&pos);
	temp=start;
	if(pos==0){
		temp=temp->next;
		return;
	}
	for(i=0;i<pos-2;i++){
		temp=temp->next;
	}
	if(temp==NULL){
		printf("Position isn't in range.");
		return;
	}
	next=temp->next->next;
	free(temp->next);
	temp->next=next;
}
void del_rear(){
	if(start==NULL){
		printf("List Empty");
	}
	struct node *todelete;
	todelete=start;
	temp=start;
	while(todelete->next!=NULL){
		temp=todelete;
		todelete=todelete->next;
	}
	if(todelete ==start)
	start=NULL;
	else
	temp->next=NULL;
	
	free(todelete);
	
}
void del_front(){
	if(start==NULL){
		printf("List Empty");
	}
	else{
	
	temp=start;
	start=start->next;
	free(temp);
}
}
void insert_after_given_position(){
	int pos,i;
	printf("Enter position: ");
	scanf("%d",&pos);
	temp=start;
	pos=pos-1;
	while(pos--){
		
		temp=temp->next;
		if(temp==NULL){
			printf("Position out of range.");
			free(temp->next);
			return;
		}
	}
	new_node=(struct node*)malloc(1*sizeof(struct node));
	printf("Enter value for insertion: ");
	scanf("%d",&new_node->data);
	new_node->next=temp->next;
	temp->next=new_node;
	free(temp->next);
}
void insert_after_given_value(){
	int n,count=0;
	printf("Enter value to be searched: ");
	scanf("%d",&n);
	temp=start;
	while(temp!=NULL){
		if((*temp).data==n){
			new_node=(struct node*)malloc(1*sizeof(struct node));
			printf("Enter value for insertion: ");
			scanf("%d",&new_node->data);
			
			new_node->next=temp->next;
			temp->next=new_node;
			count=0;
			break;
		}
		else{
			count++;
		}
		temp=temp->next;
	}
	if(count!=0){
		printf("Value not Found.");
	}
	
}
void insert_rear(){
	new_node=(struct node*)malloc(1*sizeof(struct node));
	printf("\nEnter the value of new node: ");
	scanf("%d",&new_node->data);
		new_node->next=NULL;
		if(start==NULL)
			start=new_node;
		else
		{
			temp=start;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=new_node;
		}
}
void insert_front(){
	new_node=(struct node*)malloc(1*sizeof(struct node));
	printf("\nEnter the value of new node: ");
	scanf("%d",&new_node->data);
	new_node->next=start;
	start=new_node;
}
void Create_list(){
	char ch='y';
	while(ch=='Y'||ch=='y')
	{
		insert_rear();
		printf("want to create another node?[press Y or y]  ");
		scanf(" %c",&ch);
	}
}

int main()
{
   int ch;
   while(1){
       printf("\n1.Create List\n2.Insert at Front\n3.Insert at Rear\n4.Insert after given value.\n5.Insert after given position.\n6.Delete from front.\n7.Delete from rear.\n8.Delete from position.\n9.delete next value of entered value.\n10.Reverse.\n11.Display\n12.Exit\n");
       printf("Enter Choice: ");
       scanf("%d",&ch);
       switch(ch){
            case 1:
                Create_list();
                break;
            case 2:
            	insert_front();
            	break;
            case 3:
            	insert_rear();
            	break;
            case 4:
            	insert_after_given_value();
            	break;
            case 5:
            	insert_after_given_position();
            	break;
            case 6:
            	del_front();
            	break;
            case 7:
            	del_rear();
            	break;
            case 8:
            	del_position();
            	break;
            case 9:
            	del_value();
            	break;
            case 10:
            	reverse();
            	break;
            case 11:
            	display();
            	break;
            case 12:
            	exit(1);
       }
   }

    return 0;
}