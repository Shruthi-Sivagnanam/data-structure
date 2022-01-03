//Radix sort

#include<stdio.h>
#include<conio.h>
int arr[50],n;
int b[10],b1[10][10];
int get_noofdigits()
{
	int i,count=0;
	int maxi=arr[0];
	for(i=0;i<n;i++)
		if(arr[i]>maxi)
			maxi=arr[i];
	while(maxi>0)
	{
		count++;
		maxi/=10;
	}
	return count;
}
void radix()
{
	int x=get_noofdigits();
	int pass,i,j,k;
	int divisor=1,r;
	for(pass=0;pass<x;pass++)
	{
		for(i=0;i<10;i++)
		{
			b[i]=0;

		}
		for(i=0;i<n;i++)
		{
			r=(arr[i]/divisor)%10;
			b1[r][b[r]]=arr[i];
			b[r]++;
		}
		i=0;
		for(k=0;k<n;k++)
		{
			for(j=0;j<b[k];j++)
			{
				arr[i]=b1[k][j];
				i++;
			}
		}
		divisor*=10;
		for(i=0;i<n;i++)
		printf("%d ",arr[i]);
		printf("\n");
		continue;
	}
}
void main()
{
	int i;
	clrscr();
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the elements of the array: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	radix();
	printf("The sorted array: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\nThank you!!");
	getch();
}