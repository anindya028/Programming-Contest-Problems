//MCM 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;

struct factor
{
	char s[100];
	int freq[100],len,pr[100];
};
char given[100];
factor memo[90][90];

factor make(int st,int end)
{
	factor a,b;
	int i,j,k,flag;
	if(memo[st][end].len<10000)
		return memo[st][end];
	if(st==end)
	{
		a.s[0]=given[st];
		a.s[1]='\0';
		a.len=1;
		a.freq[0]=1;
		a.pr[0]=1;
		memo[st][end]=a;
		return memo[st][end];
	}
	for(k=st;k<end;k++)
	{
		a=make(st,k);
		b=make(k+1,end);
		if(a.len!=b.len)
		{
			for(i=a.len,j=0;j<b.len;i++,j++)
			{
				a.s[i]=b.s[j];
				a.freq[i]=b.freq[j];
			}
			a.len+=b.len;
			a.s[i]='\0';
			for(i=0;i<a.len;i++)
				a.pr[i]=a.freq[i];
		}
		else
		{
			flag=1;
			for(i=0;i<a.len;i++)
				if(a.s[i]!=b.s[i] || a.pr[i]!=b.pr[i])
				{
					flag=0;
					break;
				}
			if(a.len==1 && a.s[0]==b.s[0])
				flag=1;
			if(flag)
			{
				for(i=0;i<a.len;i++)
					a.freq[i]=a.freq[i]+b.freq[i];
					
			}
			else
			{
				for(i=a.len,j=0;j<b.len;i++,j++)
				{
					a.s[i]=b.s[j];
					a.freq[i]=b.freq[j];
				}
				a.len+=b.len;
				a.s[i]='\0';
				for(i=0;i<a.len;i++)
					a.pr[i]=a.freq[i];
			}
		}
		if(a.len<memo[st][end].len)
			memo[st][end]=a;
	}
	return memo[st][end];
}

int main()
{
	int i,j,ln;
	factor ans;
	while(scanf("%s",given)==1)
	{
		if(given[0]=='*')
			break;
		ln=strlen(given);
		for(i=0;i<ln;i++)
			for(j=0;j<ln;j++)
				memo[i][j].len=100000;
		ans=make(0,ln-1);
		printf("%d\n",ans.len);
	}
	return 0;
}
