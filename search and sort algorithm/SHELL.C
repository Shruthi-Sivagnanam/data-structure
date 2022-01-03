//Shell sort

#include<stdio.h>
#include<conio.h>
int arr[50],n;
void shell()
{
	int i,j,gap,temp;
	for(gap=n/2;gap>0;gap=gap/2)
	{
		for(i=gap;i<n;i++)
		{
			temp=arr[i];
			for(j=i;j>=gap&&arr[j-gap]>temp;j-=gap)
				arr[j]=arr[j-gap];
			arr[j]=temp;
		}
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
	shell();
	printf("The sorted array: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\nThank you!!");
	getch();
}