#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<algorithm>
using namespace std;
#define Max 105
#define inf 210000000
int main()
{
	int mat[Max][Max];
	int i,j,k,t,n;
	char s[15];
	while(scanf("%d",&n)==1)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				mat[i][j]=inf;
		for(i=2;i<=n;i++)
		{
			for(j=1;j<i;j++)
			{
				scanf("%s",s);
				if(isdigit(s[0]))
				{
					sscanf(s,"%d",&mat[i][j]);
					mat[j][i]=mat[i][j];
				}
			}
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
					if((mat[i][k]+mat[k][j])<mat[i][j])
						mat[i][j]=mat[j][i]=mat[i][k]+mat[k][j];
				}
		t=0;
		for(i=1;i<=n;i++)
		{
			if(mat[1][i]>t && mat[1][i]!=inf)
				t=mat[1][i];
		}
		printf("%d\n",t);
	}
	return 0;
}













