#include<stdio.h>
#include<math.h>

#define mod 100000000
typedef long long myint;

myint sqr(myint p)
{
	myint t1,t2,t4,t;

	t=p;
	t1=p+1;
	t2=2*p+1;
	if(t%2)
	{
		t1/=2;
		if(t%3==0)
		{
			t/=3;
			t4=t;
			t4=(t1%mod)*(t4%mod);
			t4%=mod;
			t4=(t2%mod)*(t4%mod); 
			t4%=mod;
		}
		else if(t1%3==0)
		{
			t1/=3;
			t4=t1;
			t4=(t%mod)*(t4%mod);
			t4%=mod;
			t4=(t2%mod)*(t4%mod);
			t4%=mod;
		}
		else
		{
			t2/=3;
			t4=t2;
			t4=(t%mod)*(t4%mod); 
			t4%=mod;
			t4=(t1%mod)*(t4%mod);
			t4%=mod;
		}
	}
	else
	{
		t/=2;
		if(t%3==0)
		{
			t/=3;
			t4=t;
			t4=(t1%mod)*(t4%mod);
			t4%=mod;
			t4=(t2%mod)*(t4%mod);
			t4%=mod;
		}
		else if(t1%3==0)
		{
			t1/=3;
			t4=t1;
			t4=(t%mod)*(t4%mod);
			t4%=mod;
			t4=(t2%mod)*(t4%mod);
			t4%=mod;
		}
		else
		{
			t2/=3;
			t4=t2;
			t4=(t%mod)*(t4%mod);
			t4%=mod;
			t4=(t1%mod)*(t4%mod);
			t4%=mod;
		}
	}

	return t4;
}

myint find(myint q)
{
	myint n;

	n=(q+1)/2;
	n%=mod;
	n*=n;
	n%=mod;

	return n;
}

int main()
{
	myint n,m;
	myint tt,rest,odd;

	while(scanf("%lld",&n) && n)
	{
		if(n<0)
		{
			puts("0");
			continue;
		}
		if(n<3)
		{
			puts("1");
			continue;
		}
		if(n<5)
		{
			puts("2");
			continue;
		}

		if(n%2)
			m=sqrt(n);
		else
			m=sqrt(n-1);

		tt=sqr(m-1);
		if(m%2)
		{
			odd=find(m-2);
			if(n%2)rest=(n-m*m)/2+1;
			else rest=(n-1-m*m)/2+1;
			rest%=mod;
			rest*=(m%mod);
			rest%=mod;
		}
		else
		{
			odd=find(m-1);
			if(n%2) rest=(n-m*m-1)/2+1;
			else rest=(n-m*m-2)/2+1;
			rest%=mod;
			rest*=(m%mod);
			rest%=mod;
		}
		tt+=(odd%mod); 
		tt%=mod;
		tt+=(rest%mod); 
		tt%=mod;

		printf("%lld\n",tt);
	}

	return 0;
}