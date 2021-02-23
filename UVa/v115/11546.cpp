#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

#define Max(a,b) (((a)>(b))?(a):(b))

struct he
{
	vector<int> col;
}p[50005];

map<vector<int>,int> mp;
int data[35][50005];

int main()
{
	int i,j,cs=0,l,k,n,now;
	while(scanf("%d%d",&l,&k)==2 && k && l)
	{
		mp.clear();
		memset(data,0,sizeof(data));
		for(i=0;i<k;i++)
		{
			scanf("%d",&n);
			for(j=0;j<n;j++)
				scanf("%d",&now),data[i][now+1]=1;
		}

		for(i=0;i<k;i++)
			for(j=1;j<=l;j++)
				data[i][j]+=data[i][j-1];
		
		for(i=k-1;i>=0;i--)
			for(j=0;j<=l;j++)
				data[i][j]-=data[0][j];
		
		for(j=0;j<=l;j++)
		{
			p[j].col.clear();
			for(i=0;i<k;i++)
				p[j].col.push_back(data[i][j]);
		}

		int ans=0;

		for(i=0;i<l+1;i++)
		{
			if(mp.find(p[i].col)==mp.end())
			{
				mp[p[i].col]=i;
				continue;
			}
			ans=Max(i-mp[p[i].col],ans);
		}
		printf("Case #%d: %d meter(s)\n",++cs,ans);
	}
	return 0;
}