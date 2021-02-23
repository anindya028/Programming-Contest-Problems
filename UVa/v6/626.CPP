#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct triple
{
	int a,b,c;
}t[100000];
int main()
{
	int n,mat[105][105],i,j,k,count;
	while(scanf("%d",&n)==1)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&mat[i][j]);
		count=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				for(k=1;k<=n;k++)
					if(mat[i][j] && mat[j][k] && mat[k][i] && ((i>j && j>k) || (i<j && j<k)))
					{
						t[count].a=i;
						t[count].b=j;
						t[count].c=k;
						count++;
					}
		for(i=0;i<count;i++)
			printf("%d %d %d\n",t[i].a,t[i].b,t[i].c);
		printf("total:%d\n\n",count);
	}
	return 0;
}













