
#include<stdio.h>

#define MAX 1005

bool adj[MAX][MAX];
long double mx[MAX];

int main()
{
	int i,j,k,n,T,cs;
	long double t;
	adj[5][2]=adj[5][3]=true;
	mx[5]=6.0;
	adj[6][2]=adj[6][4]=true;
	mx[6]=8.0;
	adj[7][3]=adj[7][4]=true;
	mx[7]=12.0;
	adj[8][3]=adj[8][5]=true;
	mx[8]=15.0;
	for(i=9;i<1001;i++)
	{
		t=0;
		for(j=4;(i-j)>=5;j++)
		{
			if(!adj[i-j][j])
			{
				if(mx[i-j]*(long double)j>t)
				{
					t=mx[i-j]*(long double)j;
					k=j;
				}
			}
		}
		mx[i]=t;
		for(j=0;j<=(i-k);j++)
			if(adj[i-k][j])
				adj[i][j]=true;
		adj[i][k]=true;
	}
	scanf("%d",&T);
	for(cs=0;cs<T;cs++)
	{
		scanf("%d",&n);
		if(cs)
			printf("\n");
		for(i=0;;i++)
			if(adj[n][i])
			{
				printf("%d",i);
				break;
			}
		for(i++;i<1000;i++)
			if(adj[n][i])
				printf(" %d",i);
		printf("\n");
	}
	return 0;
}

















