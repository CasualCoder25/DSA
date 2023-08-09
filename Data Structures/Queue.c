#include<stdio.h>
#include<stdlib.h>
int *arr,front=-1,rear=-1,size;
void enqueue();
int dequeue();
int front1();
int rear1();
void disp();
int main()
{
    int i,j;
    printf("Enter Queue Size=");
    scanf("%d",&size);
    printf("Enter Choice:\n1 for enqueue\n2 for dequeue\n3 for front\n4 for rear\n5 for ending program\n");
    i=0;
    arr=(int*)malloc(size*sizeof(int));
    while(i!=5)
    {
        printf("Enter Choice=");
        scanf("%d",&i);
        if(i==1)
        {
            enqueue();
            disp();
        }
        else if(i==2)
        {
            j=dequeue();
            disp();
        }
        else if(i==3)
        {
            j=front1();
            if(front!=-1)
            {
                printf("Element=%d\n",j);
            }	 	  	 	 		 	     	      	   	        	 	
        }
        else if(i==4)
        {
            j=rear1();
            if(rear!=-1)
            {
                printf("Element=%d\n",j);
            }
        }
        else if(i==5)
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
void enqueue()
{
    if(rear==(size-1))
    {
        printf("Queue Overflow\n");
    }
    else if(rear==-1)
    {
    	front++;
        rear++;
        printf("Enter the Element=");
        scanf("%d",&arr[rear]);
    }
    else
    {
    	rear++;
        printf("Enter the Element=");
        scanf("%d",&arr[rear]);
    }
}
int dequeue()
{
	int i;
    if(front==-1)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    else if(front==rear)
    {
    	i=front;
    	front=-1;
    	rear=-1;
        return arr[i];
    }
	else
	{
		front++;
		return arr[front-1];
	} 	  	 	 		 	     	      	   	        	 	
}
int front1()
{
    if(front<0)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    else
    {
        return arr[front];
    }
}
int rear1()
{
    if(rear<0)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    else
    {
        return arr[rear];
    }
}
void disp()
{
    int i;
    for(i=front;i<rear+1;i++)
    {
        if(i==front)
        {
            printf("[");
        }
        if(front!=-1)
        {
        	printf(" %d ",arr[i]);
        }
        if(i==rear)
        {
            printf("]\n");
        }
    }
}
	 	  	 	 		 	     	      	   	      
