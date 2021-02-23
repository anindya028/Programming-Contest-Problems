#include<stdio.h>
#include<algorithm>

using namespace std;

#define Min(a,b) ((a)<(b)?(a):(b))

int dx[] = {1,0,-1,-1,0,1};
int dy[] = {-1,-1,0,1,1,0};

pair<int,int> calc(pair<int,int> now,int val)
{
	if(!val)
		return now;
	
	int i = now.second-1;
	int vv[] = {i,i+1,i,i,i,i-1};
	
	for(i = 0;i<6;i++)
	{
		int j = Min(val,vv[i]);
		now.first += dx[i]*j;
		now.second += dy[i]*j;
		val-=vv[i];
		if(val<=0)
			return now;
	}
	return now;
}

int main()
{
	int a[305],i,n;
	a[0] = 2;
	int dif = 1;
	for(i=1;i<300;i++)
	{
		dif += 6;
		a[i] = a[i-1] + dif;
	}
	while(scanf("%d",&n)==1)
	{
		if(n==1)
		{
			printf("0 0\n");
			continue;
		}
		for(i=0;i<300;i++)
		{
			if(a[i]>=n)
				break;
		}
		pair<int,int> now(0,i+1);
		pair<int,int> ans = calc(now,a[i] - n);
		printf("%d %d\n",ans.first,ans.second);
	}
	return 0;
}