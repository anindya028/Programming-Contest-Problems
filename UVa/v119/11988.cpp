#include<stdio.h>
#include<string.h>

char s[1000005];

char ans[1000000];
int nd,st;

int main()
{
	while(gets(s))
	{
		st = 200000;
		nd = st;
		int cnt = 0;
		int state = 0,i,j;
		for( i  = 0;s[i];)
		{
			if(s[i]=='[')
			{
				for(j=i+1;s[j] && s[j]!=']' && s[j]!='[';j++);
				int v = j;
				for(j--;j>i;j--)
				{
					st--;
					ans[st] = s[j];
				}
				i = v;
			}
			else if(s[i]==']')
			{
				i++;
			}
			else
			{	
				ans[nd] = s[i], nd++;
				i++;
			}
		}
		for(i=st;i<nd;i++)
			printf("%c",ans[i]);
		printf("\n");
	}
	return 0;
}