#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
	int n,num[205],cyc[205],i,j,k,cs=0,len,t;
	char s[300],g[300],buf[300];
	while(scanf("%d",&n)==1)
	{
		if(!n)
			break;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			cyc[i]=1;
		}
		gets(buf);
		for(i=1;i<=n;i++)
		{
			j=num[i];
			while(num[j]!=num[i])
			{
				cyc[i]++;
				j=num[j];
			}
		}
		while(gets(buf))
		{
			sscanf(buf,"%d",&k);
			if(!k)break;
			i=0;
			while(isdigit(buf[i]))
				i++;
			for(i++,j=0;buf[i];i++,j++)
				g[j]=buf[i];
			g[j]='\0';
			len=strlen(g);
			if(len<n)
				for(i=len;i<n;i++)
					g[i]=' ';
			g[i]='\0';
			for(i=0;i<n;i++)
			{
				t=num[i+1];
				if(k%cyc[i+1])
					len=k%cyc[i+1];
				else
					len=cyc[i+1];
				for(j=1;j<len;j++)
					t=num[t];
				s[t-1]=g[i];
			}
			s[n]='\0';
			printf("%s\n",s);
		}
		printf("\n");
	}
	return 0;
}













