#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<string>
using namespace std;	

#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define NC2(n) (((n)*((n)-1))/2)
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

long long nump[200005],numn[200005],nc2,nc3;
long long cntp[1<<12],cntn[1<<12],cntp2[1<<12],cntn2[1<<12];
int pr[]={2,3,5,7,11,13,17,19,23,29};

int main()
{
	int t,i,j,freq[12],k;
	long long n,pos,neg,zero,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n==1)
		{
			scanf("%lld",&temp);
			printf("0 0\n");
			continue;
		}
		pos=neg=zero=0;
		//input
		Foro(i,n)
		{
			scanf("%lld",&temp);
			if(temp<0)
				numn[neg++]=-temp;
			else if(temp>0)
				nump[pos++]=temp;
			else
				zero++;
		}
		//zero
		nc2=NC2(zero);
		nc3=(zero*(zero-1)*(zero-2))/6;
		nc2+=zero*(n-zero);
		nc3+=zero*NC2(n-zero);
		nc3+=NC2(zero)*(n-zero);
		//process
		Foro(i,1<<10)		
			cntp[i]=cntn[i]=cntp2[i]=cntn2[i]=0;
		Foro(i,pos)
		{
			temp=nump[i];
			Foro(j,10)
				freq[j]=0;
			for(j=0;j<10 && temp>1;++j)
				while(temp%pr[j]==0)
					temp/=pr[j],
					freq[j]++;
			k=0;
			Foro(j,10)
				if(freq[j]%2)
					k+=(1<<j);
			cntp[k]++;
		}
		Foro(i,neg)
		{
			temp=numn[i];
			Foro(j,10)
				freq[j]=0;
			for(j=0;j<10 && temp>1;++j)
				while(temp%pr[j]==0)
					temp/=pr[j],
					freq[j]++;
			k=0;
			Foro(j,10)
				if(freq[j]%2)
					k+=(1<<j);
			cntn[k]++;
		}
		For(i,1,1<<10)
			For(j,i,1<<10)
				if(j==i)
					cntp2[i^j]+=NC2(cntp[i]),cntn2[i^j]+=NC2(cntn[i]);
				else
					cntp2[i^j]+=(cntp[i]*cntp[j]),cntn2[i^j]+=(cntn[i]*cntn[j]);
		//nc2
		Foro(i,1<<10)
			nc2+=NC2(cntp[i]),
			nc2+=NC2(cntn[i]);
		//nc3
		nc3+=(cntp[0]*(cntp[0]-1)*(cntp[0]-2))/6;
		nc3+=(NC2(cntn[0])*cntp[0]);
		nc3+=(cntp2[0]*cntp[0]);
		nc3+=(cntn2[0]*cntp[0]);
		temp=0;
		For(i,1,1<<10)
			temp+=(cntp2[i]*cntp[i]),
			nc3+=(cntn2[i]*cntp[i]),
			nc3+=(cntp[i]*cntn[i]*cntn[0]);
		nc3+=(temp/3);
		//output
		printf("%lld %lld\n",nc2,nc3);
	}
	return 0;
}