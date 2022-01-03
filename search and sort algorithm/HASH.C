#include<stdio.h>
#include<conio.h>
int a[50],n;
int hash(int key)
{
	return(key%n);
}
void insert()
{
	int item,c=0;
	int i,index,temp;
	printf("Enter the element to be inserted: ");
	scanf("%d",&item);
	temp=item;
	for(i=0;i<n;i++)
	{
		index=hash(temp);
		if(a[index]!=-1)
			temp=item+i+1;//linear probing
			//temp=item+(i*i);//quadratic probing
		else
		{
			a[index]=item;
			c=1;
			break;
		}
	}
	if(c==1)
		printf("The element is inserted successfully");
	else
		printf("The element is not inserted");
}
void deleted()
{
	int item,index,i,temp,c=0;
	printf("Enter the item to be deleted: ");
	scanf("%d",&item);
	temp=index;
	for(i=0;i<n;i++)
	{
		index=hash(temp);
		if(a[index]!=item)
			temp=item+i;//linear probing
			//temp=item+(i*i);//quadratic probing
		else
		{
			c=1;
			a[index]=-1;
			break;
		}
	}
	if(c==1)
		printf("The element is deleted successfully");
	else
		printf("The element is not found!!");
}
void search()
{
	int item,index,i,temp,c=0;
	printf("Enter the item to be searched: ");
	scanf("%d",&item);
	temp=index;
	for(i=0;i<n;i++)
	{
		index=hash(temp);
		if(a[index]!=item)
			temp=item+i+1;
		else
		{
			c=1;
			break;
		}
	}
	if(c==1)
		printf("The element is found");
	else
		printf("The element is not found!!");
}
void display()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==-1)
			printf("-- ");
		else
			printf("%d ",a[i]);
	}
}
void main()
{
	int choice,ch,i;
	clrscr();
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		a[i]=-1;
	do
	{
		printf("\t\tMain Menu");
		printf("\n1.Insert\n2.Search\n3.Delete\n4.Display");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				search();
				break;
			case 3:
				deleted();
				break;
			case 4:
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
