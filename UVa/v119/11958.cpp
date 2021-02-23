#include<stdio.h>
#include<string.h>

int main()
{
	int t,cs,n,v,i,ans;
	char s[10];
	scanf("%d",&t);
	for(cs=1;cs<=t;cs++)
	{
		scanf("%d%s",&n,s);

		int now = ( (s[0]-'0')*10 + (s[1]-'0') ) * 60 + (s[3]-'0')*10 + (s[4]-'0');
		ans = 100000000;
		for(i=0;i<n;i++)
		{
			scanf("%s%d",s,&v);
			int got = ( (s[0]-'0')*10 + (s[1]-'0') ) * 60 + (s[3]-'0')*10 + (s[4]-'0');
			if(got<now)
				got+=1440;

			if(got-now+v<ans)
				ans = got-now+v;
		}
		printf("Case %d: %d\n",cs,ans);
	}
	return 0;
}