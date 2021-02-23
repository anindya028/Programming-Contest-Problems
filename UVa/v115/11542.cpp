#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

#define LL long long
int p[505],pr[150];

int gene(int n)
{
	int i,j;
	for(i=2;i*i<=n;i++)
		if(!p[i])
			for(j=i*i;j<=n;j+=i)
				p[j]=1;
	j=0;
	for(i=2;i<=n;i++)
		if(!p[i])
			pr[j++]=i;
	return j;
}

int mat[105][105];

bool comp(vector<int> a,vector<int> b)
{
	int i,suma=0,sumb=0,n=a.size();
	for(i=0;i<n;i++)
		suma+=a[i];
	for(i=0;i<n;i++)
		sumb+=b[i];
	return suma>sumb;
}

int main()
{
	int m=gene(500),t,i,n,j,k;
	LL two[64];
	two[0]=1;
	for(i=1;i<64;i++)
		two[i]=two[i-1]*2;
	LL x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(mat,0,sizeof(mat));
		int p=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			for(j=0;j<m;j++)
			{
				int cnt=0;
				while(x%pr[j]==0)
					x/=pr[j],cnt++;
				if(cnt%2)
					p++;
				mat[i][j]=cnt%2;
			}
		}
		vector<int> vv[100];
		for(i=0;i<m;i++)
		{
			vv[i].clear();
			for(j=0;j<n;j++)
				vv[i].push_back(mat[j][i]);
		}
		sort(vv,vv+m,comp);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				mat[j][i]=vv[i][j];
/*	
		for(i=0;i<n;i++)
		{
			for(j=0;j<p;j++)
				printf(" %d",mat[i][j]);
			printf("\n");
		}*/
		for(i=0;i<n;i++)
		{
			if(!mat[i][i])
			{
				for(j=i+1;j<n;j++)
					if(mat[j][i])
					{
						for(k=0;k<m;k++)
							swap(mat[i][k],mat[j][k]);
						break;
					}
			}
			if(!mat[i][i])
				continue;
			for(j=0;j<n;j++)
				if(j!=i && mat[j][i])
				for(k=0;k<m;k++)
					mat[j][k]^=mat[i][k];
		}
		int cnt=0;
		for(i=0;i<n;i++)
		{
			int sum=0;
			for(j=0;j<m;j++)
				sum+=mat[i][j];
			if(!sum)
				cnt++;
		}
		printf("%lld\n",two[cnt]-1);
	}
	return 0;
}