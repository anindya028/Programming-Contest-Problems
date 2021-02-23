#include<stdio.h>
#include<string.h>

#define Max(a,b) ((a)>(b)?(a):(b))

int cs;
char A[100],B[100];
char mark[62][62][62][62];
char dp[62][62][62][62];

char make(int sta, int nda,int stb,int ndb)
{
	if(sta>nda || stb>ndb)
		return 0;

	if(mark[sta][nda][stb][ndb]==cs)
		return dp[sta][nda][stb][ndb];

	mark[sta][nda][stb][ndb] = cs;
	int vvv = 0;

	int v;
	if(A[sta]==A[nda] && A[sta]==B[stb] && B[stb]==B[ndb])
	{
		v = 1 + (sta!=nda && stb!=ndb) + make(sta+1,nda-1,stb+1,ndb-1);
		vvv = Max(v,vvv);
	}

	v = make(sta+1,nda,stb,ndb);
	vvv = Max(v,vvv);

	v = make(sta,nda-1,stb,ndb);
	vvv = Max(v,vvv);

	v = make(sta,nda,stb+1,ndb);
	vvv = Max(v,vvv);

	v = make(sta,nda,stb,ndb-1);
	vvv = Max(v,vvv);

    dp[sta][nda][stb][ndb] = vvv;
	return vvv;
}

int main()
{
//    freopen("palin2.in","r",stdin);
//    freopen("palin2.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",A,B);
		cs++;

		printf("Case %d: %d\n",cs,make(0,strlen(A)-1,0,strlen(B)-1));
	}
	return 0;
}
