#include<stdio.h>
#include<string.h>

#define mod 1000000007

int cnt[26],st[100005];
char s[100005];

int main()
{
	int t,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		ans=1;
		for(i=0;i<26;++i)
			cnt[i]=0;
		for(i=strlen(s)-1;i>=0;i--)
			st[i]=ans,
			st[i]=(st[i]-cnt[s[i]-'A']+mod)%mod,
			cnt[s[i]-'A']=(cnt[s[i]-'A']+st[i])%mod,
			ans=(ans+st[i])%mod;
		printf("%d\n",ans);
	}
	return 0;
}
