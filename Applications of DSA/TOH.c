#include<stdio.h>
int k;
int TOH(int n,char from,char to,char aux)
{
	if(n==1)
	{
		printf("%c to %c\n",from,to);
		k++;
		return k;
	}
	else
	{
		TOH(n-1,from,aux,to);
		printf("%c to %c\n",from,to);
		k++;
		return TOH(n-1,aux,to,from);
	}
}
int main()
{
	int n,i;
	char s[3];
	printf("Enter the number of rings:");
	scanf("%d",&n);
	printf("Enter Initial Rod,Destination,Auxillary Rods(format:'ABC'):");
	scanf("%s",s);
	i=TOH(n,s[0],s[1],s[2]);
	printf("%d moves were performed\n",i);
	return 0;
}
