#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

#define SIZE 600

using namespace std;

bool adj[SIZE][SIZE];
int K,N;
int cnt;

void build(int n,int k)
{
	int i,j;
	memset(adj,false,sizeof(adj));
	if(k%2==0)
	{
		for(i=0;i<n;i++)
			for(j=1;j<=k/2;j++)if(!adj[i][(i+j)%n] && !adj[j][(i+j)%n])
			{
				adj[i][(i+j)%n]=true;
				cnt++;
			}

		for(i=0;i<n;i++)
			for(j=1;j<=k/2;j++)if(!adj[i][(i-j+n)%n] && !adj[(i-j+n)%n][i])
			{
				adj[i][(i-j+n)%n]=true;
				cnt++;
			}
		
	}
	else
	{
		if(n%2==0)
		{
			for(i=0;i<n;i++)
				for(j=1;j<=(k-1)/2;j++)if(!adj[i][(i+j)%n] && !adj[(i+j)%n][i])
				{
					adj[i][(i+j)%n]=true;
					cnt++;
				}

			for(i=0;i<n;i++)
				for(j=1;j<=(k-1)/2;j++)if(!adj[i][(i-j+n)%n] && !adj[(i-j+n)%n][i])
				{
					adj[i][(i-j+n)%n]=true;
					cnt++;
				}

			for(i=0;i<n;i++)if(!adj[i][(i+(n/2))%n] && !adj[(i+(n/2))%n][i])
			{
				adj[i][(i+(n/2))%n]=true;
				cnt++;
			}
		}
		else
		{
			build(n,k-1);
			for(i=0;i<=(n-1)/2;i++)if(!adj[i][i+(n-1)/2] && !adj[i+(n-1)/2][i])
			{
				adj[i][i+(n-1)/2]=true;
				cnt++;
			}
		}
	}
	return;
}

void print()
{
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)if(adj[i][j])
			printf("%d %d\n",i+1,j+1);
	return;
}

int main(void)
{
	int t,i;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&N,&K);
		if(K==1)
		{
			memset(adj,false,sizeof(adj));
			if(N==2)
				printf("%d\n",N-1);
			else
				printf("%d\n",N);

			for(i=1;i<N;i++)
			{
				adj[i-1][i]=true;
				printf("%d %d\n",i,i+1);
			}
			if(!adj[0][N-1])
				printf("1 %d\n",N);
			printf("\n");
			continue;
		}
		cnt=0;
		build(N,K+1);
		printf("%d\n",cnt);
		print();
		printf("\n");
	}
	return 0;
}