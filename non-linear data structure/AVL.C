//Avl Tree implementation

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *right;
	struct node *left;
	int height;
};
int height(struct node *t)
{
	if(t==NULL)
		return 0;
	else
		return t->height;
}
int maxi(int a,int b)
{
	if(a<b)
		return(b);
	else
		return(a);
}
struct node *create(int key)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=key;
	ptr->right=NULL;
	ptr->left=NULL;
	ptr->height=1;
	return(ptr);
}
struct node *rightrotate(struct node *ptr)
{
	struct node *ptr1=ptr->left;
	struct node *temp=ptr1->right;
	ptr1->right=ptr;
	ptr->left=temp;
	ptr->height=maxi(height(ptr->left),height(ptr->right))+1;
	ptr1->height=maxi(height(ptr1->left),height(ptr->right))+1;
	return(ptr1);
}
struct node *leftrotate(struct node *ptr)
{
	struct node *ptr1=ptr->right;
	struct node *temp=ptr1->left;
	ptr1->left=ptr;
	ptr->right=temp;
	ptr->height=maxi(height(ptr->left),height(ptr->right))+1;
	ptr1->height=maxi(height(ptr1->left),height(ptr1->right))+1;
	return(ptr1);
}
int getBalanceFactor(struct node *n)
{
	if(n==NULL)
		return(0);
	return(height(n->left) - height(n->right));
}
struct node *insert(struct node *ptr,int key)
{
	int balance;
	if(ptr==NULL)
		return(create(key));
	if(key<ptr->data)
		ptr->left=insert(ptr->left,key);
	else if(key>ptr->data)
		ptr->right=insert(ptr->right,key);
	else
		return(ptr);
	ptr->height=1+maxi(height(ptr->left),height(ptr->right));
	balance=getBalanceFactor(ptr);
	if(balance<-1 && key>ptr->right->data)
		return(leftrotate(ptr));
	if(balance>1&&key<ptr->left->data)
		return(rightrotate(ptr));
	if(balance>1&&key>ptr->left->data)
	{
		ptr->left=leftrotate(ptr->left);
		return(rightrotate(ptr));
	}
	if(balance<-1 && key<ptr->right->data)
	{
		ptr->right=rightrotate(ptr->right);
		return(leftrotate(ptr));
	}
	return(ptr);
}
struct node *minvalue(struct node *ptr)
{
	struct node *current=ptr;
	while(current->left!=NULL)
		current=current->left;
	return(current);
}
struct node *deleted(struct node *ptr,int key)
{
	int balance;
	if(ptr==NULL)
		return(ptr);
	if(key<ptr->data)
		ptr->left=deleted(ptr->left,key);
	else if(key>ptr->data)
		ptr->right=deleted(ptr->right,key);
	else
	{
		if(ptr->left==NULL||ptr->right==NULL)
		{
			struct node *temp=ptr->left?ptr->left:ptr->right;
			if(temp==NULL)
			{
				temp=ptr;
				ptr=NULL;
			}
			else
				*ptr=*temp;
				free(temp);
		}
		else
		{
			struct node *temp=minvalue(ptr->right);
			ptr->data=temp->data;
			ptr->right=deleted(ptr->right,temp->data);
		}
	}
	if(ptr==NULL)
		return(ptr);
	ptr->height=1+maxi(height(ptr->left),height(ptr->right));
	balance=getBalanceFactor(ptr);
	if(balance>1 && getBalanceFactor(ptr->left)>=0)
		return(rightrotate(ptr));
	if(balance>1 && getBalanceFactor(ptr->left)<0)
	{
		ptr->left=leftrotate(ptr->left);
		return(rightrotate(ptr));
	}
	if(balance<-1 && getBalanceFactor(ptr->right)<=0)
		return leftrotate(ptr);
	if(balance<-1 && getBalanceFactor(ptr->right)>0)
	{
		ptr->right=rightrotate(ptr->right);
		return(ptr);
	}
	return(ptr);
}
void preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
void main()
{
	int choice,ch,item;
	struct node *root=NULL;
	do
	{
		printf("\t\t\tAvl Tree\n");
		printf("\n1.Insert\n2.Delete\n3.Display\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the element: ");
				scanf("%d",&item);
				root=insert(root,item);
				break;
			case 2:
				printf("Enter the element: ");
				scanf("%d",&item);
				root=deleted(root,item);
				break;
			case 3:
				printf("The elements in the tree : ");
				preorder(root);
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