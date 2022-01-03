//Selection sort

#include<stdio.h>
#include<conio.h>
int arr[50],n;
void selection()
{
	int temp,i,j,imin;
	for(i=0;i<n;i++)
	{
		imin=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[imin])
				imin=j;
			temp=arr[imin];
			arr[imin]=arr[i];
			arr[i]=temp;
		}
	}
}
void main()
{
	int i;
	clrscr();
	printf("Enter the number of the array: ");
	scanf("%d",&n);
	printf("Enter the elements of the array: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	selection();
	printf("The sorted array: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\nThank you!!");
	getch();
}
