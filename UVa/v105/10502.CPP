#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define size 101
#define Min(a,b) (((a)<(b))?(a):(b))

struct rect
{
	int left,up,r,c;
}mat[size][size];
char s[size][size];

int main()
{
	int i,j,k,n,m,ans,mnr,mnc,mn;
	while(scanf("%d",&n)==1)
	{
		if(!n)
			break;
		scanf("%d",&m);
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		ans=0;
		if(s[0][0]=='0')
			mat[0][0].left=mat[0][0].up=mat[0][0].r=mat[0][0].c=0;
		else
		{
			mat[0][0].left=mat[0][0].up=mat[0][0].c=mat[0][0].r=1;
			ans++;
		}
		for(i=1;i<m;i++)
			if(s[0][i]=='0')
				mat[0][i].left=mat[0][i].c=mat[0][i].up=mat[0][i].r=0;
			else
			{
				mat[0][i].left=mat[0][i-1].left+1;
				mat[0][i].up=1;
				mat[0][i].r=1;
				mat[0][i].c=mat[0][i].left;
				ans+=mat[0][i].left;
			}

		for(i=1;i<n;i++)
			if(s[i][0]=='0')
				mat[i][0].left=mat[i][0].c=mat[i][0].r=mat[i][0].up=0;
			else
			{
				mat[i][0].left=1;
				mat[i][0].up=mat[i-1][0].up+1;
				mat[i][0].r=mat[i][0].up;
				mat[i][0].c=1;
				ans+=mat[i][0].up;
			}

		for(i=1;i<n;i++)
			for(j=1;j<m;j++)
				if(s[i][j]=='0')
					mat[i][j].left=mat[i][j].c=mat[i][j].r=mat[i][j].up=0;
				else
				{
					ans++;
					ans+=mat[i][j-1].left;
					ans+=mat[i-1][j].up;
					mat[i][j].left=mat[i][j-1].left+1;
					mat[i][j].up=mat[i-1][j].up+1;
					mnr=Min(mat[i-1][j-1].r,mat[i-1][j].up);
					mnc=Min(mat[i-1][j-1].c,mat[i][j-1].left);
					ans+=(mnr*mnc);
					mat[i][j].c=mnc+1;
					mat[i][j].r=mnr+1;
					k=1;
					mn=mat[i-1][j].up;
					while(mat[i-1][j-k].up>mnr && mn>mnr && s[i][j-k]=='1')
					{
						mn=Min(mn,mat[i-1][j-k].up);
						ans+=(mn-mnr);
						k++;
					}
					k=1;
					mn=mat[i][j-1].left;
					while(mat[i-k][j-1].left>mnc && mn>mnc && s[i-k][j]=='1')
					{
						mn=Min(mn,mat[i-k][j-1].left);
						ans+=(mn-mnc);
						k++;
					}
				}

		printf("%d\n",ans);
	}
	return 0;
}

