//common substring
//O(stringlength + patternlength * log(stringlength))
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
#define retnum(a) ((a>'Z')?(a-'a'):(a-'A'+26))

vector<int> pos[55];
char s[1000005],pat[105];

int binsearch(int key,int now)
{
	int low=0,high=pos[now].size()-1,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(pos[now][mid]>key)
			high=mid;
		else
			low=mid+1;
	}
	if(pos[now][low]>key)
		return low;
	return -1;
}

int main()
{
	int i,j,posk[52],q,flag,st,nd,cur,now;
	while(scanf("%s",s)==1)
	{
		Foro(i,52)
			pos[i].clear();
		for(i=0;s[i];i++)
			pos[retnum(s[i])].pb(i);
		scanf("%d",&q);
		Foro(i,q)
		{
			scanf("%s",pat);
			Foro(j,52)
			if(pos[j].size()==0)
				posk[j]=-1;
			else
				posk[j]=0;
			flag=1;
			cur=-1;
			for(j=0;pat[j] && flag;j++)
			{
				now=retnum(pat[j]);
				if(posk[now]!=-1 && pos[now][posk[now]]<=cur)
					posk[now]=binsearch(cur,now);
				if(posk[now]==-1)
				{
					flag=0;
					break;
				}
				cur=pos[now][posk[now]];
				if(!j)
					st=cur;
				posk[now]++;
				if(posk[now]>=pos[now].size())
					posk[now]=-1;
			}
			if(flag)
				nd=cur;
			if(!flag)
				printf("Not matched\n");
			else
				printf("Matched %d %d\n",st,nd);
		}
	}
	return 0;
}