#include<stdio.h>
#include<string.h>

char fib[4005][1000];
long l1,l2,l3,i,q,max,a,b,c,n;

void fibhaha()
{
	fib[0][0]='0';
	fib[1][0]='1';
	for(i=2;i<4005;i++)
	{
		l1=strlen(fib[i-2]);
		l2=strlen(fib[i-1]);
		if(l1>l2)
			max=l1;
		else
			max=l2;
		for(q=c=0;q<max||c;q++)
		{
			if(q<l1)
				a=fib[i-2][q]-48;
			else
				a=0;
			if(q<l2)
				b=fib[i-1][q]-48;
			else
				b=0;
			fib[i][q]=(a+b+c)%10+48;
			c=(a+b+c)/10;
		}
		fib[i][q]='\0';
	}
}
void main()
{
	fibhaha();
	while(scanf("%ld",&n)==1)
	{
		if(!n)break;
		l3=strlen(fib[n*2]);
		for(i=l3-1;i>=0;i--)
			printf("%c",fib[n*2][i]);
		printf("\n");
	}
}













