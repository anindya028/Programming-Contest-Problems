#include<stdio.h>
#include<string.h>

int main()
{
	char s[1000];
	int cnt=0;
	while(gets(s))
	{
		int i,f;
		for(i=0;s[i];i++)
			if(s[i]=='+')
				f=1,s[i]=' ';
			else if(s[i]=='-')
				f=-1,s[i]=' ';
			else if(s[i]=='=')
				s[i]=' ';
			else if(s[i]=='?')
				goto done;
		int a,b,c;
		sscanf(s,"%d%d%d",&a,&b,&c);
		if(c== a + f*b)
			cnt++;
done:;
	}
	printf("%d\n",cnt);
	return 0;
}