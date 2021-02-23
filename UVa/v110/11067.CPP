#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;

#define Max(a,b) (((a)>(b))?(a):(b))	
//#define Long __int64
#define Long long long 

Long mat[105][105];

int main()
{
	int n,w,h,x,y;
	register int i,j;
	while(scanf("%d%d",&w,&h)==2)
	{
		if(!w && !h)
			break;
		for(i=0;i<=w;++i)
			for(j=0;j<=h;++j)
				mat[i][j]=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&x,&y),mat[x][y]=-1;
		mat[0][0]=1;
		for(i=1;i<=w;i++)
			if(mat[i-1][0]==1 && !mat[i][0])
				mat[i][0]=1;
			else
				break;
		for(i=1;i<=h;i++)
			if(mat[0][i-1]==1 && !mat[0][i])
				mat[0][i]=1;
			else
				break;
		for(i=1;i<=w;++i)
			for(j=1;j<=h;++j)
				if(!mat[i][j])
				{
					if(mat[i-1][j]>=0 && mat[i][j-1]>=0)
						mat[i][j]=mat[i-1][j]+mat[i][j-1];
					else if(mat[i-1][j]>=0)
						mat[i][j]=mat[i-1][j];
					else 
						mat[i][j]=mat[i][j-1];
				}
		if(mat[w][h]<=0)
			printf("There is no path.\n");
		else if(mat[w][h]==1)
			printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
		else 
			printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n",mat[w][h]);
	}
	return 0;
}
