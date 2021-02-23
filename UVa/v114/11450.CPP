#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;	


double dist(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
//#define Long __int64
//#define Long long long


int main()
{
	int t,cs,i,j,k,perm[500],temp[500],m,c,n[30],price[30][30];
	scanf("%d",&t);
	For(cs,0,t)
	{
		scanf("%d%d",&m,&c);
		For(i,0,c)
		{
			scanf("%d",&n[i]);
			For(j,0,n[i])
				scanf("%d",&price[i][j]);
		}
		Fore(i,0,m)
			perm[i]=temp[i]=0;
		perm[0]=1;
		For(i,0,c)
		{
			For(j,0,n[i])
				For(k,0,m)
					if(perm[k])
						if(k+price[i][j]<=m)
							temp[k+price[i][j]]=1;
			Fore(j,0,m)
				perm[j]=temp[j],temp[j]=0;
		}
		for(i=m;i>0;i--)
			if(perm[i])
				break;
		if(!i)
			printf("no solution\n");
		else
			printf("%d\n",i);
	}
	return 0;
}
