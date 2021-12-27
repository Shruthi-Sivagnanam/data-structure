//Stack using linked list

#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *prev;
}*top;
void push()
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element: ");
	scanf("%d",&ptr->data);
	ptr->prev=NULL;
	if(top==NULL)
		top=ptr;
	else
	{
		ptr->prev=top;
		top=ptr;
	}
	printf("Element inserted successfully");
}
void pop()
{
	struct node *temp;
	if(top==NULL)
		printf("Stack underflow!");
	else
	{
		temp=top;
		top=top->prev;
		printf("%d id deleted",temp->data);
		free(temp);
	}
}
void display()
{
	struct node *temp=top;
	if(temp==NULL)
	{
		printf("No elements!!");
		return;
	}
	printf("Elements in the stack: ");
	while(temp->prev!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->prev;
	}
	printf("%d",temp->data);
}
void main()
{
	int choice,ch;
	clrscr();
	do
	{
		printf("\t\t\tMain Menu\n");
		printf("1.Push\n2.Pop\n3.Display\nEnter your choice: ");
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
				printf("Wrong choice!!");
		}
		printf("\nDo you want to continue<0/1>: ");
		scanf("%d",&ch);
	}while(ch==1);
	printf("Thank you!!");
	getch();
}
