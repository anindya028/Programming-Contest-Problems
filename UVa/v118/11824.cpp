#include<stdio.h>
#include<algorithm>

using namespace std;

#define LL long long
int n;
LL val[50];

LL calc()
{
	int i,j;
	LL ret=0;
	for(i=0;i<n;i++)
	{
		LL temp=val[i];
		if(val[i]>5000000)
			return -1;
		j=i;
		while(j)
		{
			temp*=val[i],j--;
			if(temp>5000000)
				return -1;
		}
		ret+=2*temp;
		if(ret>5000000)
			return -1;
	}
	return ret;
}

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		i=0;
		while(scanf("%lld",&val[i])==1 && val[i])		
			i++;
		n=i;
		sort(val,val+n);
		reverse(val,val+n);
		LL ans=calc();
		if(ans==-1)
			printf("Too expensive\n");
		else
			printf("%lld\n",ans);
	}
	return 0;
}