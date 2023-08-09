#include<stdio.h>
#include<stdlib.h>
int top=-1,size,k=0;
char *arr;
char *reversed(char a[],int length)
{
	int i;
	char *m=(char*)malloc(sizeof(char)*length);
	for(i=0;i<length;i++)
	{
		m[i]=a[length-1-i];
	}
	return m;
}
int associativity(char a)
{
	if(a=='^')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int order(char a)
{
    if(a=='+'||a=='-')
    {
        return 1;
    }
    else if(a=='*'||a=='/'||a=='%')
    {
        return 2;
    }
    else if(a=='^')
    {
        return 3;
    }
    else
    {
    	return 0;
    }
}
void push(char a)
{
    if((top==(size-1)))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        arr[top]=a;
    }
}
char pop()
{
    if(top<0)
    {
        printf("Stack Underflow\n");
        return '0';
    }	 	  	 	 		 	     	      	   	        	 	
    else
    {
        top--;
        return arr[top+1];
    }
}
void disp(char a[])
{
	int i;
	for(i=k;i<size;i++)
	{
    	printf("%c",a[i]);
    }
}
char *ItoP(int a)
{
    int i=0,j=0;
    char *b,*c,*e;
    e=(char*)malloc(sizeof(char)*a);
    c=(char*)malloc(sizeof(char)*a);
    scanf("%s",e);
    b=reversed(e,a);
    while(i<a+1)
    {
        if(i!=a)
        {
            if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/'||b[i]=='%'||b[i]=='^')
            {
                if(top==-1)
                {
                    push(b[i]);
                    i++;
                }
                else if(order(arr[top])>order(b[i]))
                {
                    	c[j]=pop();
                    	j++;
                }	 	  	 	 		 	     	      	   	        	 	
                else if(order(arr[top])<order(b[i]))
                {
                    push(b[i]);
                    i++;
                }
                else if(order(arr[top])==order(b[i]))
                {
                	if(associativity(b[i])==1)
					{
						c[j]=pop();
						j++;
					}
					else
					{
						push(b[i]);
						i++;
					}
				}
            }
            else if(b[i]==')')
            {
            	push(b[i]);
            	k++;
            	i++;
            }
            else if(b[i]=='(')
            {
            	k++;
            	while(arr[top]!=')')
            	{
            		c[j]=pop();
            		j++;
            	}
            	pop();
            	i++;
            }
            else
            {
            	c[j]=b[i];
                i++;
                j++;
			}
        }
        else
        {
            c[j]=pop();
            j++;
            if(top==-1)
            {
                i++;
            }
        }
    }
    free(b);
    free(e);
    return reversed(c,a);
}
int main()
{
    int a;
    char *c;
    printf("Enter the length of the expression:");
    scanf("%d",&a);
    size=a;
    arr=(char*)malloc(sizeof(char)*a);
    printf("Enter the infix expression:");
    c=ItoP(a);
    printf("The prefix expression is:");
    disp(c);
    free(arr);
    free(c);
    return 0;
}	 	  	 	 		 
