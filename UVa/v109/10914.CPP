#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define size 2500000
#define Long __int64
//#define Long long long
long pr[350000];
struct almost
{
	int abun;
	Long sigma;
	Long sum;
}a[738000];
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
bool operator<(almost x,almost y)
{
	return x.abun<y.abun;
}
int binsearch(int key,int n)
{
	int low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(a[mid].abun<=key)low=mid;
		else high=mid-1;
	}
	if(a[low].abun<=key)return low;
	else return 0;
}
int main()
{
	int m=gene(size*2);
	int two[24],i,j,k,n;
	two[0]=1;
	for(i=1;i<24;i++)
		two[i]=two[i-1]*2;
	i=0;
	for(j=1;j<m;j++)
	{
		for(k=1;k<24;k++)
		{
			if(pr[j]*two[k]>10000000)
				break;
			a[i].abun=pr[j]*two[k];
			if(k==1)a[i].sigma=1+pr[j]+2+a[i].abun;
			else a[i].sigma=a[i-1].sigma+two[k]+a[i].abun;
			i++;
		}
	}
	sort(a,a+i);
	a[0].sum=0;
	for(j=1;j<i;j++)
		a[j].sum=a[j-1].sum+a[j].sigma-2*a[j].abun;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		if(n<6)printf("%d 0\n",n);
		else printf("%d %I64d\n",n,a[binsearch(n,i)].sum);
	}
	return 0;
}













