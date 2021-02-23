#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<map>
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

char s[100005];
queue<int> q[10];

int main()
{
	int n,d,i,j,now;
	while(scanf("%d%d",&n,&d)==2 && n && d)
	{
		scanf("%s",s);
		Foro(i,10)
			while(!q[i].empty())
				q[i].pop();
		for(i=0;s[i];++i)
			q[s[i]-'0'].push(i);
		now=0;
		while(s[now] && d)
		{
			for(i=9;i>=0;--i)
				if(!q[i].empty())
				{
					j=q[i].front();
					if((j-now)<=d)
					{
						q[i].pop();
						break;
					}
				}
			while(now<j)
				q[s[now]-'0'].pop(),s[now]=' ',now++,d--;
			now++;
		}
		for(i=n-1;i>=0 && d;i--,d--)
			s[i]=' ';
		for(i=0;s[i];++i)
			if(s[i]!=' ')
				printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}