#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

#define SIZE 20000

int pr[6000],m;
bool p[SIZE];
int last;
vector<int> prm;
vector<long long> ans;

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

void make(int nowp,long long n,long long got)
{
	int i,f=0;
	long long j,now;
	if(n==1)
	{
		ans.push_back(got);
		return;
	}
	for(i=nowp;i<prm.size() && prm[i]<=(n+1);i++)
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
	int n,i;
	while(scanf("%d",&n)==1)
	{
		ans.clear();
		if(n==1)
		{
			printf("1 2\n");
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
		if((int)(ans.size())==0)
			printf("No solution.\n");
		else
		{
			sort(ans.begin(),ans.end());
			printf("%lld",ans[0]);
			for(i=1;i<ans.size();i++)
				printf(" %lld",ans[i]);
			printf("\n");
		}
	}
	return 0;
}