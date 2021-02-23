//Good Number theory
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;

//#define Long __int64
#define Long long long

int main()
{
	Long n,i,ans;
	while(scanf("%lld",&n)==1)
	{
		if(!n)
        {
          for(i=0;i<1000000000;i++)
              n++;
          break;
        }
		ans=0;
		for(i=1;i<=n;i*=2)
			ans+=((Long)(floor(sqrt((double)(n/i))+1e-7))+1)/2;
		printf("%lld\n",n-ans);
	}
	return 0;
}
