//Game theory-Grundy number
#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;

#define mem(a) memset(a,-1,sizeof(a))

char s[1005];
int dp[103][3][3];

int make(int len,int left,int right)
{
	if(!len)
		return 0;
	if(dp[len][left][right]!=-1)
		return dp[len][left][right];
	
	int i;
	set<int> now;
	if(len==1)
	{
		if(left==right || !right || !left)
			return 1;
		else
			return 0;
	}
	
	if(left!=1)
		now.insert(make(len-1,1,right));
	if(left!=2)
		now.insert(make(len-1,2,right));	
	if(right!=1)
		now.insert(make(len-1,left,1));
	if(right!=2)
		now.insert(make(len-1,left,2));
	for(i=2;i<=len-1;i++)
	{
		int j=make(i-1,left,1),k=make(len-i,1,right);
		now.insert(j^k);
		j=make(i-1,left,2),k=make(len-i,2,right);
		now.insert(j^k);
	}
	i=0;
	while(now.find(i)!=now.end())
		i++;
	dp[len][left][right]=i;
	return dp[len][left][right];
}

int main()
{
	int t;
	mem(dp);
	scanf("%d",&t);
	int st[105],nd[105],i,j,left,right,fc[105],bc[105],tot,k,l;
	while(t--)
	{
		scanf("%s",s);
		i=j=0;
		while(s[i])
		{
			while(s[i]!='.' && s[i])
				i++;
			if(!s[i])
				break;
			//st[j]=i-1;
			if(!i)
				left=0;
			else if(s[i-1]=='X')
				left=1;
			else
				left=2;
			k=0;
			while(s[i]=='.' && s[i])
				i++,k++;
			if(!s[i])
				right=0;
			else if(s[i]=='X')
				right=1;
			else
				right=2;
			j= j ^ make(k,left,right);
		}
		for(i=k=0;s[i];i++)
			k+=(s[i]!='.');
		if(k%2)
			j= !j;
		
		if(j)
			printf("Possible.\n");
		else
			printf("Impossible.\n");
	}	
	return 0;
}
