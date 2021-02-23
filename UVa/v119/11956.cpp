#include<stdio.h>
#include<string.h>

char s[100005];
int val[105];

int main()
{
	char out[] = "0123456789ABCDEF";
	int t,cs,i;
	gets(s);
	sscanf(s,"%d",&t);
	for(cs=1;cs<=t;cs++)
	{
		gets(s);
		memset(val,0,sizeof(val));
		int now = 0;
		for(i=0;s[i];i++)
		{
			if(s[i]=='.')
				continue;
			if(s[i]=='<')
				now = (now-1+100)%100;
			else if(s[i]=='>')
				now = (now+1)%100;
			else if(s[i]=='+')
				val[now] = (val[now]+1)%256;
			else if(s[i]=='-')
				val[now] = (val[now]-1+256)%256;
		}
		printf("Case %d:",cs);
		for(i=0;i<100;i++)
			printf(" %c%c",out[val[i]/16],out[val[i]%16]);
		printf("\n");
	}
	return 0;
}