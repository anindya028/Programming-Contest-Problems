#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
	
#define LL unsigned long long
#define SIZE 500001
LL pr[80600];
bool p[SIZE];

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

set<LL> now;
vector<LL> vi;

int main()
{
	int m=gene(2*SIZE);
	now.clear(),vi.clear();
	vi.push_back(1);
	int i,j;
	LL big=(LL)18446744073709551615;
	for(i=2;i<(1<<16);i++)
	{
		int temp=i;
		if(temp>2)
			while(temp%2==0)
				temp/=2;
		if(temp==1)
			continue;
		LL k=i;
		k*=i;
		k*=i;
		for(j=4;j<=63;j++)
		{
			if(k>=(big/i))
				break;
			k*=i;
			if(j%2 && !p[(j-1)/2])
				continue;
			if(now.find(k)==now.end())
			{
				//if(!k)
				//	printf("->>%d  %d \n",i,j);
				now.insert(k);
				vi.push_back(k);
			}
		}
	}
	sort(vi.begin(),vi.end());
	for(i=0;i<vi.size();i++)
		printf("%llu\n",vi[i]);
	return 0;
}