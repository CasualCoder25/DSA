#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL,*tail=NULL;
void insertAtFirst(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	if(head==NULL)
	{
		head=temp;
		tail=temp;
	}
	else
	{
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
}
void insertAtLast(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	if(tail==NULL)
	{
		head=temp;
		tail=temp;
	}
	else
	{
		temp->prev=tail;
		tail->next=temp;
		tail=tail->next;
	}
}
void insertAt(int x,int index)
{
	int count=0,flag=0;
	struct node *temp=(struct node *)malloc(sizeof(struct node)),*p=head;
	temp->data=x;
	temp->prev=NULL;
	temp->next=NULL;
	if(index==0)
	{
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			temp->next=head;
			head=temp;
		}
	}
	else
	{
		if(head==NULL)
		{
			printf("Index out of bound\n");
		}
		else
		{
			while(count<index-1)
			{
				if(p->next==NULL)
				{
					printf("Index out of bound\n");
					flag=1;
					break;
				}
				p=p->next;
				count++;
			}
			if(flag==0)
			{
				if(p->next==NULL)
				{
					temp->next=p->next;
					temp->prev=p;
					temp->prev->next=temp;
					tail=tail->next;
				}
				else
				{
					temp->next=p->next;
					temp->prev=p;
					temp->next->prev=temp;
					temp->prev->next=temp;
				}
			}
		}
	}
}
void insertAfter(int x,int y)
{
	int flag=0;
	struct node *temp=(struct node *)malloc(sizeof(struct node)),*p=head,*q;
	temp->data=x;
	temp->next=NULL;
	while(p->data!=y)
	{
		if(p->next==NULL)
		{
			printf("Element not present in list\n");
			flag=1;
			break;
		}
		p=p->next;
	}
	if(flag==0)
	{	
		if(p->next==NULL)
		{
			temp->prev=tail;
			tail->next=temp;
			tail=tail->next;
		}
		else
		{
			temp->next=p->next;
			temp->prev=p;
			temp->next->prev=temp;
			temp->prev->next=temp;
		}
	}
}
void insertBefore(int x,int y)
{
	int flag=0;
	struct node *temp=(struct node *)malloc(sizeof(struct node)),*p=head;
	temp->data=x;
	temp->next=NULL;
	if(head->data==y)
	{
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
	else
	{
		while(p->next->data!=y)
		{
			if(p->next==NULL)
			{
				printf("Element not present in list\n");
				flag=1;
				break;
			}
			p=p->next;
		}
		if(flag==0)
		{
			temp->next=p->next;
			temp->prev=p;
			temp->next->prev=temp;
			temp->prev->next=temp;
		}
	}
}
void removeElement(int x)
{
	int flag=0;
	struct node *p=head,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		if(head->data==x)
		{
			temp=head;
			head=head->next;
			head->prev=NULL;
			free(temp);
		}
		else
		{
			while(p->next->data!=x)	
			{
				if(p->next==NULL)
				{
					printf("Element not present in list\n");
					flag=1;
					break;
				}
				p=p->next;
			}
			if(flag==0)
			{
				if(p->next->next==NULL)
				{
					temp=p->next;
					p->next=NULL;
					tail=tail->prev;
					free(temp);
				}
				else
				{
					temp=p->next;
					p->next->next->prev=p;
					p->next=p->next->next;
					free(temp);
				}
			}
		}
	}
}
void removeAt(int index)
{
	int flag=0,count=0;
	struct node *p=head,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		if(index==0)
		{
			if(head==NULL)
			{
				printf("Index out of bound\n");
			}
			else
			{
				if(head->next==NULL)
				{
					temp=head;
					head=NULL;
					tail=NULL;
					free(temp);
				}
				else
				{
					temp=head;
					head=head->next;
					head->prev=NULL;
					free(temp);
				}
			}
		}
		else
		{
			while(count<index-1)
			{
				if(p->next==NULL)
				{
					printf("Index out of bound\n");
					flag=1;
					break;
				}
				p=p->next;
			}
			if(flag==0)
			{
				if(p->next->next==NULL)
				{
					temp=p->next;
					p->next=NULL;
					tail=tail->prev;
					free(temp);
				}
				else
				{
					temp=p->next;
					p->next->next->prev=p;
					p->next=p->next->next;
					free(temp);
				}
			}
		}
	}
}
void removeAtFirst()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		if(head->next==NULL)
		{
			temp=head;
			head=NULL;
			tail=NULL;
			free(temp);
		}
		else
		{
			temp=head;
			head=head->next;
			head->prev=NULL;
			free(temp);
		}
	}
}
void removeAtLast()
{
	struct node *temp,*p=head;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		if(head->next==NULL)
		{
			temp=head;
			head=NULL;
			tail=NULL;
			free(head);
		}
		else
		{
			while(p->next->next!=NULL)
			{
				p=p->next;
			}
			temp=p->next;
			p->next=NULL;
			free(temp);
		}
	}
}
void disp()
{
	int flag=0;
	struct node *p=head;
	while(p!=NULL)
	{
		flag=1;
		printf("%d\t",p->data);
		p=p->next;
	}
	if(flag==0)
	{
		printf("The list is empty");
	}
	printf("\n");
}
int main()
{
	int a,b,i,j=0;
	printf("Enter:\n");
	printf("1)For insertion at first\n");
	printf("2)For insertion at last\n");
	printf("3)For insertion at index\n");
	printf("4)For insertion at after\n");
	printf("5)For insertion at before\n");
	printf("6)For deletion at first\n");
	printf("7)For deletion at last\n");
	printf("8)For deletion of x\n");
	printf("9)For deletion at index\n");
	printf("10)For exiting program\n");
	while(j==0)
	{
		printf("Enter choice:");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				printf("Enter x:");
				scanf("%d",&b);
				insertAtFirst(b);
				disp();
				break;
			case 2:
				printf("Enter x:");
				scanf("%d",&b);
				insertAtLast(b);
				disp();
				break;
			case 3:
				printf("Enter x:");
				scanf("%d",&b);
				printf("Enter index:");
				scanf("%d",&i);
				insertAt(b,i);
				disp();
				break;
			case 4:
				printf("Enter x:");
				scanf("%d",&b);
				printf("Enter element:");
				scanf("%d",&i);
				insertAfter(b,i);
				disp();
				break;
			case 5:
				printf("Enter x:");
				scanf("%d",&b);
				printf("Enter element:");
				scanf("%d",&i);
				insertBefore(b,i);
				disp();
				break;
			case 6:
				removeAtFirst();
				disp();
				break;
			case 7:
				removeAtLast();
				disp();
				break;
			case 8:
				printf("Enter x:");
				scanf("%d",&b);
				removeElement(b);
				disp();
				break;
			case 9:
				printf("Enter index:");
				scanf("%d",&i);
				removeAt(i);
				disp();
				break;
			case 10:
				j=1;
				break;
			default:
				printf("Enter valid input\n");
		}
	}
	/*insertAtFirst(200);
	disp();
	removeAt(0);
	disp();
	insertAtFirst(400);
	disp();
	insertAt(34,1);
	disp();
	insertAtLast(35);
	disp();
	insertAfter(2,35);
	disp();
	insertBefore(67,34);
	disp();
	removeElement(34);
	disp();
	removeAt(1);
	disp();
	removeAtFirst();
	disp();
	removeAtLast();
	disp();*/
	return 0;
}