//Graph representation

#include<stdio.h>
#include<conio.h>
struct node
{
	int value;
	struct node *next;
}*list[50];
int adjmatrix[50][50],value[50],n;
void input()
{
	int i,j;
	printf("Enter the number of the vertices: ");
	scanf("%d",&n);
	printf("Enter the value of the vertices: ");
	for(i=0;i<n;i++)
		scanf("%d",&value[i]);
	printf("If there exist an edge between two vertices enter1 else 0:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d-%d  ",value[i],value[j]);
			scanf("%d",&adjmatrix[i][j]);
		}
	}
}
void print_adjmatrix()
{
	int i,j;
	printf("   ");
	for(i=0;i<n;i++)
		printf("%d  ",value[i]);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",value[i]);
		for(j=0;j<n;j++)
			printf("%d  ",adjmatrix[i][j]);
		printf("\n");
      }
}
void adjlist()
{
	struct node *ptr,*ptr1;
	int i,j;
	for(i=0;i<n;i++)
	{
		list[i]=(struct node*)malloc(sizeof(struct node));
		for(j=0;j<n;j++)
		{
			if(j==0)
			{
				list[i]->value=value[i];
				list[i]->next=NULL;
				ptr1=list[i];
			}
			if(adjmatrix[i][j]==1)
			{
				ptr=(struct node*)malloc(sizeof(struct node));
				ptr->value=value[j];
				ptr->next=NULL;
				ptr1->next=ptr;
				ptr1=ptr;
			}
		}
	}
}
void print_adjlist()
{
	struct node *ptr;
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d->",list[i]->value);
		ptr=list[i];
		if(ptr->next!=NULL)
		{
			ptr=ptr->next;
			while(ptr->next!=NULL)
			{
				printf("%d->",ptr->value);
				ptr=ptr->next;
			}
			printf("%d",ptr->value);
		}
		printf("\n");
	}
}
void main()
{
	printf("\t\tRepresentation of Graph\n");
	input();
	adjlist();
	printf("\nThe adjacent matrix:\n");
	print_adjmatrix();
	printf("\nThe adjacency list: \n");
	print_adjlist();
	getch();
}