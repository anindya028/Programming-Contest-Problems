#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define LL unsigned long long

int mypow(int b,LL p,int m)
{
	if(!p)
		return (1%m);
	if(p%2)
	{
		int temp=mypow(b,p-1,m);
		return (temp*b)%m;
	}
	else
	{
		int temp=mypow(b,p/2,m);
		return (temp*temp)%m;
	}
}

vector<int> fib[1002];

int main()
{
	int t,i,n,j,k;
	LL a,b;
	
	fib[1].push_back(0);
	for(i=2;i<=1000;i++)
	{
		fib[i].push_back(0);
		fib[i].push_back(1);
		j=2;
		while(1)
		{
			k=(fib[i][j-1]+fib[i][j-2])%i;
			if(!k && fib[i][j-1]==1)
				break;
			fib[i].push_back(k);
			j++;
		}
	}	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%llu%llu%d",&a,&b,&n);
		k=(int)(a%fib[n].size());
		
		printf("%d\n",fib[n][mypow(k,b,fib[n].size())]);
	}
	return 0;
}