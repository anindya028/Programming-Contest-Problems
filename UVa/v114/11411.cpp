#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define Max(a,b) (((a)>(b))?(a):(b))
#define size 5000
int pr[5000];
bool p[size];
int gene(int n)
{
    int i,j;
	for(i=3;i*i<=n;i+=2)
		if(!p[i/2])
			for(j=i*i;j<n+1;j+=(2*i))
				p[j/2]=1;
	j=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
		if(!p[i])
			pr[j]=i*2+1,j++;
    return j;
}

int fact[5000005];

int freq[500];

int main()
{
	int m=gene(size*2);
	int n,a,b,flag,cnt,prevst,prevnd,ans,cs,t;
	register int i,j;
	fact[1]=1;
	for(i=2;i<5000001;++i)
	{
		n=i;
		flag=0;
		cnt=0;
		for(j=0;pr[j]*pr[j]<=n;++j)
			if(n%pr[j]==0)
			{
				while(n%pr[j]==0)
					n/=pr[j],cnt++;
				fact[i]=fact[n]*(cnt+1);
				flag=1;
				break;
			}
		if(!flag)
			fact[i]=2;
	}
	scanf("%d",&t);
	for(cs=0;cs<t;++cs)
	{
		scanf("%d%d",&a,&b);
		for(i=1;i<=400;++i)
			freq[i]=0;
		for(i=a;i<=b;++i)
			freq[fact[i]]++;
		prevst=prevnd=ans=0;
		i=1;
		while(!prevst || !prevnd)
		{
			if(freq[i]>=2)
			{
				if(!prevnd && prevst)
					ans=Max(ans,i-prevst);
				prevst=prevnd=i; 
			}
			else if(freq[i])
			{
				if(!prevst)
					prevst=i;
				else
					prevnd=i,ans=Max(ans,prevnd-prevst);
			}
			++i;
		}
		for(;i<=400;++i)
			if(freq[i])
			{
				if(freq[i]>=2)
				{
					ans=Max(ans,i-prevnd);
					ans=Max(ans,i-prevst);
					prevnd=prevst=i;
				}
				else if(freq[i])
				{
					if(prevnd>prevst)
						ans=Max(ans,i-prevst),prevst=i;
					else
						ans=Max(ans,i-prevnd),prevnd=i;
				}
			}
		ans=Max(ans,abs(prevnd-prevst));
		printf("%d\n",ans);
	}
	return 0;
}