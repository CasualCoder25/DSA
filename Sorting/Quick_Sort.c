#include<stdio.h>
#include<stdlib.h>
int median3(int *arr,int l,int r)
{
	int m=(l+r)/2,temp;
	if(arr[l]>arr[m])
	{
		temp=arr[l];
		arr[l]=arr[m];
		arr[m]=temp;
	}
	if(arr[l]>arr[r])
	{
		temp=arr[l];
		arr[l]=arr[r];
		arr[r]=temp;
	}
	if(arr[m]>arr[r])
	{
		temp=arr[r];
		arr[r]=arr[m];
		arr[m]=temp;
	}
	temp=arr[r];
	arr[r]=arr[m];
	arr[m]=temp;
	return arr[r];
}
void QuickSort(int *arr,int l,int r)
{
	if(l<r)
	{
		int pivot=median3(arr,l,r),i=l,j=r-1,temp;
		while(i<j)
		{
			while(arr[i]<=pivot)
			{
				i++;
			}
			while(arr[j]>=pivot)
			{
				j--;
			}
			if(i<j)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		temp=arr[r];
		arr[r]=arr[i];
		arr[i]=temp;
		QuickSort(arr,l,i-1);
		QuickSort(arr,i+1,r);
	}
}
void disp(int *arr,int s,int n)
{
	int i;
	for(i=s;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
int main()
{
	int *arr,i,n;
	printf("Enter the number of elements in the array:");
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		printf("Enter the %d element:",(i+1));
		scanf("%d",&arr[i]);
	}
	QuickSort(arr,0,n-1);
	disp(arr,0,n);
	free(arr);
	return 0;
}
