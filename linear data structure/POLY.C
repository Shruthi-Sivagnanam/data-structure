#include<stdio.h>
#include<conio.h>
struct node
{
	int coeff;
	int power;
	struct node *next;
}*p,*r,*ans;
struct node *input(int n)
{
	struct node *head=(struct node *)malloc(sizeof(struct node));
	struct node *ptr1=(struct node*)malloc(sizeof(struct node));
	int i;
	printf("Enter the coeff and power: <in order> ");
	for(i=0;i<n;i++)
	{
		struct node *ptr=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&ptr->coeff);
		scanf("%d",&ptr->power);
		if(i==0)
		{
			ptr->next=NULL;
			head=ptr;
			ptr1=ptr;
			continue;
		}
		ptr->next=NULL;
		ptr1->next=ptr;
		ptr1=ptr;
	}
	return(head);
}
void display(struct node *ptr)
{
	struct node *temp=ptr;
	if(temp==NULL)
		printf("No polynomial");
	else
	{
		while(temp->next!=NULL)
		{
			printf("%dx^%d+",temp->coeff,temp->power);
			temp=temp->next;
		}
		printf("%dx^%d",temp->coeff,temp->power);
	}
}
struct node *add()
{
	struct node *temp1=p;
	struct node *temp2=r;
	struct node *ans1;
	struct node *ptr,*ans2;
	int i=0;
	while(temp1!=NULL&&temp2!=NULL)
	{
		ans1=(struct node*)malloc(sizeof(struct node));
		if(temp1->power==temp2->power)
		{
			ans1->power=temp1->power;
			ans1->coeff=temp1->coeff+temp2->coeff;
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else if(temp1->power>temp2->power)
		{
			ans1->power=temp1->power;
			ans1->coeff=temp1->coeff;
			temp1=temp1->next;
		}
		else
		{
			ans1->power=temp2->power;
			ans1->coeff=temp2->coeff;
			temp2=temp2->next;
		}
		if(i==0)
		{
			i=1;
			ans1->next=NULL;
			ans2=ans1;
			ptr=ans1;
			continue;
		}
		ans1->next=NULL;
		ans2->next=ans1;
		ans2=ans1;
	}
	if(temp1!=NULL)
	{
		while(temp1!=NULL)
		{       ans1=(struct node*)malloc(sizeof(struct node));
			ans1->power=temp1->power;
			ans1->coeff=temp1->coeff;
			temp1=temp1->next;
			ans2->next=ans1;
			ans2=ans1;
		}
	}
	if(temp2!=NULL)
	{
		while(temp2!=NULL)
		{
			ans1=(struct node*)malloc(sizeof(struct node));
			ans1->power=temp2->power;
			ans1->coeff=temp2->coeff;
			temp2=temp2->next;
			ans2->next=ans1;
			ans2=ans1;
		}
	}
	return(ptr);
}
struct node *sub()
{
	struct node *temp1=p;
	struct node *temp2=r;
	struct node *ans1;
	struct node *ptr,*ans2;
	int i=0;
	while(temp1!=NULL&&temp2!=NULL)
	{
		ans1=(struct node*)malloc(sizeof(struct node));
		if(temp1->power==temp2->power)
		{
			ans1->power=temp1->power;
			ans1->coeff=temp1->coeff-temp2->coeff;
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else if(temp1->power>temp2->power)
		{
			ans1->power=temp1->power;
			ans1->coeff=temp1->coeff;
			temp1=temp1->next;
		}
		else
		{
			ans1->power=temp2->power;
			ans1->coeff=temp2->coeff;
			temp2=temp2->next;
		}
		if(i==0)
		{
			i=1;
			ans1->next=NULL;
			ans2=ans1;
			ptr=ans1;
			continue;
		}
		ans1->next=NULL;
		ans2->next=ans1;
		ans2=ans1;
	}
	if(temp1!=NULL)
	{
		while(temp1!=NULL)
		{
			ans1=(struct node*)malloc(sizeof(struct node*));
			ans1->power=temp1->power;
			ans1->coeff=temp1->coeff;
			temp1=temp1->next;
			ans2->next=ans1;
			ans2=ans1;
		}
	}
	if(temp2!=NULL)
	{
		while(temp2!=NULL)
		{
			ans1=(struct node*)malloc(sizeof(struct node*));
			ans1->power=temp2->power;
			ans1->coeff=temp2->coeff;
			temp2=temp2->next;
			ans2->next=ans1;
			ans2=ans1;
		}
	}
	return(ptr);
}
void main()
{
	int n;
	clrscr();
	printf("Enter the number of the terms in the polynomial1: ");
	scanf("%d",&n);
	p=input(n);
	printf("Enter the number of the terms in the polynomial2: ");
	scanf("%d",&n);
	r=input(n);
	printf("The polynomial 1: ");
	display(p);
	printf("\nThe polynomial 2: ");
	display(r);
	ans=add();
	printf("\nThe result of addition: ");
	display(ans);
	ans=sub();
	printf("\nThe result of subtration: ");
	display(ans);
	getch();
}