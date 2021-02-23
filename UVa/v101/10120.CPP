#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int n,m,flag;
void gene(int s,int i)
{
	if(s<1 || s>n || flag)
		return;
	if(s==m)
	{
		flag=1;
		return;
	}
	i++;
	gene(s+2*i-1,i);
	gene(s-2*i+1,i);
}
int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n && !m)
			break;
		if(n>=49)
		{
			printf("Let me try!\n");
			continue;;
		}
		flag=0;
		gene(1,1);
		if(flag)printf("Let me try!\n");
		else printf("Don't make fun of me!\n");
	}
	return 0;
}













