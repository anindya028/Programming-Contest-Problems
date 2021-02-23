//Burnside's Lemma->Cn,Dn
#include<stdio.h>
#include<math.h>

#define LL long long

int gcd(int m,int n)
{
	if(!n) return m;
	return gcd(n,(m%n));
}

LL mypow(int b,int p)
{
	LL temp;
	if(!p)
		return 1;
	if(p%2)
	{
		temp=b*mypow(b,p-1);
		return temp;
	}
	else
	{
		temp=mypow(b,p/2);
		return temp*temp;
	}
}

int main()
{
	int n,t,i;
	LL Cn,Dn;
	while(scanf("%d%d",&n,&t)==2)
	{
		Cn=0;
		for(i=0;i<n;i++)
			Cn+=mypow(t,gcd(n,i));
		Cn/=n;
		Dn=Cn/2;
		if(n%2)
			Dn+=((mypow(t,(n+1)/2)+1)/2);
		else
			Dn+=((mypow(t,n/2) + mypow(t,n/2 + 1) + 3)/4);
		
		printf("%lld %lld\n",Cn,Dn);
	}
	return 0;
}