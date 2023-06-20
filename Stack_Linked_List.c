                    /*      STACK IMPLEMENTATION USING LINKED LIST    */
#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void peek();
void display();
struct node
{
    int info;
    struct node *next;
};
struct node *top=NULL;
int main()
{
    int choice=0;
    while(choice!=5)
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nWrong choice");
                break;
        }
    }
    return 0;
}
void push()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nMemory allocation failed");
        return;
    }
    printf("\nEnter the data value for the node: ");
    scanf("%d",&temp->info);
    temp->next=top;
    top=temp;
}
void pop()
{
    if(top==NULL)
    {
        printf("\nStack is empty");
        return;
    }
    else
    {
        printf("\nDeleted topmost element of the stack is: %d",top->info);
        top=top->next;
    }
}
void peek()
{
    
    if(top==NULL)
    {
        printf("\nStack is empty");
        return;
    }
    else
    {
        printf("\nTopmost element of the stack is: %d",top->info);
    }
}
void display()
{
    if(top==NULL)
    {
        printf("\nStack is empty");
        return;
    }
    else
    {
        struct node *ptr=top;
        printf("\nStack elements are: ");
        while(ptr!=NULL)
        {
            printf("%d  ",ptr->info);
            ptr=ptr->next;
        }
    }
}