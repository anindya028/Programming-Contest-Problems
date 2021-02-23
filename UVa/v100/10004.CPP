
//Bicoloring
#include<stdio.h>
#include<queue>

using namespace std;
#define INF 10000

void ini(int arr[][200],int col[],int n)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			arr[i][j]=INF;
		col[i]=0;
	}
}

void bic(int arr[][200],int col[],int n)
{
	int i,j;
	queue<int> q;

	col[0]=1;
	q.push(0);
	while(!q.empty())
	{
		i=q.front();
		q.pop();
		for(j=i+1;j<n;j++)
		{
			if(arr[i][j]==1)
			{
				if(col[i]!=col[j])
				{
					if(col[i]==1)
						col[j]=2;
					else
						col[j]=1;
					q.push(j);
				}
				else
				{
					printf("NOT BICOLORABLE.\n");
					return;
				}
			}
		}
	}
	printf("BICOLORABLE.\n");
}

int main()
{
	int i,j,n,k,m;
	int arr[200][200];
	int col[200];

	while(1)
	{
		scanf("%d",&n);
		if(!n)
			break;

		ini(arr,col,n);
		scanf("%d",&m);

		for(k=0;k<m;k++)
		{
			scanf("%d%d",&i,&j);
			arr[i][j]=arr[j][i]=1;
		}
		bic(arr,col,n);
	}

	return 0;
}













