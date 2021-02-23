#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Max 50
#define inf 21000000
int main()
{
	int mat[Max][Max];
	char s[35][5],temp1[5],temp2[5];
	int i,j,k,cost,st,t,n,e,q,N,cs;
	scanf("%d",&N);
	printf("SHIPPING ROUTES OUTPUT\n\n");
	for(cs=0;cs<N;)
	{
		scanf("%d%d%d",&n,&e,&q);
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				mat[i][j]=inf;
		for(i=1;i<=n;i++)
		{
			scanf("%s",s[i]);
		}
		for(i=0;i<e;i++)
		{
			scanf("%s%s",temp1,temp2);
			for(j=1;j<=n;j++)
			{
				if(!strcmp(s[j],temp1))
				{
					st=j;
					break;
				}
			}
			for(j=1;j<=n;j++)
			{
				if(!strcmp(s[j],temp2))
				{
					t=j;
					break;
				}
			}
			mat[st][t]=mat[t][st]=1;
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
					if((mat[i][k]+mat[k][j])<mat[i][j])
						mat[i][j]=mat[i][k]+mat[k][j];
				}
		printf("DATA SET  %d\n\n",++cs);
		for(i=0;i<q;i++)
		{
			scanf("%d%s%s",&cost,temp1,temp2);
			for(j=1;j<=n;j++)
			{
				if(!strcmp(s[j],temp1))
				{
					st=j;
					break;
				}
			}
			for(j=1;j<=n;j++)
			{
				if(!strcmp(s[j],temp2))
				{
					t=j;
					break;
				}
			}
			if(mat[st][t]==inf)printf("NO SHIPMENT POSSIBLE\n");
			else printf("$%d\n",mat[st][t]*cost*100);
		}
		printf("\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}













