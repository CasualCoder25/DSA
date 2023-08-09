#include<stdio.h>
#include<stdlib.h>
//int arr[50],top=-1,size,k=0;
int *arr,top=-1,size;
void push();
int pop();
int peek();
void disp();
int main()
{
    int i,j;
    printf("Enter Stack Size=");
    scanf("%d",&size);
    printf("Enter Choice:\n1 for push\n2 for pop\n3 for peek\n4 for ending program\n");
    i=0;
    arr=(int*)malloc(size*sizeof(int));
    while(i!=4)
    {
        printf("Enter Choice=");
        scanf("%d",&i);
        if(i==1)
        {
            push();
            disp();
        }
        else if(i==2)
        {
            j=pop();
            disp();
        }
        else if(i==3)
        {
            j=peek();
            if(top!=-1)
            {
                printf("Element=%d\n",j);
            }	 	  	 	 		 	     	      	   	        	 	
        }
        else if(i==4)
        {
            break;
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }
    free(arr);
    return 0;
}
void push()
{
    if((top==(size-1))||(top>49))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        printf("Enter the Element=");
        scanf("%d",&arr[top]);
    }
}
int pop()
{
    if(top<0)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    else
    {
        top--;
        return arr[top+1];
    }	 	  	 	 		 	     	      	   	        	 	
}
int peek()
{
    if(top<0)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    else
    {
        return arr[top];
    }
}
void disp()
{
    int i;
    if(top==-1)
    {
        printf("[]\n");
    }
    for(i=0;i<top+1;i++)
    {
        if(i==0)
        {
            printf("[");
        }
        printf(" %d ",arr[i]);
        if(i==top)
        {
            printf("]\n");
        }
    }
}
	 	  	 	 		 	     	      	   	        	 	
