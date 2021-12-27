//Circular Queue

#include<stdio.h>
#include<conio.h>
#define size 50
int arr[size];
int n,front=-1,rear=-1;
void enqueue(int item)
{
	if(rear==-1)
	{
		front++;
		rear++;
		arr[rear]=item;
		printf("Element inserted successfully");
	}
	else if(front==(rear+1)%n)
		printf("Queue overflow!!");
	else
	{
		rear=(rear+1)%n;
		arr[rear]=item;
		printf("Element inserted successfully");
	}
}
void dequeue()
{
	int item;
	if(front==-1)
		printf("Queue underflow!!");
	else
	{
		if(front==rear)
		{
			item=arr[front];
			front=-1;
			rear=-1;
		}
		else
		{
			item=arr[front];
			front=(front+1)%n;
		}
		printf("%d is deleted successfully",item);
	}
}
void display()
{
	int i,j;
	if(front==-1)
		printf("Queue underflow!!");
	else if(front>rear)
	{
		printf("The elements in the queue: ");
		for(i=front;i<n;i++)
			printf("%d ",arr[i]);
		for(j=0;j<=rear;j++)
			printf("%d ",arr[j]);
	}
	else
	{
		printf("The elements in the queue: ");
		for(i=front;i<=rear;i++)
			printf("%d ",arr[i]);
	}
}
void main()
{
	int choice,ch;
	int item;
	clrscr();
	printf("\t\t\tCircular Queue");
	printf("\nEnter the size of the array: ");
	scanf("%d",&n);
	do
	{
		printf("\t\t\tMain Menu");
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the item: ");
				scanf("%d",&item);
				enqueue(item);
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
		printf("\nDo you want to continue<0/1>: ");
		scanf("%d",&ch);
	}while(ch==1);
	printf("Thank you!!");
	getch();
}
