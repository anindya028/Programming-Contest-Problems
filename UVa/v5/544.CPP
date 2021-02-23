#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 1000000000
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b)) 
int main()
{
	char s1[100],s2[100],city[202][100];
	int n,r,mat[202][202],i,j,k,w,count,c1,c2,cs=0;
	while(scanf("%d%d",&n,&r)==2)
	{
		if(!n && !r)break;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				mat[i][j]=-inf;
		count=0;
		for(i=1;i<=r;i++)
		{
			scanf("%s%s%d",s1,s2,&w);
			c1=c2=0;
			for(j=1;j<=count;j++)
			{
				if(!strcmp(s1,city[j]))
					c1=j;
				if(!strcmp(s2,city[j]))
					c2=j;
			}
			if(!c1)
			{
				count++;
				strcpy(city[count],s1);
				c1=count;
			}
			if(!c2)
			{
				count++;
				strcpy(city[count],s2);
				c2=count;
			}
			mat[c1][c2]=mat[c2][c1]=w;
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					mat[i][j]=mat[j][i]=max(mat[i][j],min(mat[i][k],mat[k][j]));
		scanf("%s%s",s1,s2);
		for(j=1;j<=count;j++)
		{
			if(!strcmp(s1,city[j]))
				c1=j;
			if(!strcmp(s2,city[j]))
				c2=j;
		}
		printf("Scenario #%d\n%d tons\n\n",++cs,mat[c1][c2]);
	}
	return 0;
}













