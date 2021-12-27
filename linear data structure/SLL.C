#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
}*head;
struct node *create(int item)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=item;
	ptr->next=NULL;
	return(ptr);
}
void insert_beg()
{
	int item;
	struct node *ptr;
	printf("Enter the element: ");
	scanf("%d",&item);
	ptr=create(item);
	if(head==NULL)
		head=ptr;
	else
	{
		ptr->next=head;
		head=ptr;
	}
	printf("The element is inserted successfully");
}
void insert_mid()
{
	int pos,item;
	int c=0,i;
	struct node *ptr=head;
	struct node *temp;
	while(ptr!=NULL)
	{
		c++;
		ptr=ptr->next;
	}
	printf("Enter the location: ");
	scanf("%d",&pos);
	if(pos<=c)
	{
		ptr=head;
		printf("Enter the element: ");
		scanf("%d",&item);
		temp=create(item);
		for(i=1;i<=pos;i++)
		{
		       ptr=ptr->next;
		}
		temp->next=ptr->next;
		ptr->next=temp;
		printf("Element inserted successfully");
	}
	else
		printf("No such location");
}
void insert_end()
{
	int item;
	struct node *ptr,*temp;
	printf("Enter the element: ");
	scanf("%d",&item);
	ptr=create(item);
	temp=head;
	if(temp==NULL)
		head=ptr;
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=ptr;
	}
	printf("Element is inserted successfully");
}
void delete_beg()
{
	int item;
	if(head==NULL)
		printf("No elements in the list");
	else
	{
		item=head->data;
		head=head->next;
		printf("%d is deleted successfully",item);
	}
}
void delete_mid()
{
	int item,d=0;
	struct node *ptr,*temp;
	printf("Enter the item to be deleted: ");
	scanf("%d",&item);
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->next->data==item)
		{
			d=1;
			break;
		}
		ptr=ptr->next;
	}
	if(d==1)
	{
		temp=ptr->next;
		ptr->next=temp->next;
		free(temp);
		printf("Deleted successfully");
	}
	else
		printf("No such element");
}
void delete_end()
{
	int item;
	struct node *ptr;
	if(head==NULL)
		printf("No elements in the list");
	else
	{
		ptr=head;
		while(ptr->next->next!=NULL)
			ptr=ptr->next;
		item=ptr->next->data;
		ptr->next=NULL;
		printf("%d is deleted successfully",item);
	}
}
void display()
{
	struct node *ptr=head;
	if(ptr==NULL)
		printf("No elements");
	else
	{
		printf("The elements in the list: ");
		while(ptr->next!=NULL)
		{
			printf("%d->",ptr->data);
			ptr=ptr->next;
		}
		printf("%d",ptr->data);
	}
}
void main()
{
	int choice,ch;
	clrscr();
	do
	{
		printf("\t\t\tMain Menu");
		printf("\n1.Insert at beg\n2.Insert at specific location\n3.Insert at end\n4.Delete at beg\n5.Delete at specific location\n6.Delete at end\n7.Display");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert_beg();
				break;
			case 2:
				insert_mid();
				break;
			case 3:
				insert_end();
				break;
			case 4:
				delete_beg();
				break;
			case 5:
				delete_mid();
				break;
			case 6:
				delete_end();
				break;
			case 7:
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