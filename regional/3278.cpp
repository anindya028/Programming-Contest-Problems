#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

bool comp(int a,int b,int n)
{
	int i;
	vector<int> va,vb;
	for(i=0;i<n;i++)
	{
		if( a & 1<<i)
			va.push_back(i+1);
		if( b & 1<<i)
			vb.push_back(i+1);
	}

	return va<vb;
}

int main()
{
	int n,v,m,i,j,cs=0;
	int data[25];
	vector<int> com[15];
	int tot[15];
	while(scanf("%d%d",&n,&v)==2 && n && v)
	{
		for(i=0;i<n;i++)
			scanf("%d",&data[i]);
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			int k,x;
			com[i].clear();
			scanf("%d",&k);
			for(j=0;j<k;j++)
				scanf("%d",&x),x--,com[i].push_back(x);
			scanf("%d",&tot[i]);
		}
		int ans=0,kk=0;
		for(i=1;i<(1<<n);i++)
		{
			int sum=0,cnt=0;
			for(j=0;j<n;j++)
				if(i & 1<<j)
					sum+=data[j],cnt++;
			if(cnt!=v)
				continue;
			for(j=0;j<m;j++)
			{
				int k,ok=0;
				for(k=0;k<com[j].size();k++)
					if(i & 1<<com[j][k])
						ok++;
				
				if (ok) sum-=((ok-1)*tot[j]);
			}
			if(sum>ans || (sum==ans && comp(i,kk,n)))
				ans=sum,kk=i;
		}
		printf("Case Number  %d\n",++cs);
		printf("Number of Customers: %d\n",ans);
		printf("Locations recommended:");
		for(i=0;i<n;i++)
			if(kk & 1<<i)
				printf(" %d",i+1);
		printf("\n\n");
	}
	return 0;
}