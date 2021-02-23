#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

double stir2nd[105][105],fact[102];

double gene(int n,int m)
{
	if(stir2nd[n][m]>(-1.))
		return stir2nd[n][m];
	stir2nd[n][m]=(double)m*gene(n-1,m)+gene(n-1,m-1);
	return stir2nd[n][m];
}

int main()
{
	int i,j,n,m,cs=0;
	fact[0]=1.;
	for(i=1;i<102;i++)
		for(j=2;j<102;j++)
			stir2nd[i][j]=-1.;
	for(i=1;i<102;i++)
	{
		stir2nd[i][1]=stir2nd[i][i]=1.0;
		fact[i]=fact[i-1]*(double)i;
	}
	while(scanf("%d",&n)==1)
	{
		if(n==-1)break;
		scanf("%d",&m);
		printf("Case %d: %.7lf\n",++cs,1.0-((gene(n,m)/pow((double)m,(double)(n-n/2)))*(fact[m]/pow((double)m,(double)(n/2)))));
	}
	return 0;
}













