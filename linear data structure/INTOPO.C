//Infix to postfix conversion

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
char stack[20];
int top=-1;
void push(char x)
{
	top++;
	stack[top]=x;
}
char pop()
{
	return(stack[top--]);
}
int priority(char x)
{
	if(x=='(')
		return(0);
	else if(x=='+'||x=='-')
		return(1);
	else if(x=='*'||x=='/')
		return(2);
	else if(x=='^')
		return(3);
	return(-1);
}
void main()
{
	char exp[20];
	char *e;
	char x;
	clrscr();
	printf("\t\tConversion of infix to postfix");
	printf("\nEnter the infix expression: ");
	scanf("%s",exp);
	e=exp;
	while(*e!='\0')
	{
		if(isalnum(*e))
			printf("%c",*e);
		else if(*e=='(')
			push(*e);
		else if(*e==')')
		{
			while((x=pop())!='(')
				printf("%c",x);
		}
		else
		{
			while(priority(stack[top])>=priority(*e))
				printf("%c",pop());
			push(*e);
		}
		e++;
	}
	while(top!=-1)
		printf("%c",pop());
	printf("\nThank you!!");
	getch();
}
