#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,x,one,zero,t,i,temp;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&n,&x);
		one=zero=0;
		if(!x)
		{
			printf("1 1\n");
			continue;
		}
		temp=x;
		while(temp)
		{
			if(temp%2)one++;
			temp/=2;
		}
		while(1)
		{
			if(x%2)break;
			zero++;
			x/=2;
		}
		printf("%d %d\n",one+1,(int)pow(2,n)-(int)pow(2,zero)+1);
	}
	return 0;
}













