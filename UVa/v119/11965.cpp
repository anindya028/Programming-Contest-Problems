#include<stdio.h>
#include<string.h>

char s[1005],ss[1005];

int main()
{
	int t,cs,n,i;
	gets(s);
	sscanf(s,"%d",&t);
	for(cs=1;cs<=t;cs++)
	{
		gets(s);
		sscanf(s,"%d",&n);
		printf("Case %d:\n",cs);
		for(i=0;i<n;i++)
		{
			gets(s);
			int j,k,x=0;
			for(j=0;s[j];)
			{
				ss[x++] = s[j];
				
				for(k=j+1;s[k] && s[k]==' ' && s[j]==s[k];k++);

				j = k;
			}
			ss[x] = 0;
			puts(ss);
		}
		if(cs<t)
			printf("\n");
	}
	return 0;
}