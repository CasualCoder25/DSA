#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j,*arr,elem,index=-1,key,low=0,high,mid;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    {	 	  	 	 		 	     	      	   	        	 	
        scanf("%d",&arr[i]);
    }
    printf("Enter the search element:");
    scanf("%d",&elem);
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    printf("The sorted array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    high=n;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==elem)
        {
            index=mid;
            break;
        }
        else if(arr[mid]<elem)
        {
            low=mid+1;
        }
        else if(arr[mid]>elem)
        {
            high=mid-1;
        }	 	  	 	 		 	     	      	   	        	 	
    }
    if(index==-1)
    {
        printf("The element is not in the array.");
    }
    else
    {
        printf("The element is in the %d index position",index);
    }
    return 0;
}

