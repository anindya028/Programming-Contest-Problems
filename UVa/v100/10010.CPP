//Brute Force Pattern-Matching
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

char s[60][60],g[60];
int m,n,len;

bool match(int r,int c)
{
	int i,j,mh=0,k;
	//right
	for(i=0,j=c;g[i] && j<n;i++,j++)
		if(g[i]!=s[r][j])
			break;
		else
			mh++;
	if(mh==len)
		return true;
	mh=0;
	//left
	for(i=0,j=c;g[i] && j>=0;i++,j--)
		if(g[i]!=s[r][j])
			break;
		else
			mh++;
	if(mh==len)
		return true;
	mh=0;
	//up
	for(i=0,j=r;g[i] && j>=0;i++,j--)
		if(g[i]!=s[j][c])
			break;
		else
			mh++;
	if(mh==len)
		return true;
	mh=0;
	//bottom
	for(i=0,j=r;g[i] && j<m;i++,j++)
		if(g[i]!=s[j][c])
			break;
		else
			mh++;
	if(mh==len)
		return true;
	mh=0;
	//right-bottom
	for(i=0,j=r,k=c;g[i] && j<m && k<n;i++,j++,k++)
		if(g[i]!=s[j][k])
			break;
		else
			mh++;
	if(mh==len)
		return true;
	mh=0;
	//left-bottom
	for(i=0,j=r,k=c;g[i] && j<m && k>=0;i++,j++,k--)
		if(g[i]!=s[j][k])
			break;
		else
			mh++;
	if(mh==len)
		return true;
	mh=0;
	//right-up
	for(i=0,j=r,k=c;g[i] && j>=0 && k<n;i++,j--,k++)
		if(g[i]!=s[j][k])
			break;
		else
			mh++;
	if(mh==len)
		return true;
	mh=0;
	//left-up
	for(i=0,j=r,k=c;g[i] && j>=0 && k>=0;i++,j--,k--)
		if(g[i]!=s[j][k])
			break;
		else
			mh++;
	if(mh==len)
		return true;
	return false;
}

int main()
{
	int i,j,cs,t,r,c,q,k,found;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		if(cs)
			printf("\n");
		scanf("%d%d",&m,&n);
		for(i=0;i<m;i++)
			scanf("%s",s[i]);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				s[i][j]=tolower(s[i][j]);
		scanf("%d",&q);
		for(i=0;i<q;i++)
		{
			scanf("%s",g);
			for(j=0;g[j];j++)
				g[j]=tolower(g[j]);
			len=j;
			found=0;
			for(j=0;j<m && !found;j++)
				for(k=0;k<n && !found;k++)
					if(s[j][k]==g[0])
						if(match(j,k))
						{
							r=j+1;
							c=k+1;
							found=1;
						}
			printf("%d %d\n",r,c);
		}

	}

	return 0;
}

