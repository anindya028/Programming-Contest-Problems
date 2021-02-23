#include<stdio.h>
#include<string.h>

char fib[1002][250];
long l1,l2,l3,i,q,max,a,b,c,n;
void rev(char *t)
{
	int i=0,j=strlen(t)-1;
	char temp;
	while(i<j)
	{
		temp=t[i];
		t[i]=t[j];
		t[j]=temp;
		i++;
		j--;
	}
	return;
}
void fibhaha(){
	fib[0][0]='1';
        fib[0][1]='\0';
	fib[1][0]='2';
	fib[1][1]='\0';
	for(i=2;i<1002;i++){
		l1=strlen(fib[i-2]);
		l2=strlen(fib[i-1]);
		if(l1>l2)
			max=l1;
		else
			max=l2;
		for(q=c=0;q<max||c;q++){
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

void main(){
	fibhaha();
        int i=0;
	for(;i<1002;i++)rev(fib[i]);
	while(scanf("%ld",&n)==1)
	{
		printf("%s\n",fib[n]);
	}
}