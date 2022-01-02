//Bubble sort

#include<stdio.h>
#include<conio.h>
int arr[50],n;
void bubble()
{
	int i,temp,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		if(arr[j+1]<arr[j])
		{
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
	}
}
void main()
{
	int i;
	clrscr();
	printf("Enter the number of the elements in array: ");
	scanf("%d",&n);
	printf("Enter the elements of the array: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	bubble();
	printf("The sorted array: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\nThank you!!");
	getch();
}