//Good DP,O(26*n^2)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

#define size 1005

int mat[size][size],trst[size][size],trend[size][size],len;
char s[size];

int make(int st,int end)
{
	int mx,c,flag,a,b,fa,fb;
	register int i,j,k;
	if(st>end)
		return 0;
	if(st==end)
	{
		mat[st][end]=1;
		trst[st][end]=st;
		trend[st][end]=end;
		return mat[st][end];
	}
	if(mat[st][end]>=0)
		return mat[st][end];
	mx=0;
	for(k='a';k<='z';k++)
	{
		flag=c=0;
		for(i=st;i<=end && !flag;i++)
			if(s[i]==k)
				for(j=end;j>=i;j--)
					if(s[j]==k)
					{
						a=i;
						b=j;
						if(i!=j)
							c=make(i+1,j-1)+2;
						else
							c=make(i+1,j-1)+1;
						flag=1;
						break;
					}
		if(c>mx)
		{
			mx=c;
			fa=a;
			fb=b;
		}
	}
	mat[st][end]=mx;
	trst[st][end]=fa;
	trend[st][end]=fb;
	return mat[st][end];
}

void print(int st,int end)
{
	if(st>end)
		return;
	printf("%c",s[trst[st][end]]);
	print(trst[st][end]+1,trend[st][end]-1);
	if(trst[st][end]!=trend[st][end])
		printf("%c",s[trend[st][end]]);
	return;
}

int main()
{
	int got;
	register int i,j;
	while(scanf("%s",s)==1)
	{
		len=strlen(s);
		if(len==0)
			break;
		for(i=0;i<len;i++)
			for(j=i;j<len;j++)
				mat[i][j]=trst[i][j]=trend[i][j]=-1;
		got=make(0,len-1);
		print(0,len-1);
		printf("\n");
	}
	return 0;
}
