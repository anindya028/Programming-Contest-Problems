#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<cstdio>
#include <ctime>


using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))
#define istr(S) istringstream sin(S)
#define MP make_pair
#define pb push_back
#define inf 1000000000

typedef long   LL;
//typedef __int64 LL;

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<pi> vpi;


char  A[200005];
int pre[200005],suf[200005],n;
int a[200005];
LL mod1=10007,mod2=10009;
LL base1=101,base2=71;
int cs;

LL m1[200005],m2[200005];

int solve(int f)
{
//	int match = n - 1;
	
	LL ha1 = 0, ha2 = 0, hr1 = 0, hr2 = 0;
//	LL m1 = 1, m2 = 1;

	for ( int i = 0; i<n-f; ++i )
	{
		ha1 = (ha1 + m1[i]*a[i]);// % mod1;
		ha2 = (ha2 + m2[i]*a[i]);// % mod2;

		hr1 = (a[i] + base1*hr1);// % mod1;
		hr2 = (a[i] + base2*hr2);// % mod2;

//		m1 *= base1, m1 %= mod1;
//		m2 *= base2, m2 %= mod2;

		if ( ha1 == hr1 && ha2 == hr2 )
		{
			if(!f)
				pre[i]=cs;
			else
			{
				suf[n-1-i]=cs;
				if(pre[n-1-i-1]==cs)
					return 2;
			}
	//		match = i;

		}
	}
	return 0;
}

int main()
{
	int i,j,tests;
	m1[0]=1,m2[0]=1;
	for(i=1;i<200002;i++)
		m1[i] = (m1[i-1]*base1),//%mod1,
		m2[i] = (m2[i-1]*base2);//%mod2;
	
	gets(A);
	sscanf(A,"%d",&tests);
	

	while(tests--)
	{
		gets(A);
		//scanf("%s",A);
		//printf("%s\n",A);
	
		for(i=0;A[i];i++)
			a[i]=A[i]-'a';

		n=i;

		++cs;

		solve(0);
		
		i=0,j=n-1;
		while(i<j)
		{
			a[i] ^= a[j] ^= a[i] ^= a[j];
			i++,j--;
		}
		//reverse(a,a+n);
		
		
		


		int ans=solve(1);
		if(pre[n-1]==cs && !ans) ans=1;
		

	//	for(i=0;i<n-1 && ans!=2;i++)
	//		if(pre[i]==cs && suf[i+1]==cs) ans=2;

		if(ans==2)
			puts("alindrome");
		else if(ans==1)
			puts("palindrome");
		else
			puts("simple");
		

	}

	return 0;
}