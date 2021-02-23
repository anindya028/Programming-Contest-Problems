#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))

struct food
{
	int v,c,ind;
}f[55];

bool operator<(food a,food b)
{
	if(a.c==b.c)
		return a.v>b.v;
	return a.c<b.c;
}

struct memo
{
	int vv,cc;
}dp[23][52][2][102];

int n,parent[23][52][2][102];

memo make(int day,int prev,int past,int rem)
{
	memo ret;
	if(!day)
	{
		ret.cc=0;
		ret.vv=0;
		return ret;
	}
	if(!rem)
	{
		ret.cc=0;
		ret.vv=-100000000;
		return ret;
	}
	if(dp[day][prev][past][rem].vv!=-1)
		return dp[day][prev][past][rem];
	dp[day][prev][past][rem].vv=-100000000;

	int i;
	for(i=1;i<=n;i++)
		if(f[i].c<=rem)
		{
			ret=make(day-1,i,prev==i,rem-f[i].c);
			ret.cc+=f[i].c;
			if(prev!=i)
				ret.vv+=f[i].v;
			else if(prev==i && !past)
				ret.vv+=(f[i].v/2);
			if(ret.vv>0)
			{
				if(ret.vv>dp[day][prev][past][rem].vv)
					dp[day][prev][past][rem]=ret,parent[day][prev][past][rem]=i;
				else if(ret.vv==dp[day][prev][past][rem].vv && (ret.cc<dp[day][prev][past][rem].cc/* || f[i].ind<f[parent[day][prev][past][rem]].ind*/))
					dp[day][prev][past][rem]=ret,parent[day][prev][past][rem]=i;
			}
		}
		else
			break;
	return dp[day][prev][past][rem];
}

int main()
{
	int k,m,i,prev,past;
	vector<int> menu;
	memo ans;
	while(scanf("%d%d%d",&k,&n,&m)==3 && k)
	{
		mem(dp,-1);
		for(i=1;i<=n;i++)
			scanf("%d%d",&f[i].c,&f[i].v),f[i].v*=2,f[i].ind=i;

		sort(f+1,f+n+1);

		ans=make(k,0,0,m);
		if(ans.vv<0)
		{
			printf("0.0\n");
			continue;
		}
		printf("%.1lf\n",ans.vv/2.0);
		menu.clear();
		prev=0,past=0;
		while(k)
		{
			i=parent[k][prev][past][m];
			menu.push_back(i);
			k--;
			m-=f[i].c;
			past=(prev==i);
			prev=i;
		}
		printf("%d",f[menu[0]].ind);
		for(i=1;i<menu.size();i++)
			printf(" %d",f[menu[i]].ind);
		printf("\n");
	}
	return 0;
}