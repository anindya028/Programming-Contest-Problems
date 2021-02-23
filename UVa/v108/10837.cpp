#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;

#define SIZE 15000
#define inf 1<<30
#define Min(a,b) ((a)<(b)?(a):(b))

int pr[5000],m;
bool p[SIZE];
int ans,last;
vector<int> prm;

int gene(int n)
{
	int root=ceil(sqrt((double)n));
    int i,j;
	for(i=3;i<=root;i+=2)
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

void make(int nowp,int n,int got)
{
	int i,now,j,f=0;
	if(got<0)
		return;
	if(n==1)
	{
		ans=Min(ans,got);
		return;
	}
	if(got>ans)
		return;
	for(i=nowp;i<prm.size() && prm[i]<=(n+1) && got*(prm[i]-1)<ans;i++)
	{
		now=prm[i]-1;
		j=prm[i];
		while(n%now==0)
		{
			make(i+1,n/now,got*j);
			j*=prm[i];
			now*=prm[i];
		}
	}
	for(i=0;pr[i]*pr[i]<=(n+1) && !f && i<m;i++)
		if((n+1)%pr[i]==0)
			f=1;
	if(!f && (n+1)>last)	
		make(nowp+1,1,got*(n+1));
}

int main()
{
	m=gene(SIZE*2);	
	int n,cs=0,i;
	while(scanf("%d",&n)==1 && n)
	{
		ans=inf;
		if(n==1)
		{
			printf("Case %d: %d 1\n",++cs,n);
			continue;
		}
		prm.clear();
		for(i=0;i<m && pr[i]<=(n+1);i++)
			if(n%(pr[i]-1)==0)
			{
				prm.push_back(pr[i]);
				last=pr[i];
			}
		make(0,n,1);
		printf("Case %d: %d %d\n",++cs,n,ans);
	}
	return 0;
}