#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		if(n%9==0)printf("9\n");
		else printf("%d\n",n%9);
	}
	return 0;
}













