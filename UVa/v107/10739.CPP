#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Min(a,b) (((a)<(b))?(a):(b))
int memo[1005][1005];
char s[1005];
int det(int i,int j)
{
	if(j<i)return 0;
	if(memo[i][j]>=0)return memo[i][j];
	if(s[i]==s[j])memo[i][j]=det(i+1,j-1);
	else memo[i][j]=Min(det(i+1,j),Min(det(i,j-1),det(i+1,j-1)))+1;
	return memo[i][j];
}

int main()
{
	int i,j,len,t,cs;
	
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%s",s);
		len=strlen(s);
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
				memo[i][j]=-1;
			memo[i][i]=0;
		}
		printf("Case %d: %d\n",cs+1,det(0,len-1));
	}

	return 0;
}













