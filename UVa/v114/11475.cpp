//Hashing/Robin-Carp
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
int M=45347,B=37; //Hash values->M should be a large prime
int fh[100005],bh[100005],bs[100005];
char s[100005],ne[100005];

bool check(int st1,int nd1,int st2,int nd2)
{
	int i,j;
	for(i=st1,j=nd2;i<=nd1;i++,j--)
		if(s[i]!=s[j])
			return false;
	return true;
}

int main()
{
	int n,len,d1,d2,st1,nd1,st2,nd2,j,flag,base;
	register int i;
	while(scanf("%s",s)==1)
	{
		len=strlen(s);
		bh[len]=0;
		base=1;
		for(i=len-1;i>=0;--i)
			bh[i]=(s[i]+(B*bh[i+1])%M)%M;
		bs[0]=1;
		fh[0]=s[0];
		for(i=1;i<len;++i)
			fh[i]=(s[i]+(fh[i-1]*B)%M)%M,bs[i]=(bs[i-1]*B)%M;
		i=flag=j=0;
		while(i<len && !flag)
		{
			n=len-i;
			if(n==1)
				break;
			if(n%2)
				st1=i,nd1=i+n/2-1,st2=i+n/2+1,nd2=i+n-1;
			else
				st1=i,nd1=i+n/2-1,st2=i+n/2,nd2=i+n-1;
			if(st1==0)
				d1=fh[nd1];
			else
				d1=(fh[nd1]+M-(fh[st1-1]*bs[nd1-st1+1])%M)%M;
			d2=(bh[st2]+M-bh[nd2+1])%M;
			if(d1==d2)
				if(check(st1,nd1,st2,nd2))
					flag=1;
			if(!flag)
				ne[j++]=s[i];
			i++;
		}
		ne[j]='\0';
		printf("%s",s);
		for(i=j-1;i>=0;--i)
			printf("%c",ne[i]);
		printf("\n");
	}
	return 0;
}