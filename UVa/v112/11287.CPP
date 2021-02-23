#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Long long long
//#define Long __int64
#define size 50000
long pr[10000];
bool p[size];
long gene(long n)
{
	int root=ceil(sqrt(n));
    long i,j;
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
Long bigmod(Long b,Long p,Long m)
{
   Long a; 
   if (p == 0) 
      return 1; 
   if (p%2 == 0)
   { 
      a = bigmod(b,p/2,m); 
      return (a*a) % m; 
   }
   else
   { 
      return ((b % m) * bigmod(b,p-1,m)) % m; 
   } 
}
int main()
{
	int a,p,i,flag;
	int m=gene(size*2);
	while(scanf("%d%d",&p,&a)==2)
	{
		if(!a && !p)break;
		flag=0;
		for(i=0;pr[i]*pr[i]<=p && i<m;i++)
			if(p%pr[i]==0)
			{
				flag=1;
				break;
			}
		if(!flag)
		{
			printf("no\n");
			continue;
		}
		if(bigmod(a,p,p)==a)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}













