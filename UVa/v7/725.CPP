#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char given[]={"0123456789"};
int freq[]={0,0,60,8,12,24,3,8,62,6,0,0,4,3,8,2,3,27,1,2,0,0,1,3,2,0,9,4,1,2,0,0,1,0,0,5,0,1,2,0,0,0,0,1,5,0,1,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,2,0,0,0,1,0,1};
char s[10],sp[10];
int num,k,taken[10];
void gene(int lev)
{
	int i,n,m,*take;
	if(lev==5)
	{
		s[lev]='\0';
		sscanf(s,"%d",&n);
		m=n*num;
		sprintf(sp,"%d",m);
		if(strlen(sp)!=5)
			return;
		for(i=0;sp[i];i++)
			if(taken[sp[i]-'0'])
				return;
		take=(int *)calloc(10,sizeof(int));
		for(i=0;sp[i];i++)
			if(take[sp[i]-'0'])
			{
				free(take);
				return;
			}
			else take[sp[i]-'0']=1;
		printf("%s / %s = %d\n",sp,s,num);
		k++;
		free(take);
		return;
	}
	for(i=0;i<10 && k<freq[num];i++)
	{
		if(!taken[i])
		{
			s[lev]=given[i];
			taken[i]=1;
			lev++;
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
	while(scanf("%d",&num)==1)
	{
		if(!num)break;
		if(cs)printf("\n");
		k=0;
		if(num>1 && num<69 && freq[num])gene(0);
		if(!k)
			printf("There are no solutions for %d.\n",num);
		cs++;
	}
	return 0;
}













