#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;	
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

#define SIZE 150
int pr[100];
bool p[SIZE];
int gene(int n)
{
    int i,j;
	for(i=3;i*i<=n;i+=2)
	{
		if(!p[i/2])
		{
			for(j=i*i;j<n+1;j+=(2*i))p[j/2]=1;
		}
	}
	j=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
	{
		if(!p[i])
        {
			pr[j]=i*2+1;
			j++;
        }
	}
    return j;
}

int dp[1005][16][72][2];

bool comp(int a,int b)
{
	char sa[10],sb[10];
	string ssa,ssb;
	sprintf(sa,"%d",a),ssa=sa;
	sprintf(sb,"%d",b),ssb=sb;
	return ssa<ssb;
}

vector<int> data;

int make(int now,int rem,int pos,int f)
{
	if(!rem)
		return !now;
	if(pos==SZ(data))
		return 0;
	if(now<=0)
		return 0;
	if(dp[now][rem][pos][f]!=-1)
		return dp[now][rem][pos][f];
	int i;
	dp[now][rem][pos][f]=0;
	if(!f)
		dp[now][rem][pos][f]=dp[now][rem][pos][f] | make(now-data[pos],rem-1,pos,f+1);
	if(data[pos]!=2 && f==1)
		dp[now][rem][pos][f]=dp[now][rem][pos][f] | make(now-data[pos],rem-1,pos+1,0);
	for(i=pos+1;i<data.size();i++)
		dp[now][rem][pos][f]=dp[now][rem][pos][f] | make(now-data[i],rem-1,i,1);
	return dp[now][rem][pos][f];
}

int main()
{
	int m=gene(SIZE*2);
	int i,j,n,len,cs=0,f,prev;
	data.clear();
	Foro(i,m)
		data.push_back(pr[i]);
	sort(data.begin(),data.end(),comp);
	vector<int> vi;
	memset(dp,-1,sizeof(dp));
	while(scanf("%d%d",&n,&len)==2 && n)
	{
		printf("CASE %d:\n",++cs);
		vi.clear();
		if(make(n,len,0,0))
		{
			prev=0;
			f=0;
			j=len;
			while(n)
			{
				if(!f)
					if(make(n-data[prev],j-1,prev,1))
					{
						vi.push_back(data[prev]);
						j--,n-=data[prev],f=1;
						continue;
					}
				if(data[prev]!=2 && f==1 && make(n-data[prev],j-1,prev+1,0))
				{
					vi.push_back(data[prev]);
					j--,n-=data[prev],f=0;
					prev++;
					continue;
				}
				for(i=prev+1;i<data.size();i++)
					if(make(n-data[i],j-1,i,1))
					{
						vi.push_back(data[i]);
						j--,n-=data[i],f=1,prev=i;
						break;
					}
			}
			printf("%d",vi[0]);
			for(i=1;i<vi.size();i++)
				printf("+%d",vi[i]);
			printf("\n");
		}
		else
			printf("No Solution.\n");
	}
	return 0;
}