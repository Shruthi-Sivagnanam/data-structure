#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
}*front,*rear;
void enqueue()
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element: ");
	scanf("%d",&ptr->data);
	ptr->next=NULL;
	if(rear==NULL)
	{
		front=ptr;
		rear=ptr;
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
	}
	printf("Element inserted successfully");
}
void dequeue()
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	if(front==NULL)
		printf("No elements in the queue");
	else if(front==rear)
	{
		ptr=front;
		front=NULL;
		rear=NULL;
		printf("%d is deleted successfully",ptr->data);
		free(ptr);
	}
	else
	{
		ptr=front;
		front=front->next;
		printf("%d is deleted successfully",ptr->data);
		free(ptr);
	}
}
void display()
{
	struct node *ptr=front;
	if(front==NULL)
		printf("No elements");
	else
	{
		printf("The elements in the queue: ");
		while(ptr->next!=NULL)
		{
			printf("%d->",ptr->data);
			ptr=ptr->next;
		}
		printf("%d",ptr ->data);
	}
}
void main()
{
	int choice,ch;
	clrscr();
	do
	{
		printf("\t\t\tMain Menu");
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default:
				printf("Wrong choice!!");
		}
		printf("\nDo you want to continue?<0/1>: ");
		scanf("%d",&ch);
	}while(ch==1);
	printf("Thank you!!");
	getch();
}
