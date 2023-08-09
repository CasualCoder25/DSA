#include<stdio.h>
#include<stdlib.h>
void merge(int *arr,int l1,int l2,int r1,int r2)
{
	int i=0,j=0,k=0,n1,n2,*arr1;
	arr1=(int*)malloc(r2-l1+1);
	n1=(l2-l1+1);
	n2=(r2-r1+1);
	while(i<n1&&j<n2)
	{
		if(arr[l1+i]<arr[r1+j])
		{
			arr1[k]=arr[l1+i];
			i++;
			k++;
		}
		else if(arr[l1+i]>=arr[r1+j])
		{
			arr1[k]=arr[r1+j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		arr1[k]=arr[l1+i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr1[k]=arr[r1+j];
		j++;
		k++;
	}
	for(i=0;i<k;i++)
	{
		arr[l1+i]=arr1[i];
	}
	free(arr1);
}
void mergeSort(int *arr,int l,int r)
{
	if(l<r)
	{
		int m;
		m=(l+r)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,m+1,r);
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
	mergeSort(arr,0,n-1);
	disp(arr,0,n);
	free(arr);
	return 0;
}
