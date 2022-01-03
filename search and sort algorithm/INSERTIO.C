//Insertion sort

#include<stdio.h>
#include<conio.h>
int arr[50],n;
void insertion()
{
	int i,curr,j;
	for(i=1;i<=n;i++)
	{
		curr=arr[i];
		for(j=i-1;j>=0&&arr[j]>curr;j--)
			arr[j+1]=arr[j];
		arr[j+1]=curr;
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
	insertion();
	printf("The sorted array: ");
	for(i=1;i<=n;i++)
		printf("%d ",arr[i]);
	printf("\nThank you!!");
	getch();
}