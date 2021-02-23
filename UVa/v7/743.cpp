#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;	

#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

int solve(int pos,char *x,char *y)
{
	char temp[2000];
	int i,j;
	if(pos<0) return 1;
	if(x[pos]=='2')
	{
		for(i=0,j=pos+1;x[j];++i,++j)
		{
			y[i]=x[j];
		}
		y[i]=0;
		if(solve(pos-1,x,y)) return 1;
	}
	else if(x[pos]=='3')
	{
		strcpy(temp,y);
		strcat(temp,"2");
		strcat(temp,y);
		strcpy(y,temp);
		if(solve(pos-1,x,y)) return 1;
	}
	return 0;
}

int main()
{
	char n[2000],p[2000];
	int i,len,ok;
	while(gets(n))
	{
		if(strcmp(n,"0")==0) break;
		len=strlen(n);
		if(strchr(n,'0') || len==1) 
		{
			printf("NOT ACCEPTABLE\n");
		}
		else
		{
			for(ok=i=0;i<len-1 && ok==0;++i)
			{
				if(n[i]=='2')
				{
					ok=solve(i,n,p);
				}
			}
			if(ok)
			{
				printf("%s\n",p);
			}
			else
			{
				printf("NOT ACCEPTABLE\n");
			}
		}
	}
	return 0;
}