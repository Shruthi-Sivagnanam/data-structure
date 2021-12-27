#include<stdio.h>
#include<conio.h>
#define size 20
int arr[size];
int n;
void create()
{
	int i;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements of the array: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Array created sucessfully\n");
}
void insert()
{
	int pos;
	int i;
	printf("Enter the location: ");
	scanf("%d",&pos);
	if(pos<n&&pos>=0)
	{
		n++;
		for(i=n;i>pos;i--)
			arr[i]=arr[i-1];
		printf("Enter the item: ");
		scanf("%d",&arr[i]);
		printf("Element inserted successfully\n");
	}
	else if(pos<size&&pos==n)
	{
		n++;
		printf("Enter the item: ");
		scanf("%d",&arr[pos]);
		printf("Element inserted successfully\n");
	}
	else
	{
		printf("No such location\n");
	}
}
void deleted()
{
	int item,d=0,i;
	printf("Enter the item to be deleted: ");
	scanf("%d",&item);
	for(i=0;i<n;i++)
		if(arr[i]==item)
		{
			d=1;
			break;
		}
	if(d==1)
	{
		for(;i<n;i++)
			arr[i]=arr[i+1];
		n--;
		printf("Deleted successfully\n");
	}
	else
		printf("No such elements\n");
}
void display()
{
	int i;
	printf("The elements in the list: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
void find()
{
	int item;
	int i,d=0;
	printf("Enter the item to be searched: ");
	scanf("%d",&item);
	for(i=0;i<n;i++)
	{
		if(arr[i]==item)
		{
			d=1;
			break;
		}
	}
	if(d==1)
		printf("Element found!!-position: %d\n",i);
	else
		printf("Element not found!!\n");
}
void main()
{
	int choice,ch;
	clrscr();
	printf("\t\t\tArray Implementation of list\n");
	create();
	do
	{
		printf("\t\t\tMain Menu\n");
		printf("1.Insert\n2.Delete\n3.Search\n4.Display\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				deleted();
				break;
			case 3:
				find();
				break;
			case 4:
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