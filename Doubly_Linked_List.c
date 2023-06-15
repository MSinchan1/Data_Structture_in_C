							/*DOUBLY LINKED LIST*/
#include<stdio.h>
#include<stdlib.h>
//Declaring all required functions
void create();
void display();
void create_start();
void create_end();
void create_pos();
void del_start();
void del_end();
void del_pos();
void length();
void reverse();
struct node//Creating a structure with three parts info,next & prev
{
	int info;
	struct node *next,*prev;
};
struct node *start=NULL;
struct node *tail=NULL;//tail will point the last node in the list
int main()
{
	int choice;//used for user's choice collecting purpose
	while(choice!=11)
	{
		printf("\n1.Create");
		printf("\n2.Display");
		printf("\n3.Create at start");
		printf("\n4.Create at end");
		printf("\n5.Create at desired position");
		printf("\n6.Delete at start");
		printf("\n7.Delete at end");
		printf("\n8.Delete at desired position");
		printf("\n9.Length of the string");
		printf("\n10.Reverse the string");
		printf("\n11.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				create_start();
				break;
			case 4:
				create_end();
				break;
			case 5:
				create_pos();
				break;
			case 6:
				del_start();
				break;
			case 7:
				del_end();
				break;
			case 8:
				del_pos();
				break;
			case 9:
				length();
				break;
			case 10:
				reverse();
				break;
			case 11:
				exit(0);
				break;
			default:
				printf("\nWrong choice");
				break;
		}
	}
	return 0;
}
void create()//for creating nodes when list is completely empty
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));//initialize memory
	if(temp==NULL)
	{
		printf("\nMemory allocation failed");
		return;
	}
	printf("\nEnter the data value for the node:");
	scanf("%d",&temp->info);
	temp->next=temp->prev=NULL;
	if(start==NULL)//When no node exits
	{
		start=tail=temp;
	}
	else //when atleast one node is present in the list
	{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
}
void display()//for printing the list
{
	if(start==NULL)//when no nodes exits int he list
	{
		printf("\nList is empty");
		return;
	}
	else//when atleast one node is present in the list
	{
		struct node *ptr=start;
		printf("\nList elements are: ");
		while(ptr!=tail->next)//traverse upto the last node
		{
			printf("%d	",ptr->info);//printing the node elements
			ptr=ptr->next;
		}
	}
}
void create_start()//for creating a node in the first position of the list
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));//initialize memory
	if(temp==NULL)
	{
		printf("\nMemory allocation failed");
		return;
	}
	printf("\nEnter the data value for the node:");
	scanf("%d",&temp->info);
	temp->next=temp->prev=NULL;
	if(start==NULL)//when no nodes exits in  the list
	{
		start=tail=temp;
	}
	else
	{
		temp->next=start;
		start->prev=temp;
		start=temp;
	}
}
void create_end()//for creating a node in the end position of the list
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));//initialize memory
	if(temp==NULL)
	{
		printf("\nMemory allocation failed");
		return;
	}
	printf("\nEnter the data value for the node:");
	scanf("%d",&temp->info);
	temp->next=temp->prev=NULL;
	if(start==NULL)//when no nodes exits in  the list
	{
		start=tail=temp;
	}
	else
	{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
}
void create_pos()//for creating a node in the user defined position of the list
{
	int pos;
	printf("\nEnter the position of the node:");
	scanf("%d",&pos);
	if(pos==1)//when position is first
	{
		return create_start();//just call the create_start function
	}
	else
	{
		struct node *ptr=start;
		for(int i=1;i<pos-1;i++)//just call the create_start function
		{
			ptr=ptr->next;
			if(ptr->next==NULL)//this will execute when entered position is not in the list
			{
				printf("\nPosition not found");
				return;
			}
		}
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));//initialize memory
		if(temp==NULL)
		{
			printf("\nMemory allocation failed");
			return;
		}
		printf("\nEnter the data value for the node:");
		scanf("%d",&temp->info);
		temp->next=ptr->next;//new node is pointing the next position's node
		temp->prev=ptr;//new node's prev pointer is pointing the previous one
		ptr->next=temp;//previous  ode is pointing to the newly created node
		ptr->next->prev=temp;//new node's next node's prev pointer is now pointing the new node
	}
}
void del_start()//for deleting the first node  from the list
{
	if(start==NULL)//when no nodes exits in  the list
	{
		printf("\nList is empty");
		return;
	}
	else
	{
		printf("\nDeleted element is: %d",start->info);//printing the deleted node's element
		start=start->next;//start pointer is now pointing to the second node
	}
}
void del_end()//for deleting the last node  from the list
{
	if(start==NULL)//when no nodes exits in  the list
	{
		printf("\nList is empty");
		return;
	}
	else if(start->next==NULL)//when only first node exits in  the list
	{
		printf("\nDeleted element is: %d",tail->info);//printing the deleted node's element
		start=NULL;//intialize the start pointer with NULL
	}
	else//when more than one node is present in the list
	{
		printf("\nDeleted element is: %d",tail->info);//printing the deleted node's element
		tail=tail->prev;//last node is now pointing to it's previous one
		tail->next=NULL;//initialize the last node with null
	}
}
void del_pos()//for deleting the user defined node  from the list
{
	if(start==NULL)//when no nodes exits in  the list
	{
		printf("\nList is empty");
		return;
	}
	int pos;
	printf("\nEnter the position of the node: ");
	scanf("%d",&pos);
	if(pos==1)//when position is first
	{
		return del_start();//just call the del_start function
	}
	else
	{
		struct node *ptr=start;
		for(int i=1;i<pos;i++)//traverse upto the entered position of the list
		{
			ptr=ptr->next;
			if(ptr==NULL)//this will execute when entered position is not in the list
			{
				printf("\nPosition not found");
				return;
			}
		}
		if(ptr->next==NULL)//when ptr is pointing the last node 
		{
			return del_end();//just call the delete end function
		}
		else
		{
			printf("\nDeleted element is: %d",ptr->info);//printing the deleted node's element
			ptr->prev->next=ptr->next;////deleted node's previous node's next pointer is now pointing
			//to the deleted node's next node
			ptr->next->prev=ptr->prev;//deleted node's next node's previous pointer is now pointing to the 
			//deleted nodes previous node
		}
		free(ptr);//free the created memory
	}
}
void length()//for finding the no of node or length of the list
{
	if(start==NULL)//when no nodes exits in  the list
	{
		printf("\nList is empty");
		return;
	}
	else
	{
		struct node *ptr=start;
		int count=0;
		while(ptr!=tail->next)//traverse upto the last node of the list
		{
			count+=1;//increasing the value for every iteration
			ptr=ptr->next;
		}
		printf("\nLength of the list is: %d",count);//printing the count value
	}
}
void reverse()//to reverse a complete list
{
	if(start==NULL)//when no nodes exits in  the list
	{
		printf("\nList is empty");
		return;
	}
	else
	{
		struct node *ptr=start,*temp;
		while(ptr!=NULL)//traverse upto the last node of the list
		{	//reversing logic
			temp=ptr->next;
			ptr->next=ptr->prev;
			ptr->prev=temp;
			ptr=temp;
		}
		//just swaping the tail and start pointer with each other
		temp=start;
		start=tail;
		tail=temp;
	}
}