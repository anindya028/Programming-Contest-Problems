#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int c[27][352][27];
int count(int l,int s,int a)
{
	int i,k=0;
	if(l>26 || s>351 || a>=s)
		return 0;
	if(c[l][s][a]!=-1)
		return c[l][s][a];
	if(l==1)
	{
		if(s<=26)
			c[l][s][a]=1;
		else c[l][s][a]=0;
		return c[l][s][a];
	}
	for(i=a+1;(i<=26 && i<s) && ((i+1)*(l-1))<=s;i++)
	{
		if(c[l-1][s-i][i]!=-1)
			k+=c[l-1][s-i][i];
		else k+=count(l-1,s-i,i);
	}
	c[l][s][a]=k;
	return k;
}
int main()
{
	int l,s,cs=0,i,j,k;
	for(i=0;i<27;i++)
		for(j=0;j<352;j++)
			for(k=0;k<27;k++)
				c[i][j][k]=-1;
	while(scanf("%d%d",&l,&s)==2)
	{
		if(!l && !s)break;
		printf("Case %d: %d\n",++cs,count(l,s,0));
	}
	return 0;
}













