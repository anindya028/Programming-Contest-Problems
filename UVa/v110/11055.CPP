//Tricky DP(?)
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
int mat[1005][1005];
int main()
{
	int i,j,n,flag;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&mat[i][j]);
		if(n==1)
		{
			printf("homogeneous\n");
			continue;
		}
		flag=1;
		for(i=1;i<n && flag;i++)
			for(j=1;j<n && flag;j++)
				if((mat[i][j]+mat[i-1][j-1])!=(mat[i-1][j]+mat[i][j-1]))
					flag=0;
		if(flag)
			printf("homogeneous\n");
		else
			printf("not homogeneous\n");
	}
	return 0;
}













