//Binary search tree 
#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
}*tree;
struct node *create(struct node *ptr,int ele)
{
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=ele;
	ptr->left=NULL;
	ptr->right=NULL;
	return(ptr);
}
struct node *insert(struct node *root,int ele)
{
	if(root==NULL)
	{
		root=create(root,ele);
		printf("Element inserted sucessfully");
	}
	else if(ele>root->data)
		root->right=insert(root->right,ele);
	else if(ele<root->data)
		root->left=insert(root->left,ele);
	else if(ele==root->data)
		printf("Duplication of element is not possible");
	return(root);
}
struct node *findmin(struct node *t)
{
	if(t==NULL)
		return(NULL);
	else if(t->left==NULL)
		return(t);
	else
		return(findmin(t->left));
}
struct node *del(struct node *root,int ele)
{
	int c=0;
	struct node *temp;
	if(root==NULL)
	{
		printf("Element not found!!");
		c=1;
	}
	else if(ele<root->data)
		root->left=del(root->left,ele);
	else if(ele>root->data)
		root->right=del(root->right,ele);
	else
	{
		if(root->right==NULL)
		{
			struct node *temp=root->left;
			free(root);
			return(temp);
		}
		else if(root->left==NULL)
		{
			struct node *temp=root->right;
			free(root);
			return(temp);
		}
		temp=findmin(root->right);
		root->data=temp->data;
		root->right=del(root->right,temp->data);
	}
	if(c==0)
		printf("Element deleted successfully");
	return(root);
}
struct node *findmax(struct node *t)
{
	if(t==NULL)
		return(NULL);
	else if(t->right==NULL)
		return(t);
	else
		return(findmax(t->right));
}
void find(struct node *t,int item)
{
	if(t==NULL)
	{
		printf("No such element!!");
		return;
	}
	else
	{
		if(item>t->data)
			find(t->right,item);
		else if(item<t->data)
			find(t->left,item);
		else
		{
			printf("Element found!!");
			return;
		}
	}
}
void preorder(struct node *t)
{
	if(t!=NULL)
	{
		printf("%d ",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
void inorder(struct node *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%d ",t->data);
		inorder(t->right);
	}
}
void postorder(struct node *t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("%d ",t->data);
	}
}
void main()
{
	int choice,ch;
	struct node *temp;
	int item;
	clrscr();
	do
	{
		printf("\t\t\tMain Menu");
		printf("\n1.Insert\n2.Delete\n3.Find\n4.FindMin\n5.FindMax\n6.Preorder\n7.Inorder\n8.Postorder\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the item: ");
				scanf("%d",&item);
				tree=insert(tree,item);
				break;
			case 2:
				printf("Enter the item: ");
				scanf("%d",&item);
				tree=del(tree,item);
				break;
			case 3:
				printf("Enter the item: ");
				scanf("%d",&item);
				find(tree,item);
				break;
			case 4:
				temp=findmin(tree);
				printf("%d is min",temp->data);
				break;
			case 5:
				temp=findmax(tree);
				printf("%d is max",temp->data);
				break;
			case 6:
				preorder(tree);
				break;
			case 7:
				inorder(tree);
				break;
			case 8:
				postorder(tree);
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
