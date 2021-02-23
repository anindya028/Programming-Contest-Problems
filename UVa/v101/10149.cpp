#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

#define Max(a,b) (((a)>(b))?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))

int dp[1<<13][13],parent[1<<13][13],round[13][5];

int calc(int pos,int now)
{
	int i,sum=0;
	if(now<6)
	{
		for(i=0;i<5;i++)
			if(round[pos][i]==(now+1))
				sum+=round[pos][i];
		return sum;
	}
	else if(now<=9)
	{
		for(i=0;i<5;i++)
			sum+=round[pos][i];
		if(now==6)
			return sum;
		int f[7]={0};
		for(i=0;i<5;i++)
			f[round[pos][i]]++;
		if(now==7)
		{
			for(i=1;i<=6;i++)
				if(f[i]>=3)
					return sum;
			return 0;
		}
		if(now==8)
		{
			for(i=1;i<=6;i++)
				if(f[i]>=4)
					return sum;
			return 0;
		}
		if(now==9)
		{
			for(i=1;i<=6;i++)
				if(f[i]==5)
					return 50;
			return 0;
		}
	}
	else if(now==10)
	{
		int f[7]={0};
		for(i=0;i<5;i++)
			f[round[pos][i]]++;
		if(f[1] && f[2] && f[3] && f[4])
			return 25;
		if(f[5] && f[2] && f[3] && f[4])
			return 25;
		if(f[5] && f[6] && f[3] && f[4])
			return 25;
		return 0;
	}
	else if(now==11)
	{
		int f[7]={0};
		for(i=0;i<5;i++)
			f[round[pos][i]]++;
		if(f[1] && f[2] && f[3] && f[4] && f[5])
			return 35;
		if(f[6] && f[2] && f[3] && f[4] && f[5])
			return 35;	
		return 0;
	}
	else
	{
		int f[7]={0};
		for(i=0;i<5;i++)
			f[round[pos][i]]++;
		int three=0,two=0;
		for(i=1;i<=6;i++)
			if(f[i]==3)
				three=1;
			else if(f[i]==2)
				two=1;
		if(two && three)
			return 40;
		return 0;
	}
}

int make(int now,int pos)
{
	if(pos<0)
		return 0;
	if(dp[now][pos]!=-1)
		return dp[now][pos];
	int i,j,k;
	for(i=0;i<13;i++)
		if(!(now & 1<<i))
		{
			k=calc(i,pos);
			j=make(now | 1<<i,pos-1);
			if(pos==6 && j>=63)
				j+=35;
			j+=k;	
			dp[now][pos]=Max(dp[now][pos],j);
			if(dp[now][pos]==j)
				parent[now][pos]=i;
		}
	return dp[now][pos];
}

int main()
{
	int i,j,ans,sum,k;
	vector<int> seq;
	while(scanf("%d",&round[0][0])==1)
	{
		for(j=1;j<5;j++)
			scanf("%d",&round[0][j]);
		for(i=1;i<13;i++)
			for(j=0;j<5;j++)
				scanf("%d",&round[i][j]);
														
		mem(dp,-1);
		mem(parent,-1);
		ans=make(0,12);
		seq.clear();
		j=12,i=sum=0;
		while(j>=0)
		{
			k=calc(parent[i][j],j);
			sum+=k;
			seq.push_back(k);
			i=i | 1<<parent[i][j];
			j--;
		}
		reverse(seq.begin(),seq.end());
		printf("%d",seq[0]);
		for(i=1;i<13;i++)
			printf(" %d",seq[i]);
		printf(" %d %d\n",ans-sum,ans);
	}
	return 0;
}
