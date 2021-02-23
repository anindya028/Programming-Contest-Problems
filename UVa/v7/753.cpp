#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<string>
using namespace std;	

#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define inf 1<<29
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

#define maxv 605 
int cap[maxv][maxv],parent[maxv];
queue<int> q;
bool visited[maxv];
map<string,int> mp;

//finding augmenting path using BFS
int find_path(int n,int source,int sink)
{
	int i,now,path_cap;
	Foro(i,n)
		visited[i]=0,parent[i]=-1;
	while(!q.empty())
		q.pop();
	q.push(source);
	visited[source]=1;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		Foro(i,n)
			if(!visited[i] && cap[now][i]>0)
			{
				parent[i]=now,visited[i]=1,q.push(i);
				if(i==sink)
					goto done;
			}
	}
done:
	if(!visited[sink])
		return 0;//no path found
	path_cap=inf;
	now=sink;
	while(parent[now]>-1)
		path_cap=Min(path_cap,cap[parent[now]][now]),//capacity of path
		now=parent[now];
	now=sink;
	while(parent[now]>-1)
		cap[parent[now]][now]-=path_cap,
		cap[now][parent[now]]+=path_cap,
		now=parent[now];//updating the flow network
	return path_cap;
}

int main()
{
	int i,j,tot,n,m,k,t,cs=0,mxflow;
	char s1[50],s2[50];
	string ss1,ss2;
	scanf("%d",&t);
	while(t--)
	{
		if(cs)
			printf("\n");
		cs++;
		tot=0;
		mp.clear();
		Foro(i,603)
			Foro(j,603)
				cap[i][j]=0;
		mp["source"]=tot++;
		mp["sink"]=tot++;
		scanf("%d",&n);
		Foro(i,n)
			scanf("%s",s1),ss1=s1,
			mp[ss1+"out"]=tot,cap[tot][1]=1,
			tot++,
			mp[ss1+"in"]=tot,cap[tot][tot-1]=inf,
			tot++;
		scanf("%d",&m);
		Foro(i,m)
		{
			scanf("%s%s",s1,s2),ss1=s1,ss2=s2;
			mp[ss1]=tot,cap[0][tot]=1,tot++;
			if(mp.find(ss2+"out")!=mp.end())
				cap[tot-1][mp[ss2+"in"]]=1;
			else
				mp[ss2+"in"]=tot,
				cap[mp[ss1]][tot]=1,
				tot++,
				mp[ss2+"out"]=tot,
				cap[tot-1][tot]=inf,
				tot++;
		}
		scanf("%d",&k);
		Foro(i,k)
			scanf("%s%s",s1,s2),ss1=s1,ss2=s2,cap[mp[ss1+"out"]][mp[ss2+"in"]]=inf;
		mxflow=0;
		while(1)
		{
			k=find_path(tot,0,1);
			if(!k)
				break;
			mxflow+=k;
		}
		printf("%d\n",m-mxflow);
	}
	return 0;
}