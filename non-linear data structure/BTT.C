//Binary Tree Traversal
#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *right;
	struct node *left;
};
int count=1;
struct node *insert(struct node *root,int digit)
{
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		root->data=digit;
		root->right=NULL;
		root->left=NULL;
		count++;
	}
	else if(count%2==0)
	{
		if(root->right==NULL)
			root->right=insert(root->right,digit);
		else
			root->left=insert(root->left,digit);
	}
	else
	{
		if(root->left==NULL)
			root->left=insert(root->left,digit);
		else
			root->right=insert(root->right,digit);
	}
	return(root);
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
	int digit;
	struct node *root=NULL;
	printf("\t\tBinary Tree Traversal");
	printf("\nEnter the nodes value: To quit enter-1 ");
	scanf("%d",&digit);
	while(digit!=-1)
	{
		root=insert(root,digit);
		scanf("%d",&digit);
	}
	printf("Preorder: ");
	preorder(root);
	printf("\nInorder: ");
	inorder(root);
	printf("\nPostorder: ");
	postorder(root);
	getch();
}