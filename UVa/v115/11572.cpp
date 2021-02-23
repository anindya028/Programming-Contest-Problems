#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;	

int num[1000005];
map<int,int> mp;

#define Max(a,b) (((a)>(b))?(a):(b))

int main()
{
	int n,i,ans,last,cs;
	scanf("%d",&cs);
	while(cs--)
	{
		scanf("%d",&n);
		mp.clear();
		last=-1;
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			if(mp.find(num[i])==mp.end())
				mp[num[i]]=i;
			else
			{
				if(mp[num[i]]>last)
					ans=Max(ans,i-last-1),last=mp[num[i]];
				mp[num[i]]=i;
			}
		}
		ans=Max(ans,i-last-1);
		printf("%d\n",ans);
	}
	return 0;
}
