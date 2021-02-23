#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char s[105][105];
int r,c;
struct let
{
	int freq;
	char c;
}*l;
bool operator<(let a,let b)
{
	if(a.freq==b.freq)
		return a.c<b.c;
	return a.freq>b.freq;
}
void flood_fill(int i,int j,char key)
{
	if(i>0)
	{
		if(s[i-1][j]==key)
		{
			s[i-1][j]='*';
			flood_fill(i-1,j,key);
		}
	}
	if(i<(r-1))
	{
		if(s[i+1][j]==key)
		{
			s[i+1][j]='*';
			flood_fill(i+1,j,key);
		}
	}
	if(j>0)
	{
		if(s[i][j-1]==key)
		{
			s[i][j-1]='*';
			flood_fill(i,j-1,key);
		}
	}
	if(j<(c-1))
	{
		if(s[i][j+1]==key)
		{
			s[i][j+1]='*';
			flood_fill(i,j+1,key);
		}
	}
	return;
}
int main()
{
	int t,i,j,k;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&r,&c);
		for(j=0;j<r;j++)
			scanf("%s",s[j]);
		l=(let *)calloc(26,sizeof(let));
		for(j=0;j<r;j++)
			for(k=0;k<c;k++)
				if(s[j][k]!='*')
				{
					l[s[j][k]-'a'].freq++;
					l[s[j][k]-'a'].c=s[j][k];
					flood_fill(j,k,s[j][k]);
					s[j][k]='*';
				}
		printf("World #%d\n",i+1);
		sort(l,l+26);
		for(j=0;j<26 && l[j].freq;j++)
			printf("%c: %d\n",l[j].c,l[j].freq);
		free(l);
	}
	return 0;
}