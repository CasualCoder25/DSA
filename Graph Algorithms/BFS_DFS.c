#include<stdio.h>
#include<stdlib.h>
int **arr;
int numOfVertex;
int *visited;
struct node
{
	int val;
	struct node* next;
}*head,*tail;
void enqueue(int key)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->val=key;
	if(head==NULL)
	{
		head=temp;
		tail=temp;
	}
	else
	{
		tail->next=temp;
		tail=tail->next;
	}
}
int dequeue()
{
	struct node *temp=head;
	int val=temp->val;
	if(head=tail)
	{
		head=NULL;
		tail=NULL;
		free(temp);
	}
	else
	{
		head=head->next;
		free(temp);
	}
	return val;
}
int isEmpty()
{
	if(head!=NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void input(int x)
{
	numOfVertex=x;
	int i,j;
	visited=(int*)malloc(sizeof(int)*x);
	arr=(int**)malloc(sizeof(int*)*x);
	for(j=0;j<x;j++)
	{
		arr[j]=(int*)malloc(sizeof(int)*x);
	}
	for(i=0;i<x;i++)
	{
		visited[i]=0;
		for(j=0;j<x;j++)
		{
			printf("Enter the edge weight for edge from %d to %d:",i+1,j+1);
			scanf("%d",&arr[i][j]);
		}
	}
}
void DFS(int i)
{
	printf("%d\t",i+1);
	visited[i]=1;
	for(int j=0;j<numOfVertex;j++)
	{
		if(arr[i][j]!=0&&visited[j]!=1)
		{
			DFS(j);
		}
	}	
}
void BFS(int i)
{
	int j;
	printf("%d\t",i+1);
	visited[i]=1;
	enqueue(i);
	while(isEmpty()==0)
	{
		j=dequeue();
		for(int k=0;k<numOfVertex;k++)
		{
			if(arr[j][k]!=0&&visited[k]!=1)
			{
				printf("%d\t",k+1);
				visited[k]=1;
				enqueue(k);
			}
		}
	}
	for(int m=0;m<numOfVertex;m++)
	{
		visited[m]=0;
	}
}
int main()
{
	int a;
	printf("Enter number of vertices:");
	scanf("%d",&a);
	input(a);
	BFS(0);
	printf("\n");
	DFS(0);
	return 0;
}