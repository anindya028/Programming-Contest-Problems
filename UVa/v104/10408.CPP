//Number Theory
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct farey
{
	int num,den;
}f[1000000];
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,(a%b));
}
bool operator<(farey a,farey b)
{
	return (a.num*b.den)<(b.num*a.den);
}
int main()
{
	int i,j,k,n,l;
	while(scanf("%d%d",&n,&k)==2)
	{
		l=0;
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
				if(gcd(i,j)==1)
				{
					f[l].num=i;
					f[l].den=j;
					l++;
				}
		f[l].num=1;
		f[l].den=1;
		l++;
		sort(f,f+l);
		printf("%d/%d\n",f[k-1].num,f[k-1].den);
	}
	return 0;
}













