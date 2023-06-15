								/*SINGLE LINKED LIST*/
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
struct node//Creating a structure with two parts info & next
{
	int info;
	struct node *next;
};
struct node *start=NULL;
int main()
{
	int choice; //used for user's choice collecting purpose
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
    temp->next=NULL;
    if(start==NULL)//When no node exits
    {
        start=temp;
    }
    else//when atleast one node is present in the list
    {
        struct node *ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void display()//for printing the list
{
    if(start==NULL)//when no nodes exits in  the list
    {
        printf("\nList is empty");
        return;
    }
    else//when atleast one node is present in the list
    {
        struct node *ptr=start;
        printf("\nList elements are:");
        while(ptr!=NULL)//traverse upto the last node
        {
            printf("%d  ",ptr->info); //printing the node elements
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
    temp->next=NULL;
    if(start==NULL)//when no nodes exits in  the list
    {
        start=temp;
    }
    else
    {
        temp->next=start;
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
    temp->next=NULL;
    if(start==NULL)//when no nodes exits in  the list
    {
        start=temp;
    }
	else
	{
		struct node *ptr=start;
		while(ptr->next!=NULL)//traverse upto the last node
		{
			ptr=ptr->next;
		}
		ptr->next=temp;//last node is pointion to the newly created node
	}
}
void create_pos()//for creating a node in the user defined position of the list
{
	if(start==NULL)//when no nodes exits in  the list
	{
		printf("\nList is not Created ");
		return;
	}
	int i,pos;
	printf("\nEnter the position of the node:");
	scanf("%d",&pos);
	if(pos==1)//when position is first
	{
		return create_start();//just call the create_start function
	}
	else
	{
		struct node *ptr=start;
		for(i=1;i<pos-1;i++)//traverse the list upto the position-1 node
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
    	temp->next=NULL;
		temp->next=ptr->next;//new node is pointing the next position's node
		ptr->next=temp;//previous  ode is pointing to the newly created node
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
		struct node *ptr=start;
		printf("\nDeleted element is: %d",ptr->info);//printing the deleted node's element
		start=ptr->next;//start pointer is now pointing to the second node
		free(ptr);//free the created memory
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
		printf("\nDeleted element is: %d",start->info);//printing the deleted node's element
		start=NULL;//intialize the start pointer with NULL
	}
	else//when more than one node is present in the list
	{
		struct node *ptr=start,*temp;
		while(ptr->next!=NULL)//traverse upto to last node of the list
		{
			temp=ptr;//this will point the second last node of the list
			ptr=ptr->next;
		}
		printf("\nDeleted element is: %d",ptr->info);//printing the deleted node's element
		temp->next=NULL;//initialize the last node with null
		free(ptr);//free the created memory
	}
}
void del_pos()//for deleting the user defined node  from the list
{
	if(start==NULL)//when no nodes exits in  the list
	{
		printf("\nList is empty");
		return;
	}
	int i,pos;
	printf("\nEnter the position of the node:");
	scanf("%d",&pos);
	if(pos==1)//when position is first
	{
		return del_start();//just call the del_start function
	}
	else
	{
		struct node *temp,*ptr=start;
		for(i=1;i<pos;i++)//traverse upto the entered position of the list
		{
			temp=ptr;//this will point the second last node of the list
			if(ptr->next==NULL)//this will execute when entered position is not in the list
			{
				printf("\nPosition not found");
				return;
			}
			ptr=ptr->next;
		}
		printf("\nDeleted element is: %d",ptr->info);//printing the deleted node's element
		temp->next=ptr->next;//previous node is now pointing to the entered position's next node 
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
        while(ptr!=NULL)//traverse upto the last node of the list
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
		struct node *temp,*ptr=start,*prev=NULL;
		while(ptr!=NULL)//traverse upto the last node of the list
		{		//reversing logic
			temp=ptr;
			ptr=ptr->next;
			temp->next=prev;
			prev=temp;
		}
		start=prev;
	}
}