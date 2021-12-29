//Priority Queue using heaps(max)

#include<stdio.h>
#include<conio.h>
int arr[10],size=0;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(int i)
{
	int left=2*i;
	int right=2*i+1;
	int largest;
	if(left<=size && arr[left]>arr[i])
		largest=left;
	else
		largest=i;
	if(right<=size && arr[right]>arr[left])
		largest=right;
	if(largest!=i)
	{
		swap(&arr[i],&arr[largest]);
		heapify(largest);
	}
}
void insert()
{
	int item,i;
	printf("Enter the item: ");
	scanf("%d",&item);
	arr[size]=item;
	size++;
	for(i=0;i<size;i++)
		heapify(i);
	printf("Element inserted successfully");
}
void deleted()
{
	int item,i;
	item=arr[0];
	swap(&arr[0],&arr[size-1]);
	size--;
	for(i=0;i<size;i++)
		heapify(i);
	printf("%d is deleted",item);
}
void display()
{
	int i;
	if(size==0)
	{
		printf("No elements in the heap");
		return;
	}
	printf("The elements in the heaps: ");
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
}
void main()
{
	int choice,ch;
	clrscr();
	printf("\tImplemetation of priority queue using Max heap\n");
	do
	{
		printf("\t\t\tMain Menu");
		printf("\n1.Insert\n2.Delete\n3.Display\nEnter your choice: ");
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
				display();
				break;
			default:
				printf("Wrong choice!!");
		}
		printf("\nDo you want to continue?<0/1>?: ");
		scanf("%d",&ch);
	}while(ch==1);
	printf("Thank you!!");
	getch();
}