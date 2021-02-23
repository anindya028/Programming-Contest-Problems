#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>

using namespace std;

map<int,int> mp;

int main()
{
	int i,n,ans;
	char s[15];
	while(scanf("%d",&n)==1 && n)
	{
		mp.clear();

		mp[n]=1;
		ans=1;
		while(1)
		{
			sprintf(s,"%.8d",n*n);
			n=0;
			for(i=2;i<6;i++)
				n=n*10+s[i]-'0';
			if(mp.find(n)!=mp.end())
				break;
			mp[n]=1;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}