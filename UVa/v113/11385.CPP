//Adhoc
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;
	

int main()
{
	char s[1000],g[1000],h[1000];
	int fib[50],i,j,given[50],n,t,k,mx;
	fib[0]=1;
	fib[1]=2;
	for(i=2;i<46;i++)
		fib[i]=fib[i-1]+fib[i-2];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&given[i]);
		gets(s);
		gets(s);
		for(i=j=0;s[i];i++)
			if(s[i]>='A' && s[i]<='Z')
			{
				g[j]=s[i];
				j++;
			}
		g[j]='\0';
		for(i=0;i<105;i++)
			h[i]=' ';
		mx=-1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<45;j++)
				if(given[i]==fib[j])
				{
					k=j;
					break;
				}
			if(k>mx)
				mx=k;
			h[k]=g[i];
		}
		h[mx+1]='\0';
		printf("%s\n",h);
	}
	return 0;
}
