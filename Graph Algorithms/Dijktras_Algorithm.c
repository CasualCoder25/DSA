#include<stdio.h>
#include<stdlib.h>
const int inf=9999999;
int *visited,*dist,*pathvertex,**arr;//[5][5]={{0,3,0,4,0},{3,0,1,0,4},{0,1,0,2,1},{4,0,2,0,3},{0,4,1,3,0}};
int n;
int minDistance()
{
	int minvertex=0;
	int mindist=inf;
	for(int i=0;i<n;i++)
	{
		if(dist[i]<=mindist&&visited[i]!=1)
		{
			minvertex=i;
			mindist=dist[i];
		}
	}
	return minvertex;
}
void input(int x)
{
	n=x;
	int i,j;
	visited=(int*)malloc(sizeof(int)*x);
	dist=(int*)malloc(sizeof(int)*x);
	pathvertex=(int*)malloc(sizeof(int)*x);
	arr=(int**)malloc(sizeof(int*)*x);
	for(j=0;j<x;j++)
	{
		arr[j]=(int*)malloc(sizeof(int)*x);
	}
	for(i=0;i<x;i++)
	{
		visited[i]=0;
		dist[i]=inf;
		pathvertex[i]=0;
		for(j=0;j<x;j++)
		{
			printf("Enter the edge weight for edge from %d to %d:",i+1,j+1);
			scanf("%d",&arr[i][j]);
		}
	}
}
void dijkstras(int src)
{
	dist[src]=0;pathvertex[src]=src;
	int u=minDistance();
	visited[u]=1;
	for(int count=0;count<n;count++)
	{
		for(int i=0;i<n;i++)
		{
			if(visited[i]!=1&&arr[u][i]!=0&&dist[u]!=inf&&dist[u]+arr[u][i]<dist[i])
			{
				dist[i]=dist[u]+arr[u][i];
				pathvertex[i]=u;
			}
		}
		visited[u]=1;
		u=minDistance();
	}
}
int main()
{
	int a;
	printf("Enter number of vertices:");
	scanf("%d",&a);
	input(a);
	dijkstras(0);
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\n",i,dist[i],pathvertex[i]);
	}
	return 0;
}