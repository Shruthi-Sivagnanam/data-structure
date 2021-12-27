//Postfix expression-Evaluation

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define size 50
char arr[size];
int stack[size],top=-1;
int c=0;
void push(int item)
{
	int num;
	if(c==1)
	{
		num=pop();
		top++;
		stack[top]=item+10*num;
	}
	else
	{
		top++;
		stack[top]=item;
		c=1;
	}
}
int pop()
{
	int item=-1;
	if(top==-1)
		printf("Stack underflow");
	else
	{
		item=stack[top];
		top--;
	}
	return(item);
}
void main()
{
	int d=0;
	int i=0,item;
	clrscr();
	printf("\t\tEvaluation of postfix Expression\n");
	printf("Enter the expression: ");
	fgets(arr,100,stdin);
	while(arr[i]!='\n')
	{
		if(isdigit(arr[i]))
		{
			item=arr[i]-48;
			push(item);
			c=1;
		}
		else if(arr[i]==' ')
			c=0;
		else
		{
			int op2=pop();
			int op1=pop();
			switch(arr[i])
			{
				case '*':
					push(op2*op1);
					break;
				case '/':
					push(op2/op1);
					break;
				case '+':
					push(op2+op1);
					break;
				case '-':
					push(op2-op1);
					break;
				case '^':
					push(pow(op2,op1));
					break;
				default:
					printf("Wrong operator!");
					d=1;
			}
		}
		if(d==1)
			break;
		i++;
	}
	if(d==1)
		printf("Expression invalid");
	else
	{
		printf("Result: %d",pop());
	}
	printf("\nThank you!!");
	getch();
}
