#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define inf 10000000
int main()
{
	char s[100][100];
	int n,i,j,k,l,m,ans,c;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		for(i=ans=0;i<n;i++)
			for(j=0;j<n;j++)
				if(s[i][j]=='1')
				{
					for(m=inf,k=0;k<n;k++)
						for(l=0;l<n;l++)
						{
							if(s[k][l]=='3')
							{
								c=abs(k-i)+abs(l-j);
								if(c<m)
									m=c;
							}
						}
					if(m>ans)
						ans=m;
				}
		printf("%d\n",ans);
	}
	return 0;
}













