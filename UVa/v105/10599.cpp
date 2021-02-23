#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
enum{Right=1,Down};
vector< pair<int,int> > now;
pair<int,long long> col[105];
int dp1[105][105];
int parent[105][105],R,C,got;
char s[105][105];
vector<int> ans;

int make1(int r,int c)
{
	if(r>R || c>C)
		return 0;
	if(r==R && c==C)
		return s[r][c]=='g';
	if(dp1[r][c]!=-1)
		return dp1[r][c];
	
	dp1[r][c]=make1(r+1,c);
	parent[r][c]=Down;
	
	int temp=make1(r,c+1);
	if(temp>dp1[r][c])
		dp1[r][c]=temp,parent[r][c]=Right;
	
	dp1[r][c]+=(s[r][c]=='g');
	return dp1[r][c];
}

int main()
{
	int i,j,cs=0;
	while(scanf("%d%d",&R,&C)==2)
	{
		if(R==-1)
			break;
		mem(dp1,-1),mem(parent,-1);
		mem(s,0);
	//	mem(is,0);
		ans.clear();	
	//	is.clear();
		now.clear();
		while(1)
		{
			scanf("%d%d",&i,&j);
			s[i][j]='g';
			now.push_back(make_pair(i,j));	
			if(!i)
				break;
		}
		
		got=make1(1,1);
		sort(now.begin(),now.end());
		if(now[now.size()-1]!=make_pair(R,C))
			now.push_back(make_pair(R,C));
		for(i=1;i<=C;i++)
			col[i]=make_pair(0,0);
		
		pair<int,long long> u;
		for(i=0;i<now.size();i++)
		{
			u=make_pair(0,0);
			for(j=1;j<=now[i].second;j++)
				if(col[j].first>u.first)
					u=col[j];
				else if(col[j].first==u.first)
					u.second+=col[j].second;
			u.first++;
			if(!u.second)
				u.second=1;
			col[j-1]=u;
		}
		
		printf("CASE#%d: %d %lld",++cs,got,col[C].second);

		i=j=1;
		while(i<=R || j<=C)
		{
			if(s[i][j]=='g')
				ans.push_back((i-1)*C+j);
			if(parent[i][j]==-1)
				break;
			if(parent[i][j]==Right)
				j++;
			else if(parent[i][j]==Down)
				i++;
		}

		for(i=0;i<ans.size();i++)
			printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}