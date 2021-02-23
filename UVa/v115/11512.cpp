#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<string>
using namespace std;	

#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define inf 1<<29
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

char s[1005];
int power[1005],hash[1005];
//hash
#define base 31
#define mod 45347

struct match
{
	string str;
	int freq;
}x;

bool operator<(match a,match b)
{
	return a.str<b.str;
}

bool check(int st1,int nd1,int st2,int nd2)
{
	int i,j;
	for(i=st1,j=st2;i<=nd1;i++,j++)
		if(s[i]!=s[j])
			return false;
	return true;
}

vector<match> findg(int len)
{
	vector<match> now;
	int i,slen=strlen(s),j,a,b,cnt;
	bool got[1005];
	for(i=0;s[i];i++)
		got[i]=false;
	for(i=0;i+len<slen;++i)
	{
		if(got[i])
			continue;
		if(!i)
			a=hash[i+len-1];
		else
			a=(hash[i+len-1]- (hash[i-1]*power[len])%mod+mod)%mod;
		cnt=1;
		for(j=i+1;j<slen;++j)
		{
			b=(hash[j+len-1]- (hash[j-1]*power[len])%mod+mod)%mod;
			if(a==b && check(i,i+len-1,j,j+len-1))
				got[j]=1,cnt++;
		}
		if(cnt>1)
		{
			x.str="";
			x.freq=cnt;
			for(j=i;j<i+len;j++)
				x.str+=s[j];
			now.push_back(x);
		}
	}
	return now;
}

int main()
{
	int t,i,low,high,mid;
	vector<match> now,prev;
	power[0]=1;
	for(i=1;i<1003;++i)
		power[i]=(power[i-1]*base)%mod;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		now.clear(),prev.clear();
		hash[0]=s[0];
		for(i=1;s[i];++i)
			hash[i]=(hash[i-1]*base+s[i])%mod;
		low=1,high=strlen(s);
		while(low<=high)
		{
			mid=(low+high)/2;
			now.clear();
			now=findg(mid);
			if(SZ(now)>0)
				low=mid+1,prev=now;
			else
				high=mid-1;
		}
		sort(prev.begin(),prev.end());
		if(SZ(prev)>0)
		{
			Forc(i,prev[0].str)
				printf("%c",prev[0].str[i]);
			printf(" %d\n",prev[0].freq);
		}
		else
			printf("No repetitions found!\n");
	}
	return 0;
}