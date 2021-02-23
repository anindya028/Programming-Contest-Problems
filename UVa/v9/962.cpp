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

#define qu(a) ((a)*(a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define SIZE 1000100002
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

map<int,int> mp;
vector<int> tax;

int main()
{
	int i,j;
	int l,r,h;
	mp.clear();
	tax.clear();
	For(i,1,1001)
		for(j=i;qu(j)+qu(i)<SIZE;++j)
		{
			mp[qu(j)+qu(i)]++;
			if(mp[qu(j)+qu(i)]==2)
				tax.pb(qu(j)+qu(i));
		}
	sort(tax.begin(),tax.end());
	printf("%d",SZ(tax));
	while(scanf("%d%d",&l,&r)==2)
	{
		h=l+r;
		r=0;
		for(i=0;i<SZ(tax) && tax[i]<=h;i++)
			if(tax[i]>=l)
				r++,printf("%d\n",tax[i]);
		if(!r)
			printf("None\n");
	}
	return 0;
}