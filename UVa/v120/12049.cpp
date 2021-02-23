#include<stdio.h>
#include<algorithm>
#include<map>

using namespace std;

map<int,int> mp;

int main()
{
	int n,m,t,i,a;
	scanf("%d",&t);
	while(t--)
	{
		mp.clear();
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(mp.find(a)==mp.end())
				mp[a] = 1;
			else
				mp[a]++;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&a);
			if(mp.find(a)==mp.end())
				mp[a] = -1;
			else
				mp[a]--;
		}

		int sum = 0;
		map<int,int>::iterator it;
		for(it = mp.begin(); it!=mp.end(); it++)
			if(it->second > 0)
				sum += it->second;
			else
				sum -= it->second;

		printf("%d\n",sum);
	}
	return 0;
}