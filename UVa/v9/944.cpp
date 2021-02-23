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

int sumsq(int n)
{
	int ret=0;
	while(n)
	{
		ret+=sq(n%10);
		n/=10;
	}
	return ret;
}

int num[100005],len[100005];

int happy(int n)
{
	if(num[n]==3)
	{
		if(n==1)
			return 1;
		else
			return -1;
	}
	if(num[n])
		return len[n];
	int temp=sumsq(n),u;
	num[n]=3;
	u=happy(temp);
	if(u==-1)
		len[n]=-1,num[n]=2;
	else
		len[n]=u+1,num[n]=1;
	return len[n];
}

int main()
{
	int i,l,h,cs=0;
	Foro(i,100003)
		num[i]=len[i]=0;
	num[0]=num[1]=1;
	len[1]=1;
	Foro(i,100003)
		if(!num[i])
			len[i]=happy(i);
	while(scanf("%d%d",&l,&h)==2)
	{
		if(cs)
			printf("\n");
		cs++;
		for(i=l;i<=h;i++)
			if(num[i]==1)
				printf("%d %d\n",i,len[i]);
	}
	return 0;
}
