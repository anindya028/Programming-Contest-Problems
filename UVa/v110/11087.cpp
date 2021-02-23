
//this is a O(2*n*log n) solution,
//unfotunately it gets TLE
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
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

vector<int> pos[505];
int num[100005],d[100005];

int binsearch(int now,int key)
{
	int low=0,high=pos[now].size()-1,mid;
	if(!pos[now].size())
		return 0;
	while(low<high)
	{
		mid=(low+high)/2;
		if(pos[now][mid]>key)
			high=mid;
		else
			low=mid+1;
	}
	if(pos[now][low]>key)
		return low;
	else
		return pos[now].size();
}

int main()
{
	int t,cs,i,k,n,j,cnt,m;
	long long ans;
	//freopen("divisible.in","r",stdin);
	//freopen("11087.txt","w",stdout);
	scanf("%d",&t);
	Foro(cs,t)
	{
		scanf("%d%d",&n,&k);
		Foro(i,n)
			scanf("%d",&num[i]);
		sort(num,num+n);
		ans=0;
		for(i=m=0;i<n;i++)
		{
			cnt=1;
			j=i+1;
			while(j<n && num[j]==num[i])
				j++,cnt++;
			if(abs(num[i]*2)%k==0 && cnt>1)
				ans++;
			d[m++]=num[i];
			i=j-1;
		}
		Foro(i,k)
			pos[i].clear();
		Foro(i,m)
			d[i]=(k * (abs(d[i])/k + 1) + d[i])%k,pos[d[i]].pb(i);
		Foro(i,m)
		{
			j=binsearch((k-d[i])%k,i);
			ans+=(pos[(k-d[i])%k].size()-j);
		}
		printf("Case %d: %lld\n",cs+1,ans);
	}
	return 0;
}


//Judge solution-> O(k^2 + nlog(n))
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
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

int num[100005],d[100005],freq[505];

int main()
{
	int t,cs,i,k,n,j,cnt,m;
	long long ans;
	scanf("%d",&t);
	Foro(cs,t)
	{
		scanf("%d%d",&n,&k);
		Foro(i,n)
			scanf("%d",&num[i]);
		sort(num,num+n);
		ans=0;
		for(i=m=0;i<n;i++)
		{
			cnt=1;
			j=i+1;
			while(j<n && num[j]==num[i])
				j++,cnt++;
			if(abs(num[i]*2)%k==0 && cnt>1)
				ans++;
			d[m++]=num[i];
			i=j-1;
		}
		Foro(i,k)
			freq[i]=0;
		Foro(i,m)
			freq[((d[i] % k) + k) % k ]++;
		Foro(i,k)
			For(j,i,k)
				if((i+j)%k==0)
					if(i==j)
						ans+=((freq[i]*(freq[i]-1))/2);
					else
						ans+=freq[i]*freq[j];
		printf("Case %d: %lld\n",cs+1,ans);
	}
	return 0;
}