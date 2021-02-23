#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
	char text[]="_abcdefghijklmnopqrstuvwxyz.";
	char g[100],s[100];
	int d[100],i,k,n,j;
	while(scanf("%d",&k)==1)
	{
		if(!k)break;
		scanf("%s",g);
		n=strlen(g);
		for(i=0;i<n;i++)
			for(j=0;j<28;j++)
				if(g[i]==text[j])
					d[i]=j;
		for(i=0;i<n;i++)
			s[(k*i)%n]=text[(d[i]+i)%28];
		s[i]='\0';
		printf("%s\n",s);
	}
	return 0;
}













