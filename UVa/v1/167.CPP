#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int queen,cost,maxcost;
int mat[8][8],col[8],diag[8][8][8];
void gene(void)
{
	int j,i,k,flag;
	if(queen==8)
	{

		if(cost>maxcost)
			maxcost=cost;
		return;
	}
	for(j=0;j<8;j++)
	{
		for(i=flag=0;i<queen;i++)
			if(diag[i][queen][j])
				flag=1;
		if(flag || col[j])continue;
		col[j]=1;
		cost+=mat[queen][j];
		for(i=queen,k=j;i<8 && k<8;i++,k++)
			diag[queen][i][k]=1;
		for(i=queen,k=j;i<8 && k>=0;i++,k--)
			diag[queen][i][k]=1;
		queen++;
		gene();
		queen--;
		for(i=queen,k=j;i<8 && k<8;i++,k++)
			diag[queen][i][k]=0;
		for(i=queen,k=j;i<8 && k>=0;i++,k--)
			diag[queen][i][k]=0;
		cost-=mat[queen][j];
		col[j]=0;
	}
	return;
}
int main()
{
	int n,i,j,k,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<8;j++)
		{
			for(k=0;k<8;k++)
			{
				scanf("%d",&mat[j][k]);
			}
			col[j]=0;
		}
		for(m=0;m<8;m++)
			for(j=0;j<8;j++)
				for(k=0;k<8;k++)
					diag[m][j][k]=0;
		maxcost=cost=queen=0;
		gene();
		printf("%5d\n",maxcost);
	}
	return 0;
}













