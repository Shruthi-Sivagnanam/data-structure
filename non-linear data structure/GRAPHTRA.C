//Graph traversal

#include<stdio.h>
#include<conio.h>
int adjmatrix[50][50],visited[50],value[50];
int stack[50],queue[50];
int top=-1,front=-1,rear=-1;
void push(int ele)
{
		top++;
		ele=value[ele];
		stack[top]=ele;

}
int pop()
{
	int item;
	if(top==-1)
		item=-1;
	else
	{
		item=stack[top];
		top--;
	}
	return(item);
}
void dfs(int s,int n)
{
	int i,k,x=0;
	push(s);
	visited[s]=1;
	k=pop();
	if(k!=-1)
		printf("%d ",k);
	while(k!=-1)
	{
		for(i=0;i<n;i++)
		{
			if((adjmatrix[x][i]!=0)&&visited[i]==0)
			{
				push(i);
				visited[i]=1;
			}
			k=pop();
			if(k!=-1)
				printf("%d ",k);
		}
	}
	for(i=0;i<n;i++)
		if(visited[i]==0)
			dfs(i,n);
}
void graph_representation(int n)
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
void main()
{
	int n,i,j;
	clrscr();
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	printf("Enter the value of vertices: ");
	for(i=0;i<n;i++)
		scanf("%d",&value[i]);
	for(i=0;i<n;i++)
		visited[i]=0;
	printf("Enter 1 if there exist an edge else 0:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d-%d ",value[i],value[j]);
			scanf("%d",&adjmatrix[i][j]);
		}
	}
	graph_representation(n);
	printf("\nDfs: ");
	dfs(0,n);
	getch();
}