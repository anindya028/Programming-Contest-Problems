#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<map>
using namespace std;

#define Max 100
bool wake[Max];
bool adj[Max][Max];
map<char,int> mp;

int main()
{
	int i,j,k,n,m,cnt,g,y,tc,found,f[50];
	char s[15];
	while(scanf("%d",&n)==1)
	{
		scanf("%d",&m);
		for(i=0;i<26;i++)
		{
			for(j=0;j<26;j++)
				adj[i][j]=false;
			wake[i]=false;
		}
		mp.clear();
		scanf("%s",s);
		mp[s[0]]=1;
		mp[s[1]]=2;
		mp[s[2]]=3;
		wake[0]=wake[2]=wake[1]=true;
		cnt=g=3;
		for(i=0;i<m;i++)
		{
			scanf("%s",s);
			if(mp[s[0]])
				j=mp[s[0]]-1;
			else
			{
				j=g;
				mp[s[0]]=++g;
			}
			if(mp[s[1]])
				k=mp[s[1]]-1;
			else
			{
				k=g;
				mp[s[1]]=++g;
			}
			adj[j][k]=adj[k][j]=true;
		}
		y=0;
		while(cnt<n)
		{
			found=0;
			for(i=0;i<n;i++)
				if(!wake[i])
				{
					for(j=tc=0;j<n;j++)
						if(adj[i][j] && wake[j])
							tc++;
					if(tc>=3)
					{
						f[found]=i;
						found++;
					}
				}
			for(i=0;i<found;i++)
				wake[f[i]]=true;
			if(found)
			{
				y++;
				cnt+=found;
			}
			else
				break;
		}
		if(cnt==n)
			printf("WAKE UP IN, %d, YEARS\n",y);
		else
			printf("THIS BRAIN NEVER WAKES UP\n");
	}
	return 0;
}

