#include<stdio.h>
#include<stdlib.h>
struct BSTnode
{
	struct BSTnode *LC;
	int data;
	struct BSTnode *RC;
};
int i=0,j=0,*arr;
struct BSTnode *root=NULL;
void insert(struct BSTnode *T,int x)
{
	struct BSTnode *temp;
	if(T==NULL)
	{
		temp=(struct BSTnode *)malloc(sizeof(struct BSTnode));
		temp->data=x;
		temp->LC=NULL;
		temp->RC=NULL;
		root=temp;
		i++;
	}
	else
	{
		if(T->data<x)
		{
			if(T->RC==NULL)
			{
				temp=(struct BSTnode *)malloc(sizeof(struct BSTnode));
				temp->data=x;
				temp->LC=NULL;
				temp->RC=NULL;
				T->RC=temp;
				i++;
			}
			else if(T->RC!=NULL)
			{
				insert(T->RC,x);
			}
		}
		else if(T->data>=x)
		{
			if(T->LC==NULL)
			{
				temp=(struct BSTnode *)malloc(sizeof(struct BSTnode));
				temp->data=x;
				temp->LC=NULL;
				temp->RC=NULL;
				T->LC=temp;
				i++;
			}
			else
			{
				insert(T->LC,x);
			}
		}
	}
}
struct BSTnode *maxValueNode(struct BSTnode *T)
{
	struct BSTnode *temp=T;
	while(temp!=NULL&&temp->RC!=NULL)
	{
		temp=temp->RC;
	}
	return temp;
}
void deletion(struct BSTnode *T,struct BSTnode *parent,int x)
{
	struct BSTnode *LC,*RC,*temp;
	if(T==NULL)
	{
		printf("Tree underflow");
	}
	else
	{
		if(T->data<x)
		{
			deletion(T->RC,T,x);
		}
		else if(T->data>x)
		{
			deletion(T->LC,T,x);
		}
		else if(T->data==x)
		{
			if(T->LC==NULL&&T->RC==NULL&&parent==NULL)
			{
				i--;
				root=NULL;
				free(T);
			}
			else if(T->LC==NULL&&T->RC==NULL&&parent!=NULL)
			{
				if(parent->LC!=NULL&&parent->LC->data==x)
				{
					parent->LC=NULL;
				}
				else if(parent->RC!=NULL&&parent->RC->data==x)
				{
					parent->RC=NULL;
				}
				i--;
				free(T);
			}
			else if(T->LC==NULL&&parent==NULL)
			{
				i--;
				root=T->RC;
				free(T);
			}
			else if(T->LC==NULL)
			{
				if(parent->LC!=NULL&&parent->LC->data==x)
				{
					parent->LC=T->RC;
				}
				else if(parent->RC!=NULL&&parent->RC->data==x)
				{
					parent->RC=T->RC;
				}
				i--;
				free(T);
			}
			else
			{
				temp=maxValueNode(T->LC);
				T->data=temp->data;
				deletion(T->LC,T,temp->data);
			}
		}
	}
}
void inorder(struct BSTnode *T)
{
	if(T!=NULL)
	{
		inorder(T->LC);
		arr[j]=T->data;
		j++;
		inorder(T->RC);
	}
}
void preorder(struct BSTnode *T)
{
	if(T!=NULL)
	{
		arr[j]=T->data;
		j++;
		preorder(T->LC);
		preorder(T->RC);
	}
}
void postorder(struct BSTnode *T)
{
	if(T!=NULL)
	{
		postorder(T->LC);
		postorder(T->RC);
		arr[j]=T->data;
		j++;
	}
}
void disp()
{
	j=0;
	int k;
	for(k=0;k<i;k++)
	{
		printf("%d\t",arr[k]);
	}
	printf("\n");
}
int main()
{
	/*insert(root,3);
	insert(root,5);
	insert(root,6);
	insert(root,0);
	insert(root,-2);
	insert(root,-1);
	//insert(root,2);
	arr=(int *)malloc(i*sizeof(int));
	inorder(root);
	disp();
	deletion(root,NULL,3);
	arr=(int *)malloc(i*sizeof(int));
	inorder(root);
	disp();
	deletion(root,NULL,6);
	arr=(int *)malloc(i*sizeof(int));
	inorder(root);
	disp();*/
	printf("1 for insert\n2 for delete\n3 for inorder\n4 for preorder\n5 for postorder\n6 for ending program\n");
	int choice=0,x;
	while(choice!=6)
	{
		printf("Enter choice:");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Enter Element:");
			scanf("%d",&x);
			insert(root,x);
		}
		else if(choice==2)
		{
			printf("Enter Element:");
			scanf("%d",&x);
			deletion(root,NULL,x);
		}
		else if(choice==3)
		{
			arr=(int *)malloc(i*(sizeof(int)));
			inorder(root);
			disp();
		}
		else if(choice==4)
		{
			arr=(int *)malloc(i*(sizeof(int)));
			preorder(root);
			disp();
		}
		else if(choice==5)
		{
			arr=(int *)malloc(i*(sizeof(int)));
			postorder(root);
			disp();
		}
		else if(choice==6)
		{
			printf("Ending program");
		}
		else
		{
			printf("Invalid input\n");
		}
	}
	return 0;
}