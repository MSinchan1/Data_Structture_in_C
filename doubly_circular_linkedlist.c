								/*	DOUBLY CIRCULAR LINKED LIST*/
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
struct node//Creating a structure with three parts info,next & prev
{
    int info;
    struct node *next,*prev;
};
struct node *start=NULL;
struct node *tail=NULL;//tail will point the last node in the list
int main()
{
	int choice=0;//used for user's choice collecting purpose
	while(choice!=10)
	{
		printf("\n1.Create");
		printf("\n2.Display");
		printf("\n3.Create at start");
		printf("\n4.Create at end");
		printf("\n5.Create at desired position");
		printf("\n6.Delete at start");
		printf("\n7.Delete at end");
		printf("\n8.Delete at desired position");
		printf("\n9.Length of the list");
		printf("\n10.Exit");
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
    if(start==NULL)//When no node exits
    {
        start=tail=temp;
        tail->next=temp;
    }
    else//when atleast one node is present in the list
    {
        tail->next=temp;
        temp->prev=tail;
        temp->next=tail->next;
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
        while(ptr!=tail)//traverse upto the second last node
        {
            printf("%d      ",ptr->info);//printing the node elements
            ptr=ptr->next;
        }
        printf("%d",ptr->info);//printing the last node elements
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
    if(start==NULL)//when no nodes exits in  the list
    {
        start=tail=temp;
        tail->next=temp;
    }
    else
    {
        temp->next=start;
        temp->prev=NULL;
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
    printf("\nEnter the data value for the node: ");
    scanf("%d",&temp->info);
    if(start==NULL)//when no nodes exits in  the list
    {
        start=tail=temp;
        tail->next=temp;
    }
    else
    {
        tail->next=temp;
        temp->prev=tail;
        temp->next=tail->next;
        tail=temp;
    }
}
void create_pos()//for creating a node in the user defined position of the list
{
    if(start==NULL)//when no nodes exits in  the list
    {
        printf("\nList is not created");
        return;
    }
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
        for(int i=1;i<pos-1;i++)//traverse the list upto the entered position
        {
            if(ptr->next==tail->next)//this will execute when entered position is not in the list
            {
                printf("\nPosition not found");
                return;
            }
            ptr=ptr->next;
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
        temp->prev=ptr;//new node's prev pointer is pointing entered position's previous pointer
        temp->next=ptr->next;//new node's next pointer is now pointing to the entered position's next node
        ptr->next->prev=temp;//entered position's next node's prev pointer is pointing new node
        ptr->next=temp;//entered position's next pointer is pointing to new node
    }
}
void del_start()//for deleting the first node  from the list
{
    if(start==NULL)//when no nodes exits in  the list
    {
        printf("\nList is empty");
        return;
    }
    else if(start->next==start)//when only one node is present
    {
        printf("\nDeleted element is: %d",start->info);//printing the deleted node's element
        start=NULL;//intialize the start pointer with NULL
    }
    else
    {
        struct node *ptr=start;
        printf("\nDeleted element is: %d",start->info);//printing the deleted node's element
        start->next->prev=tail;//second node's prev is pointing to the tail 
        start=start->next;//start is pointing second node
        tail->next=start;
    }
}
void del_end()//for deleting the last node  from the list
{
    if(start==NULL)//when no nodes exits in  the list
    {
        printf("\nList is empty");
        return;
    }
    else if(start->next==start)//when only first node exits in  the list
    {
        printf("\nDeleted element is: %d",start->info);//printing the deleted node's element
        start=NULL;//intialize the start pointer with NULL
    }
    else//when more than one node is present in the list
    {
        printf("\nDeleted element is: %d",tail->info);//printing the deleted node's element
        tail->prev->next=start;//second last node is pointing to the first node
        start->prev=tail->prev; //first node's prev is now pointing the second last node
        tail=tail->prev;//tail is pointing second last node
    }
}
void del_pos()//for deleting the user defined node  from the list
{
    if(start==NULL)//when no nodes exits in  the list
    {
        printf("\nList is not created");
        return;
    }
    int pos;
    printf("Enter the position of the node: ");
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
            if(ptr==tail->next)//this will execute when entered position is not in the list
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
            ptr->prev->next=ptr->next;//entered position's previous node's next is pointing the next node of 
			//entered position
            ptr->next->prev=ptr->prev;//entered position's next node's prev pointer is pointing to previous
			// node of the entered position
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
        int count=1;//initialize count as 1 because we can't traverse the list upto the last node
        while(ptr!=tail)//traverse upto the second last node of the list
        {
            count+=1;//increasing the value for every iteration
            ptr=ptr->next;
        }
        printf("Length of the list is: %d",count);//printing the count value
    }
}