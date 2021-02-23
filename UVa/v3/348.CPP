#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define max 15
#define inf 2000000000
int num;
void print(unsigned long s[][max],int i,int j)
{
	if(i==j)
		printf("A%d",num++);
	else
	{
		printf("(");
		print(s,i,s[i][j]);
		printf(" x ");
		print(s,s[i][j]+1,j);
		printf(")");
	}
	return;
}
void mat_order(int *p,int n)
{
	unsigned long m[max][max]={0};
	unsigned long s[max][max]={0};
	unsigned long q;
	int i,j,k,l;
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=(n-l+1);i++)
		{
			j=i+l-1;
			m[i][j]=inf;
			for(k=i;k<j;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	num=1;
	print(s,1,n);
	return;
}
int main()
{
	int n,i,cs=0;
	int p[max]={0};
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		for(i=1;i<=n;i++)
			scanf("%d%d",&p[i-1],&p[i]);
		printf("Case %d: ",++cs);
		mat_order(p,n);
		printf("\n");
	}
	return 0;
}













