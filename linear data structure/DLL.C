//Doubly linked list

#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*head;
struct node *create()
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter the item: ");
	scanf("%d",&ptr->data);
	ptr->next=NULL;
	ptr->prev=NULL;
	return(ptr);
}
void insert_beg()
{
	struct node *ptr=create();
	if(head==NULL)
		head=ptr;
	else
	{
		ptr->next=head;
		head->prev=ptr;
		head=ptr;
	}
	printf("Element inserted successfully");
}
int get_noofnodes()
{
	int c=0;
	struct node *ptr=head;
	while(ptr!=NULL)
	{
		c++;
		ptr=ptr->next;
	}
	return(c);
}
void insert_mid()
{
	int pos;
	int c=0;
	struct node *ptr;
	struct node *temp=head;
	printf("Enter the location: ");
	scanf("%d",&pos);
	if(head==NULL)
	{
		ptr=create();
		printf("Element inserted successfully<1St element>");
		return;
	}
	if(pos>get_noofnodes())
	{
		printf("No such Loacation!!");
		return;
	}
	else
	{
		ptr=create();
		while(temp!=NULL&&pos!=(c-1))
		{
			c++;
			temp=temp->next;
		}
		ptr->prev=temp;
		ptr->next=temp->next;
		temp->next=ptr;
		temp->next->prev=ptr;
		printf("Element inserted successfully");
	}
}
void insert_end()
{
	struct node *ptr=create();
	struct node *temp=head;
	if(head==NULL)
		head=ptr;
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=ptr;
		ptr->prev=temp;
	}
	printf("Element inserted successfully");
}
void delete_beg()
{
	int item;
	if(head==NULL)
	{
		printf("No elements in the list");
		return;
	}
	else
	{
		item=head->data;
		head=head->next;
		head->prev=NULL;
		printf("%d is deleted successfully",item);
	}
}
void delete_mid()
{
	int item;
	int c=0;
	struct node *temp=head;
	if(head==NULL)
	{
		printf("No elements in the list");
		return;
	}
	else
	{
		printf("Enter the item to be deleted: ");
		scanf("%d",&item);
		while(temp!=NULL)
		{
			if(temp->data==item)
			{
				c=1;
				break;
			}
			temp=temp->next;
		}
	}
	if(c==1)
	{
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
		printf("Element deleted successfully");
	}
	else
		printf("No such element");
}
void delete_end()
{
	struct node *ptr=head;
	struct node *temp;
	if(head==NULL)
		printf("No elements in the list");
	else
	{
		while(ptr->next!=NULL)
			ptr=ptr->next;
		temp=ptr;
		ptr->prev->next=NULL;
		printf("%d is deleted successfully",temp->data);
		free(temp);
	}
}
void display()
{
	struct node *ptr=head;
	if(head==NULL)
		printf("No elements in the list");
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
		printf("\n1.Insert at beg\n2.Insert at mid\n3.Insert at end\n4.Delete at beg\n5.Delete at mid\n6.Delete at end\n7.Display");
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
		printf("\nDo yopu want to continue?<0/1>: ");
		scanf("%d",&ch);
	}while(ch==1);
	printf("Thank you!!");
	getch();
}
