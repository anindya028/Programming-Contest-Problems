#include<stdio.h>
#include<string.h>

#define mem(a,b) memset(a,b,sizeof(a))
#define Min(a,b) (((a)<(b))?(a):(b))
#define mabs(a) (((a)>0)?(a):-(a))

char mat[1002][302];
int dp[1002][302],even[1005][2],h,w,last;

int make(int r,int c)
{
	if(r==h || r==last+1)
		return -1;
	if(dp[r][c]!=-1)
		return dp[r][c];
	int i=r;
	if(even[i][0]==-1)
	{
		dp[r][c]=1+make(r+1,c);
		return dp[r][c];
	}
	if(even[i][0]==even[i][1])
	{
		dp[r][c]=1+mabs(c-even[i][0])+make(r+1,even[i][0]);
		return dp[r][c];
	}
	if(c<=even[i][0])
	{
		dp[r][c]=even[i][1]-c + 1 + make(r+1,even[i][1]);
		int temp=even[i][1]-c + 1 + even[i][1]-even[i][0] + make(r+1,even[i][0]);
		dp[r][c]=Min(dp[r][c],temp);
	}
	else if(c>=even[i][1])
	{
		dp[r][c]=c-even[i][0] + 1 + make(r+1,even[i][0]);
		int temp=c-even[i][0] + 1 + even[i][1]-even[i][0] + make(r+1,even[i][1]);
		dp[r][c]=Min(dp[r][c],temp);
	}
	else
	{
		dp[r][c]= c-even[i][0] + 1 + even[i][1]-even[i][0] + make(r+1,even[i][1]);
		int temp= even[i][1]-c + 1 + even[i][1]-even[i][0] + make(r+1,even[i][0]);
		dp[r][c]=Min(dp[r][c],temp);
	}
	return dp[r][c];
}

int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&w,&h);
//		if(w>500) while(1) printf("\n");
//		if(h>500) printf("%d\n",1/(!h));
		for(i=0;i<h;i++)
			scanf("%s",mat[i]);
		last=0;
		for(i=0;i<h;i++)
		{
			j=0;
			while(j<w && (mat[i][j]-'0')%2!=0)
				j++;
			if(j==w)
				even[i][0]=-1;
			else
				even[i][0]=j;
			j=w-1;
			while(j>=0 && (mat[i][j]-'0')%2!=0)
				j--;
			if(j>=0)
				even[i][1]=j;
			else
				even[i][1]=-1;
			if(even[i][0]!=-1)
				last=i;
		}
		mem(dp,-1);
		printf("%d\n",make(0,0));
	}
	return 0;
}
