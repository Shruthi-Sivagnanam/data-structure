#include<stdio.h>
#include<conio.h>
#define size 50
int arr[size];
int top=-1;
void push()
{
	int item;
	if(top==size-1)
		printf("Stack overflow\n");
	else
	{
		top++;
		printf("Enter the item: ");
		scanf("%d",&item);
		arr[top]=item;
		printf("Element insereted successfully\n");
	}
}
void pop()
{
	int item;
	if(top==-1)
		printf("Stack underflow\n");
	else
	{
		item=arr[top];
		top--;
		printf("%d is deleted\n",item);
	}
}
void display()
{
	int i;
	if(top==-1)
		printf("No elements in the stack");
	else
	{
		printf("The elements in the stack are: ");
		for(i=0;i<=top;i++)
			printf("%d ",arr[i]);
	}
	printf("\n");
}
void main()
{
	int choice,ch;
	clrscr();
	do
	{
		printf("\t\t\tMain Menu");
		printf("\n1.Push\n2.Pop\n3.Display\nEnter your choice: ");
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
				display();
				break;
			default:
				printf("Wron choice!!\n");
		}
		printf("Do you want to continue?<0/1>: ");
		scanf("%d",&ch);
	}while(ch==1);
	printf("Thank you!!");
	getch();
}