#include<stdio.h>
int main()
{
	int i,a[100],max,min,j,t,n;
	printf("enter the no.of elements: ");
	scanf("%d",&n);
	printf("enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	printf("sorting order is: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\nenter the mvalue: ");
	scanf("%d",&min);
	printf("enter the n value: ");
	scanf("%d",&max);
	printf("%dth min is %d",min,a[min-1]);
	printf("\n%dth max is: %d",max,a[n-max]);
}
