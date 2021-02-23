#include<stdio.h>

#define LL long long
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

int main()
{
	int i;
	freopen("irreducible.in","r",stdin);
	freopen("irreducible.out","w",stdout);
	int n,m=gene(2*SIZE);
	while(scanf("%d",&n)==1 && n)
	{
		int temp=n;
		for(i=0;i<m && pr[i]*pr[i]<=temp;i++)
			if(temp%pr[i]==0)
			{
				n/=pr[i];
				n*=(pr[i]-1);
				while(temp%pr[i]==0)
					temp/=pr[i];
			}
		if(temp>1)
			n/=temp,n*=(temp-1);
		printf("%d\n",n);
	}
	return 0;
}