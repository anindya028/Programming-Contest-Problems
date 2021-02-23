#include<stdio.h>

long h[5850];
long i,n2,n3,n5,n7,p2,p3,p5,p7,n;

void goo()
{
	h[0]=1;
	for(i=1;i<5845;i++)
	{
		n2=h[p2]*2;
		n3=h[p3]*3;
		n5=h[p5]*5;
		n7=h[p7]*7;
		if (n2<=n3 && n2<=n5 && n2<=n7)
		{
			h[i]=n2;
			p2++;
		}
		if (n3<=n2 && n3<=n5 && n3<=n7)
		{
			h[i]=n3;
			p3++;
		}
		if (n5<=n3 && n5<=n2 && n5<=n7)
		{
			h[i]=n5;
			p5++;
		}
		if (n7<=n3 && n7<=n2 && n7<=n5)
		{
			h[i]=n7;
			p7++;
		}
	}
}

void main()
{
	goo();
	while(scanf("%ld",&n)==1&&n)
	{
		if(n%10==1 && n%100!=11)
		{
			printf("The %ldst humble number is %ld.\n",n,h[n-1]);
		}
		else if(n%10==2 && n%100!=12)
		{
			printf("The %ldnd humble number is %ld.\n",n,h[n-1]);
		}
		else if(n%10==3 && n%100!=13)
		{
			printf("The %ldrd humble number is %ld.\n",n,h[n-1]);
		}
		else
			printf("The %ldth humble number is %ld.\n",n,h[n-1]);
	}
}