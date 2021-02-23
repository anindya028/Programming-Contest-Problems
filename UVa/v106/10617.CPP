//Good Dp
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

#define Long __int64
//#define Long long long
#define size 70

Long memo[size][size],ans;

int main()
{
	int t,cs,i,j,k,len;
	char s[size];
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%s",s);
		len=strlen(s);
		for(i=0;i<len;i++)
			for(j=0;j<len;j++)
				memo[i][j]=0;
		for(i=len-1;i>=0;i--)
		{
			memo[i][i]=1;
			for(j=i+1;j<len;j++)
			{
				if(s[i]!=s[j])
					memo[i][j]=memo[i][j-1];
				else
				{
					memo[i][j]=memo[i][j-1]+1;
					for(k=i+1;k<j;k++)
						memo[i][j]+=memo[k][j-1];
				}
			}
		}
		for(i=ans=0;i<len;i++)
			ans+=memo[i][len-1];
		printf("%I64d\n",ans);
	}
	return 0;
}
