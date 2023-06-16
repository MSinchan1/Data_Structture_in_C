								/*		CIRCULAR LINKED LIST	*/
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
struct node//Creating a structure with two parts info,next.
{
	int info;
	struct node *next;
};
struct node *tail=NULL;//tail will point the last node in the list
int main()
{
	int choice;//used for user's choice collecting purpose
	while(choice!=11)
	{
		printf("\n1.Create");
		printf("\n2.Display");
		printf("\n3.Create at beginning");
		printf("\n4.Create at end");
		printf("\n5.Create at desired position");
		printf("\n6.Delete at beginning");
		printf("\n7.Delete at end");
		printf("\n8.Delete at desired position");
		printf("\n9.Length of the list");
		printf("\n10.Reverse the list");
		printf("\n11.Exit");
		printf("\nEnter your choice: ");
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
	printf("\nEnter the data value for the node: ");
	scanf("%d",&temp->info);
	temp->next=NULL;
	if(tail==NULL)//When no node exits
	{
		tail=temp;
		tail->next=temp;
	}
	else //when atleast one node is present in the list
	{
		temp->next=tail->next;
		tail->next=temp;
		tail=temp;
	}
}
void display()//for printing the list
{
	if(tail==NULL)//when no nodes exits int he list
	{
		printf("\nList is empty");
		return;
	}
	else//when atleast one node is present in the list
	{
		struct node *ptr=tail->next;
		printf("\nList elements are: ");
		while(ptr!=tail)//traverse upto the second last node
		{
			printf("%d	",ptr->info);//printing the node elements
			ptr=ptr->next;
		}
		printf("%d	",ptr->info);//printing the las node element
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
	printf("\nEnter the data value for the node: ");
	scanf("%d",&temp->info);
	temp->next=NULL;
	if(tail==NULL)//when no nodes exits in  the list
	{
		tail=temp;
		tail->next=temp;
	}
	else
	{
		temp->next=tail->next;
		tail->next=temp;
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
	printf("\nEnter the data value for the node: ");
	scanf("%d",&temp->info);
	temp->next=NULL;
	if(tail==NULL)//when no nodes exits in  the list
	{
		tail=temp;
		tail->next=temp;
	}
	else
	{
		temp->next=tail->next;
		tail->next=temp;
		tail=temp;
	}
}
void create_pos()//for creating a node in the user defined position of the list
{
	if(tail==NULL)//when no nodes exits in  the list
	{
		printf("\nList is not created");
		return;
	}
	int pos;
	printf("\nEnter the position of the node: ");
	scanf("%d",&pos);
	if(pos==1)//when position is first
	{
		return create_start();//just call the create_start function
	}
	else
	{
		struct node *ptr=tail->next;
		for(int i=1;i<pos-1;i++)//traverse the list upto the entered position
		{
			ptr=ptr->next;
			if(ptr->next==tail->next)//this will execute when entered position is not in the list
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
		printf("\nEnter the data value for the node: ");
		scanf("%d",&temp->info);
		temp->next=NULL;
		temp->next=ptr->next;//new node is now pointing to the entered position's node
		ptr->next=temp;//ptr is now pointing to the new node
	}
}
void del_start()//for deleting the first node  from the list
{
	if(tail==NULL)//when no nodes exits in  the list
	{
		printf("\nList is empty");
		return;
	}
	struct node *temp=tail->next;
	if(temp->next==temp)//when only one node is present
	{
		printf("\nDeleted element is: %d",temp->info);//printing the deleted node's element
		tail=NULL;
		free(temp);//free the created memory
	}
	else
	{
		printf("\nDeleted element is: %d",tail->next->info);//printing the deleted node's element
		tail->next=temp->next;//tail->next is now pointing to the second node in the list
		free(temp);//free the created memory
	}
}
void del_end()//for deleting the last node  from the list
{
	if(tail==NULL)//when no nodes exits in  the list
	{
		printf("\nList is empty");
		return;
	}
	struct node *temp=tail->next;
	if(temp->next==temp)//when only one node is present
	{
		printf("\nDeleted element is: %d",temp->info);//printing the deleted node's element
		tail=NULL;
		free(temp);//free the created memory
	}
	else
	{
		struct node *ptr=tail->next,*temp;
		while(ptr->next!=tail->next)//traverse the list upto the lat node
		{
			temp=ptr;
			ptr=ptr->next;
		}
		printf("\nDeleted element is: %d",tail->info);//printing the deleted node's element
		temp->next=tail->next;//second last node is now pointing to the first node  
		tail=temp;//tail is now pointing to the second last node
		free(ptr);//free the created memory
	}
}
void del_pos()//for deleting the user defined node  from the list
{
	if(tail==NULL)//when no nodes exits in  the list
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
		int i;
		struct node *temp,*ptr=tail->next;
		for(i=1;i<pos;i++)//traverse upto the entered position of the list
		{
			temp=ptr;
			if(ptr->next==tail->next)//this will execute when entered position is not in the list
			{
				printf("\nPosition not found");
				return;
			}
			ptr=ptr->next;
		}
		if(ptr==tail)//when ptr is pointing the last node 
		{
			return del_end();//just call the delete end function
		}
		else
		{
			printf("\nDeleted element is: %d",ptr->info);//printing the deleted node's element
			temp->next=ptr->next;//entered position's previous node is now pointing to the 
			//next node of the entered position's 
			free(ptr);	//free the created memory
		}
	}
}
void length()//for finding the no of node or length of the list
{
	if(tail==NULL)//when no nodes exits in  the list
	{
		printf("\nList is empty");
		return;
	}
	else
	{
		struct node *ptr=tail->next;
		int count=1;//count is initialized as 1 because in this list we can't iterate upto the last node
		while(ptr!=tail)//traverse upto the second last node of the list
		{
			count+=1;//increasing the value for every iteration
			ptr=ptr->next;
		}
		printf("\nLength of the is: %d",count);//printing the count value
	}
}
void reverse()//to reverse a complete list
{
	if(tail==NULL)//when no nodes exits in  the list
	{
		printf("\nList is empty");
		return;
	}
	else
	{
		struct node *ptr=tail->next,*temp=ptr->next,*prev;
		while(ptr!=tail)//traverse upto the last node of the list
		{
			//reversing logic
			prev=ptr;
			ptr=temp;
			temp=temp->next;
			ptr->next=prev;
		}
		temp->next=tail;
		tail=temp;
	}
}