#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define size 500000
int cir[1000001];
bool p[size];
void gene(long n)
{
	int temp[7],len,div,mod,flag;
	char t[8];
	int root=ceil(sqrt(n));
    long i,j;
	for(i=3;i<n;i+=2)
		cir[i]=-1;
	for(i=3;i<=root;i+=2)
	{
		if(!p[i/2])
		{
			for(j=i*i;j<n+1;j+=(2*i))
				p[j/2]=1;
		}
	}
	cir[2]=1;
	for(i=3;i<n;i+=2)
	{
		if(cir[i]!=-1)
			continue;
		sprintf(t,"%ld",i);
		len=strlen(t);
		temp[0]=i;
		for(j=1;j<len;j++)
		{
			div=temp[j-1]/10;
			mod=temp[j-1]%10;
			temp[j]=mod*(int)pow(10,len-1)+div;
		}
		flag=1;
		for(j=0;j<len && flag;j++)
			if(p[(temp[j]-1)/2] || (temp[j]%2==0))
				flag=0;
		if(flag)
		{
			for(j=0;j<len;j++)
				if(cir[temp[j]]==-1)
					cir[temp[j]]=1;
		}
		else
		{
			for(j=0;j<len;j++)
				if(cir[temp[j]]==-1)
					cir[temp[j]]=0;
		}
	}
    return;
}
int main()
{
	gene(size*2);
	int cum[size*2];
	int i,j,t;
	cum[0]=0;
	for(i=1;i<size*2;i++)
		cum[i]=cum[i-1]+cir[i];
	while(scanf("%d",&i)==1)
	{
		if(i==-1)break;
		scanf("%d",&j);
		t=cum[j]-cum[i-1];
		if(!t)printf("No Circular Primes.\n");
		else if(t==1)printf("1 Circular Prime.\n");
		else printf("%d Circular Primes.\n",t);
	}
	return 0;
}













