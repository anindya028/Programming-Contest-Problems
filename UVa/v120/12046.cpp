#include<stdio.h>
#include<string.h>

#define mod 1000007

int dp[50][2][3][4][5][6][1<<5];
int make(int pos,int two,int three,int four,int five,int six,int now)
{
	if(!pos)
		return !(two * (now & 1) + three *(now & (1<<1)) + four *(now & (1<<2)) + five *(now & (1<<3)) + six *(now & (1<<4)));
	int &ret = dp[pos][two][three][four][five][six][now];
	if(ret!=-1)
		return ret;
	ret = 0;

	int i;
	for(i=1;i<=6;i++)
	{
		int next = now;
		if(i>1)
			next |= (1<<(i-2));
		ret = ( ret + make( pos-1,(two*10+i)%2,(three*10+i)%3,(four*10+i)%4,(five*10+i)%5,(six*10+i)%6,next))%mod;
	}
	return ret;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",make(n,0,0,0,0,0,0));
	}
	return 0;
}