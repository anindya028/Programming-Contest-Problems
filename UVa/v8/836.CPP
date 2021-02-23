#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int t,r,c,c1,n,mat[30][30],sum[30][30],max,runsum,inf=-11111,i;
    char s[30];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		if(i)printf("\n");
		scanf("%s",s);
		n=strlen(s);
		for(c=1;c<=n;c++)
		{
			mat[1][c]=s[c-1]-'0';
			if(!mat[1][c])mat[1][c]=inf;
		}
		for(r=2;r<=n;r++)
		{
			scanf("%s",&s);
			for(c=1;c<=n;c++)
			{
				mat[r][c]=s[c-1]-'0';
				if(!mat[r][c])mat[r][c]=inf;
			}
		}
		for(r=1;r<=n;r++)
			for(c=1;c<=n;c++)
				sum[r][c]=mat[r][c]+sum[r][c-1];
		max=inf;
		for(c=1;c<=n;c++)
		{
			for(c1=c;c1<=n;c1++)
			{
				runsum=0;
				for(r=1;r<=n;r++)
				{
					runsum+=sum[r][c1]-sum[r][c-1];
					if(runsum>max)max=runsum;
					if(runsum<0)runsum=0;
				}
			}
		}
		if(max>0)printf("%d\n",max);
		else printf("0\n");
	}
	return 0;
}













