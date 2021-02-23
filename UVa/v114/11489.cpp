#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string>
using namespace std;

#define INF 1<<30
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Foro(i,n) For(i,0,n)

int main()
{
	int t,i,sum,cnt[3],cs=0;
	char s[1005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		for(i=sum=cnt[0]=cnt[1]=cnt[2]=0;s[i];++i)
			sum+=s[i]-'0',cnt[(s[i]-'0')%3]++;
		if(strlen(s)==1)
		{
			printf("Case %d: S\n",++cs);
			continue;
		}
		if(sum%3==0)
		{
			if(cnt[0]%2)
				printf("Case %d: S\n",++cs);
			else
				printf("Case %d: T\n",++cs);
		}
		else
		{
			if(!cnt[sum%3])
			{
				printf("Case %d: T\n",++cs);
				continue;
			}
			if(cnt[0]%2)
				printf("Case %d: T\n",++cs);
			else
				printf("Case %d: S\n",++cs);
		}
			
	}
	return 0;
}
