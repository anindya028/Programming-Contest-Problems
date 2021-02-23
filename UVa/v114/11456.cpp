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

#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

int lis[2005],lds[2005],num[2005],n;

int makei(int i)
{
	int temp,j;
	if(lis[i])
		return lis[i];
	for(j=i+1;j<n;j++)
	{
		temp=makei(j);
		if(num[j]>num[i] && temp>lis[i])
			lis[i]=temp;
	}
	lis[i]++;
	return lis[i];
}

int maked(int i)
{
	int temp,j;
	if(lds[i])
		return lds[i];
	for(j=i+1;j<n;j++)
	{
		temp=maked(j);
		if(num[j]<num[i] && temp>lds[i])
			lds[i]=temp;
	}
	lds[i]++;
	return lds[i];
}

int main()
{
	int t,cs,i,mx;
	scanf("%d",&t);
	Foro(cs,t)
	{
		scanf("%d",&n);
		Foro(i,n)
			scanf("%d",&num[i]),lis[i]=lds[i]=0;
		mx=0;
		Foro(i,n)
			mx=Max(mx,makei(i)+maked(i)-1);
		printf("%d\n",mx);
	}
    return 0;
}
