#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;
	

int main()
{
	int indeg[26],outdeg[26],i,j,n,t,cnt,flag,len,u,v,k,st,end;
	bool mat[26][26];
	char s[1005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<26;i++)
		{	
			indeg[i]=outdeg[i]=0;
			for(j=0;j<26;j++)
				mat[i][j]=false;
			mat[i][i]=true;
		}
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			len=strlen(s);
			u=s[0]-'a';
			v=s[len-1]-'a';
			indeg[u]++;
			outdeg[v]++;
			mat[u][v]=mat[v][u]=true;
		}
		cnt=0;
		flag=1;
		st=end=-1;
		for(i=0;i<26 && flag;i++)
			if(indeg[i]!=outdeg[i])
			{
				cnt++;
				if((indeg[i]-outdeg[i])==1)
				{
					if(st==-1)
						st=i;
					else
						flag=0;
				}
				else if((outdeg[i]-indeg[i])==1)
				{
					if(end==-1)
						end=i;
					else
						flag=0;
				}
				else
					flag=0;
			}

		for(k=0;k<26;k++)
			for(i=0;i<26;i++)
				for(j=0;j<26;j++)
					if(mat[i][k] && mat[k][j])
						mat[i][j]=true;

		for(i=0;i<26 && flag;i++)
			if(indeg[i]+outdeg[i]>0)
				for(j=0;j<26;j++)
					if(indeg[j]+outdeg[j]>0 && !mat[i][j])
					{
						flag=0;
						break;
					}
		if(flag && (cnt==0 || cnt==2))
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");
	}
	return 0;

}
