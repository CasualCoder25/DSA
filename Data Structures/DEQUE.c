#include<stdio.h>
#include<stdlib.h>
int *arr,front=-1,rear=-1,size,k=0;
void enqueue1();
int dequeue1();
void enqueue2();
int dequeue2();
int front1();
int rear1();
void disp();
int main()
{
    int i,j;
    printf("Enter Queue Size=");
    scanf("%d",&size);
    printf("Enter Choice:\n1 for enqueue from rear\n2 for dequeue from front\n3 for enqueue from front\n4 for dequeue from rear\n5 for front\n6 for rear\n7 for ending program\n");
    i=0;
    arr=(int*)malloc(size*sizeof(int));
    while(i!=7)
    {
        printf("Enter Choice=");
        scanf("%d",&i);
        if(i==1)
        {
            enqueue1();
            disp();
        }
        else if(i==2)
        {
            j=dequeue1();
            disp();
        }
        else if(i==3)
        {
            enqueue2();
            disp();
        }
        else if(i==4)
        {
            j=dequeue2();
            disp();
        }
        else if(i==5)
        {
            j=front1();
            if(front!=-1)
            {
                printf("Element=%d\n",j);
            }	 	  	 	 		 	     	      	   	        	 	
        }
        else if(i==6)
        {
            j=rear1();
            if(rear!=-1)
            {
                printf("Element=%d\n",j);
            }
        }
        else if(i==7)
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
void enqueue1()
{
    if((front==0&&rear==size-1)||(front==rear+1))
    {
        printf("Queue Overflow\n");
    }
    else
    {
    	if(front==-1&&rear==-1)
    	{
    		front++;
    		rear++;
    		printf("Enter the Element=");
        	scanf("%d",&arr[rear]);
        	k++;
		}
		else
		{
    		rear=(rear+1)%size;
        	printf("Enter the Element=");
        	scanf("%d",&arr[rear]);
        	k++;
    	}
    }
}
int dequeue1()
{
	int i;
    if(front==-1&&rear==-1)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    else
    {
	    if(front==rear)
	    {
	    	i=front;
	    	front=-1;
	    	rear=-1;
	    	k--;
	        return arr[i];
	    }
		else
		{
			i=front;
			front=(front+1)%size;
			k--;
			return arr[i];
		} 
	}
}
void enqueue2()
{
    if((front==0&&rear==size-1)||(front==rear+1))
    {
        printf("Queue Overflow\n");
    }
    else
    {
    	if(front==-1&&rear==-1)
    	{
    		front++;
    		rear++;
    		printf("Enter the Element=");
        	scanf("%d",&arr[rear]);
        	k++;
		}
		else
		{
    		front=(front+size-1)%size;
        	printf("Enter the Element=");
        	scanf("%d",&arr[front]);
        	k++;
    	}
    }
}
int dequeue2()
{
	int i;
    if(front==-1&&rear==-1)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    else
    {
	    if(front==rear)
	    {
	    	i=front;
	    	front=-1;
	    	rear=-1;
	    	k--;
	        return arr[i];
	    }
		else
		{
			i=rear;
			rear=(rear+size-1)%size;
			k--;
			return arr[i];
		} 
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
    int i,j;
    if(k==0)
    {
    	printf("[]\n");
	}
    for(i=0;i<k;i++)
    {
    	j=(front+i)%size;
        if(j==front)
        {
            printf("[");
        }
        if(front!=-1)
        {
        	printf(" %d ",arr[j]);
        }
        if(j==rear)
        {
            printf("]\n");
        }
    }
}
	 	  	 	 	