#include<stdio.h>
#include<algorithm>
#include<map>

using namespace std;

map<int,int> mp;

int main()
{
	int n,m,cnt,i,a;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n && !m)
			break;
		cnt=0;
		mp.clear();
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			mp[a]=1;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&a);
			if(mp.find(a)!=mp.end())
				cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}