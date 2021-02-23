#include<stdio.h>

#define Min(a,b) (((a)<(b))?(a):(b))

char s[2000005];

int main()
{
	int n,i,ans;
	while(scanf("%d",&n)==1 && n)
	{
		scanf("%s",s);
		int lastr=-1,lastd=-1;
		ans=1<<29;
		for(i=0;i<n;i++)
			if(s[i]=='R')
			{
				if(lastd!=-1)
					ans=Min(ans,i-lastd);
				lastr=i;
			}
			else if(s[i]=='D')
			{
				if(lastr!=-1)
					ans=Min(ans,i-lastr);
				lastd=i;
			}
			else if(s[i]=='Z')
			{
				ans=0;
				break;
			}
		printf("%d\n",ans);
	}
	return 0;
}