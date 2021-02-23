#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
	int cs,t,i,j,k;
	int ans[10][10];
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		for(i=1;i<=9;i+=2)
			for(j=1;j<=i;j+=2)
				scanf("%d",&ans[i][j]);
		for(i=2;i<9;i+=2)
			ans[9][i]=(ans[7][i-1]-ans[9][i-1]-ans[9][i+1])/2;
		for(i=8;i>1;i--)
			for(j=1;j<=i;j++)
				ans[i][j]=ans[i+1][j]+ans[i+1][j+1];
		for(i=1;i<=9;i++)
		{
			printf("%d",ans[i][1]);
			for(j=2;j<=i;j++)
				printf(" %d",ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}













