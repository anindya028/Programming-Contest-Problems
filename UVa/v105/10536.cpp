#include<stdio.h>
#include<string.h>

#define mem(a) memset(a,-1,sizeof(a))

int dp[1<<17];

int make(int now)
{
	if(now==((1<<(16)) -1))
		return 1;
	if(dp[now]!=-1)
		return dp[now];
	dp[now]=0;
	int i,j;
	//1
	for(i=0;i<16;i++)
		if(!(now & (1<<i)))
			dp[now]|= !make(now + (1<<i));
	//2->horizontal
	for(i=0;i<4;i++)
		for(j=0;j<3;j+=2)
			if(!(now & (1<<(i*4+j))) && !(now & (1<<(i*4+j+1))))
				dp[now]|= !make(now + (1<<(i*4+j)) + (1<<(i*4+j+1)));
	//2->vertical
	for(i=0;i<3;i+=2)
		for(j=0;j<4;j++)
			if(!(now & (1<<(i*4+j))) && !(now & (1<<((i+1)*4+j))))
				dp[now]|= !make(now + (1<<(i*4+j)) + (1<<((i+1)*4+j)));
	//3->horizontal
	for(i=0;i<4;i++)
		for(j=0;j<2;j++)
			if(!(now & (1<<(i*4+j))) && !(now & (1<<(i*4+j+1))) && !(now & (1<<(i*4+j+2))))
				dp[now]|= !make(now + (1<<(i*4+j)) + (1<<(i*4+j+1)) + (1<<(i*4+j+2)));
	//3->vertical
	for(i=0;i<2;i++)
		for(j=0;j<4;j++)
			if(!(now & (1<<(i*4+j))) && !(now & (1<<((i+1)*4+j))) && !(now & (1<<((i+2)*4+j))))
				dp[now]|= !make(now + (1<<(i*4+j)) + (1<<((i+1)*4+j)) + (1<<((i+2)*4+j)));
	return dp[now];
}

int main()
{
	char s[10][10];
	int t,i,j,now;
	mem(dp);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s%s%s",s[0],s[1],s[2],s[3]);
		now=0;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(s[i][j]=='X')
					now+=(1<<(i*4+j));
		if(make(now))
			printf("WINNING\n");
		else
			printf("LOSING\n");
	}
	return 0;
}
