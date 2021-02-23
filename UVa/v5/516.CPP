#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define size 40000
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
int tokenize_input(void)
{
	int num=1,b,p;
	char c;
	while(cin.get(c) && c!='\n')
	{
		if(c>='0' && c<='9')
		{
			cin.unget();
			cin>>b;
			if(b==0)
				return b;
			getchar();
			cin>>p;
			num*=(int)pow(b,p);
		}
	}
	return num;
}
int main()
{
	int m,n,*freq,i,j,count,*fact;
	m=gene(size);
	while(1)
	{
		n=tokenize_input();
		if(!n)break;
		n--;
		freq=(int *)calloc(m,sizeof(int));
		fact=(int *)calloc(m,sizeof(int));
		for(i=count=0;i<m;i++)
		{
			if(pr[i]*pr[i]>n)break;
			while(n%pr[i]==0)
			{
				freq[count]++;
				n/=pr[i];
			}
			if(freq[count])
			{
				fact[count]=pr[i];
				count++;
			}
		}
		if(n!=1)
		{
			fact[count]=n;
			freq[count]=1;
			count++;
		}
		printf("%d %d",fact[count-1],freq[count-1]);
		for(j=count-2;j>=0;j--)
			printf(" %d %d",fact[j],freq[j]);
		printf("\n");
		free(fact);
		free(freq);
	}
	return 0;
}













