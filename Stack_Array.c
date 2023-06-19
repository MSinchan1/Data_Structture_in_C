                                    /*      STACK IMPLEMENTATION USING ARRAY        */
#include<stdio.h>
#include<stdlib.h>
int stack[7];//Globaly declare the array with size
int top=-1;//Globally declare the top integer with initialized -1
//declared required functions
void push();
void pop();
void peek();
void display();
int main()
{//using switch case for the different choice
    int choice=0;
    while(choice!=5)
    {
        printf("\n1.Push");
        printf("\n2.Pull");
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
void push()//used for enter new data in the declared stack
{
    if(top==6)//when stack is full
    {
        printf("\nOverflow");
        return;
    }
    else//when atleast one element is present in the stack
    {
        top+=1;
        printf("\nEnter data: ");
        scanf("%d",&stack[top]);
    }
}
void pop()//used for delete stored data from declared stack
{
    if(top==-1)//when stack is full
    {
        printf("\nUnderflow");
        return;
    }
    else//when atleast one element is present in the stack
    {
        printf("\nDeleted element is : %d",stack[top]);//print the deleted data
        top-=1;
    }
}
void peek()//used for print the  stored topmost data from declared stack
{
    if(top==-1)//when stack is full
    {
        printf("\nStack is empty");
        return;
    }
    else//when stack is full
    {
        printf("\nTopmost element of the stack is : %d",stack[top]);
    }
}
void display()//used for printing the stored data in stack
{
    if(top==-1)//when stack is full
    {
        printf("\nStack is empty");
        return;
    }
    else//when stack is full
    {
        printf("\nStack elements are: ");
        /*for(int i=top;i>=0;i--)//used for acces the topmost element of the stack
        {
            printf("%d  ",stack[top]);
            top-=1;
        }
        */
        for(int i=0;i<=top;i++)//used for acces the first element of the stack
        {
            printf("%d  ",stack[i]);
        }
    }
}