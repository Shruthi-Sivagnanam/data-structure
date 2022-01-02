//Binary and linear search

#include<stdio.h>
#include<conio.h>
int arr[50],n;
void binary_search(int ele)
{
	int beg,mid,end,c=0;
	beg=0;
	end=n-1;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(arr[mid]==ele)
		{
			c=1;
			break;
		}
		else if(arr[mid]>ele)
			end=mid-1;
		else
			beg=mid+1;
	}
	if(c==1)
		printf("Element is found!! index: %d",mid);
	else
		printf("Element is not found!!");
}
void linear_search(int item)
{
	int i=0;
	int c=0;
	for(i=0;i<n;i++)
		if(arr[i]==item)
		 {
			c=1;
			break;
		 }
	if(c==1)
		printf("Element is found!! index: %d",i);
	else
		printf("Element is not found!!");
}
void get_input()
{
	int i;
	printf("Enter the number of elements of the array: ");
	scanf("%d",&n);
	printf("Enter the elements of the array: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
}
void main()
{
	int choice;
	int item;
	clrscr();
	printf("\t\t\tMain Menu");
	printf("\n1.Binary Search\n2.Linear Search\nEnter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			get_input();
			printf("Enter the item: ");
			scanf("%d",&item);
			binary_search(item);
			break;
		case 2:
			get_input();
			printf("Enter the item: ");
			scanf("%d",&item);
			linear_search(item);
			break;
		default:
			printf("Wrong choice!!");
	}
	printf("\nThank you!!");
	getch();
}