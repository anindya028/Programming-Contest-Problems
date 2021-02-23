//Number theory
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//#define Long __int64
#define Long long long
#define size 500
#define eps 1e-10
long pr[200];
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
int main()
{
	int m=gene(size*2);
	int i,j,k,n,t,cs,dif,*freq;
	Long fact,mx;
	for(i=1,mx=1;i<=18;i++)
		mx*=10;
	double digit;
	char s[100];
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%s",s);
		i=n=0;
		while(s[i]>='0' && s[i]<='9')
		{
			n=n*10+s[i]-'0';
			i++;
		}
		j=0;
		while(s[i]=='!')
		{
			j++;
			i++;
		}
		dif=j;
		freq=(int *)calloc(m,sizeof(int));
		for(i=n;i>0;i-=dif)
		{
			k=i;
			for(j=0;j<m && pr[j]<=k;j++)
			{
				while(k%pr[j]==0)
				{
					k/=pr[j];
					freq[j]++;
				}
			}
		}
		digit=0.;
		for(i=0;i<m;i++)
			digit+=log10(freq[i]+1);
		if((floor(digit+eps)+1)>19)
		{
			printf("Case %d: Infinity\n",cs+1);
			free(freq);
			continue;
		}
		fact=1;
		for(i=0;i<m;i++)
		{
			fact*=(freq[i]+1);
			if(fact>mx)
				break;
		}
		if(fact>mx)
			printf("Case %d: Infinity\n",cs+1);
		else
			printf("Case %d: %lld\n",cs+1,fact);
		free(freq);
	}

	return 0;
}

