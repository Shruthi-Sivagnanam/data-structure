//Queue using array implementation

#include<stdio.h>
#include<conio.h>
#define size 50
int arr[size],front=-1,rear=-1;
void enqueue()
{
	int item;
	if(rear==size-1)
		printf("Queue overflow\n");
	else
	{
		printf("Enter the item: ");
		scanf("%d",&item);
		if(rear==-1)
		{
			front++;
			rear++;
			arr[rear]=item;
		}
		else
		{
			rear++;
			arr[rear]=item;
		}
		printf("Element inserted successfully\n");
	}
}
void dequeue()
{
	int item;
	if(front==-1)
		printf("Queue underflow\n");
	else
	{
		if(front==size-1)
		{
			item=arr[front];
			front=-1;
			rear=-1;
		}
		else
		{
			item=arr[front];
			front++;
		}
		printf("%d is deleted successfully\n",item);
	}
}
void display()
{
	int i;
	if(rear==-1)
		printf("No elements in the queue\n");
	else
	{
		printf("The elements in the queue are: ");
		for(i=front;i<=rear;i++)
			printf("%d ",arr[i]);
		printf("\n");
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
				printf("Wrong choice!!\n");
		}
		printf("Do you want to continue?<0/1>: ");
		scanf("%d",&ch);
	}while(ch==1);
	printf("Thank you!!");
	getch();
}
