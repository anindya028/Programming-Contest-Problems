#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int prime[32];
int taken[17],len,*s;
void gene(int lev)
{
	int i,j;
	if(lev==len)
	{
		if(!prime[s[lev-1]+s[0]])
			return;
		printf("%d",s[0]);
		for(j=1;j<len;j++)
			printf(" %d",s[j]);
		printf("\n");
		return;
	}
	if(s[lev-1]%2)
		i=2;
	else i=3;
	for(;i<=len;i+=2)
	{
		if(!taken[i] && prime[s[lev-1]+i])
		{
			s[lev]=i;
			lev++;
			taken[i]=1;
			gene(lev);
			lev--;
			taken[i]=0;
		}
	}
	return;
}
int main()
{
	int cs=0;
	prime[2]=prime[3]=prime[5]=prime[7]=prime[11]=prime[13]=prime[17]=prime[19]=prime[23]=prime[29]=prime[31]=1;
	while(scanf("%d",&len)==1)
	{
		if(cs)printf("\n");
		s=(int *)calloc(len,sizeof(int));
		s[0]=1;
		printf("Case %d:\n",++cs);
		gene(1);
		free(s);
	}
	return 0;
}













