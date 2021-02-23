//Game
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	if(!b)return 0;
	if((a/b)==1) return !gcd(b,(a%b));
	return 1;
}
int main()
{
	int a,b,temp;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(!a && !b)break;
		if(a<b)
		{
			temp=a;
			a=b;
			b=temp;
		}
		if(gcd(a,b)%2)printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
	return 0;
}













