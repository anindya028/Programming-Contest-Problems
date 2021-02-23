#include<stdio.h>
#include<string.h>

#define mod 10000007
#define LL long long

LL ten[105];

char pattern[105];
int F[105];
void build_failure_function(void)
{
  int m = strlen(pattern);
  int i,j;
  F[0] = F[1] = 0; // always true
  
  for(i = 2; i <= m; i++) {
    // j is the index of the largest next partial match 
    // (the largest suffix/prefix) of the string under  
    // index i - 1
    j = F[i - 1];
    for( ; ; ) {
      // check to see if the last character of string i - 
      // - pattern[i - 1] "expands" the current "candidate"
      // best partial match - the prefix under index j
      if(pattern[j] == pattern[i - 1]) { 
        F[i] = j + 1; break; 
      }
      // if we cannot "expand" even the empty string
      if(j == 0) { F[i] = 0; break; }
      // else go to the next best "candidate" partial match
      j = F[j];
    }
  }   
}

int next[105][10],dp[105][105],n;
int make(int pos,int v)
{
	if(!pattern[v])
		return 0;
	if(pos==n)
		return 1;
	if(dp[pos][v]!=-1)
		return dp[pos][v];
	dp[pos][v] = 0;

	int i;
	for(i = (!pos && n>1) ; i < 10 ; i++)
		dp[pos][v] = (dp[pos][v] + make(pos+1,next[v][i]))%mod;

	return dp[pos][v];
}

int main()
{
	int i,j,k;
	ten[0] = 1;
	for(i=1;i<=102;i++)
		ten[i] = (ten[i-1] * 10)%mod;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,pattern);
		int len = strlen(pattern);
		
		build_failure_function();
		for(i=0;i<len;i++)
		{
			for(j=0;j<10;j++)
			{
				k = i;
				while(1)
				{
					if(pattern[k] == (j+'0'))
					{
						next[i][j] = k+1;
						break;
					}
					if(k==0)
					{
						next[i][j] = 0;
						break;
					}
					k = F[k];
				}
			}
		}
		memset(dp,-1,sizeof(dp));
		printf("%d\n",make(0,0));
	}
	return 0;
}