#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct
{
	char *arr;
	int top;
	int size;
}stack;
typedef struct
{
	double *arr;
	int top;
	int size;
}stack1;
typedef struct
{
	char *postfix;
	int j;
}output;
int numOfpar(char *a,int length)
{
	int i,j=0;
	for(i=0;i<length;i++)
	{
		if(a[i]=='('||a[i]==')')
		{
			j++;
		}
	}
	return j;
}
int charToInt(char *arr,int n1)
{
	int i,j=0;
	for(i=n1;;i++)
	{
		if(arr[i]=='0')
		{
			j=10*j+0;
		}
		else if(arr[i]=='1')
		{
			j=10*j+1;
		}
		else if(arr[i]=='2')
		{
			j=10*j+2;
		}
		else if(arr[i]=='3')
		{
			j=10*j+3;
		}
		else if(arr[i]=='4')
		{
			j=10*j+4;
		}
		else if(arr[i]=='5')
		{
			j=10*j+5;
		}
		else if(arr[i]=='6')
		{
			j=10*j+6;
		}
		else if(arr[i]=='7')
		{
			j=10*j+7;
		}
		else if(arr[i]=='8')
		{
			j=10*j+8;
		}
		else if(arr[i]=='9')
		{
			j=10*j+9;
		}
		else if(arr[i]==' ')
		{
			break;
		}
	}
	return j;
}
int lengthofint(int a)
{
	int i=0;
	while(a>0)
	{
		a=a/10;
		i++;
	}
	return i;
}
int isempty(stack *s)
{
	if(s->top<0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isempty1(stack1 *s1)
{
	if(s1->top<0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isfull(stack *s)
{
	if(s->top==s->size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isfull1(stack1 *s1)
{
	if(s1->top==s1->size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
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
void push(stack *s,char a)
{
    if(isfull(s)==1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->top++;
        s->arr[s->top]=a;
    }
}
void push1(stack1 *s1,float a)
{
    if(isfull1(s1)==1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s1->top++;
        s1->arr[s1->top]=a;
    }
}
char pop(stack *s)
{
    if(isempty(s)==1)
    {
        printf("Stack Underflow\n");
        return '0';
    }	 	  	 	 		 	     	      	   	        	 	
    else
    {
        s->top--;
        return s->arr[s->top+1];
    }
}
float pop1(stack1 *s1)
{
    if(isempty1(s1)==1)
    {
        printf("Stack Underflow\n");
        return 0;
    }	 	  	 	 		 	     	      	   	        	 	
    else
    {
        s1->top--;
        return s1->arr[(s1->top)+1];
    }
}
void disp1(stack1 *s1)
{
	int i;
	for(i=0;i<s1->top+1;i++)
	{
		printf("%d",s1->arr[i]);
	}
	printf("\n");
}
void ItoP(stack *s,output *p,int length)
{
    int i=0,par;
    char *b;
    b=(char*)malloc(sizeof(char)*length);
    scanf("%s",b);
    par=numOfpar(b,length);
    p->postfix=(char*)malloc(sizeof(char)*(2*length-1-par));
    while(i<length)
    {
        if(!isdigit(b[i])&&order(b[i])!=0)
        {
            if(isempty(s)==1)
            {
                push(s,b[i]);
                i++;
            }
            else if(order(s->arr[s->top])>order(b[i]))
            {
                	p->postfix[p->j]=pop(s);
                	p->postfix[p->j+1]=' ';
                   	p->j=p->j+2;
            }	 	  	 	 		 	     	      	   	        	 	
            else if(order(s->arr[s->top])<order(b[i]))
            {
                push(s,b[i]);
                i++;
            }
            else if(order(s->arr[s->top])==order(b[i]))
            {
              	if(associativity(b[i])==1)
				{
					push(s,b[i]);
					i++;
				}
				else
				{
					p->postfix[p->j]=pop(s);
					p->postfix[p->j+1]=' ';
                   	p->j=p->j+2;
				}
			}
        }
        else if(b[i]=='(')
        	{
          		push(s,b[i]);
        	   	i++;
        	}
        else if(b[i]==')')
	    {
	     	while(s->arr[s->top]!='(')
	       	{
	     		p->postfix[p->j]=pop(s);
	       		p->postfix[p->j+1]=' ';
	      		p->j=p->j+2;
	       	}
	       	pop(s);
	       	i++;
	    }
        else
        {
         	p->postfix[p->j]=b[i];
         	p->j++;
            i++;
            if(!isdigit(b[i]))
            {
				p->postfix[p->j]=' ';
             	p->j++;
            }
		}
    }
    while(isempty(s)==0)
	{
            p->postfix[p->j]=pop(s);
            p->postfix[p->j+1]=' ';
            p->j=p->j+2;
    }
    free(b);
}
double evaluation(stack1 *s1,output *p)
{
	int i,l,m;
	double k,h,result;
	for(i=0;i<p->j;i++)
    {
    	if(isdigit(p->postfix[i]))
    	{
			l=charToInt(p->postfix,i);
    		push1(s1,l);
    		m=lengthofint(l);
			i=i+m-1;
    	}
    	else if(p->postfix[i]==' ')
        {
        	continue;
        }
        else
        {
			k=pop1(s1);
			h=pop1(s1);                                                                                                                                   	
        	if(p->postfix[i]=='+')
        	{
        		result=h+k;
        		push1(s1,result);
        	}
        	else if(p->postfix[i]=='-')
        	{
        		result=h-k;
        		push1(s1,result);
        	}
        	else if(p->postfix[i]=='*')
        	{
        		result=k*h;
        		push1(s1,result);
        	}
        	else if(p->postfix[i]=='/')
        	{
        		result=h/k;
        		push1(s1,result);
        	}
        	else if(p->postfix[i]=='^')
        	{
        		result=pow(h,k);
        		push1(s1,result);
        	}
        }
    }
    return pop1(s1);
}
void disp(output *p)
{
	int i;
	for(i=0;i<p->j;i++)
	{
		printf("%c",p->postfix[i]);
	}
	printf("\n");
}

int main()
{
	stack s;
	stack1 s1;
    int length;
	double result;
    output p;
    p.j=0;
    printf("Enter the length of the expression:");
    scanf("%d",&length);
    s.top=-1;
    s.size=length;
    s.arr=(char*)malloc(sizeof(char)*length);
    printf("Enter the infix expression:");
    ItoP(&s,&p,length);
    printf("The postfix expression is:");
    disp(&p);
	s1.top=-1;
    s1.size=p.j;
    s1.arr=(double*)malloc(sizeof(double)*(p.j));
    result=evaluation(&s1,&p);
    printf("The final eveluated answer is: %.4f",result);
    free(s.arr);
    free(s1.arr);
    free(p.postfix);
    return 0;
}	 	  	
