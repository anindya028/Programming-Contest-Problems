#include<stdio.h>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;

#define SIZE 5005
int pr[1300];
bool p[SIZE];
int gene(int n)
{
    int i,j;
	for(i=3;i*i<=n;i+=2)
	{
		if(!p[i/2])
		{
			for(j=i*i;j<n+1;j+=(2*i))
				p[j/2]=1;
		}
	}
	j=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
	{
		if(!p[i])
        {
			pr[j]=i*2+1;
			j++;
        }
	}
    return j;
}

vector<int> adj[1200];
vector<int> primes;
int n;

bool ok(int a,int b)
{
	char s1[10],s2[10];
	int i,s=0;
	sprintf(s1,"%d",a);
	sprintf(s2,"%d",b);
	for(i=0;i<4;i++)
		s+=(s1[i]!=s2[i]);
	return s==1;
}

void bfs(int source,int dest)
{
	int s,t,now,i,dis[1200];
	queue<int> q;
	bool visited[1200];
	for(i=0;i<n;i++)
		if(primes[i]==source)
		{	
			s=i;
			break;
		}
	for(i=0;i<n;i++)
		if(primes[i]==dest)
		{	
			t=i;
			break;
		}
	for(i=0;i<n;i++)
		visited[i]=0,dis[i]=10000000;
	visited[s]=1;
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		if(now==t)
			break;
		for(i=0;i<(int)adj[now].size();i++)
			if(!visited[adj[now][i]])
			{
				visited[adj[now][i]]=1;
				dis[adj[now][i]]=dis[now]+1;
				q.push(adj[now][i]);
			}
	}
	if(dis[t]<10000000)
		printf("%d\n",dis[t]);
	else
		printf("Impossible\n");
}

int main()
{
	int m=gene(SIZE*2),i,a,b,j,t;
	primes.clear();
	for(i=n=0;i<m;i++)
		if(pr[i]>1000)
			primes.push_back(pr[i]),n++;
	for(i=0;i<n;i++)
	{
		adj[i].clear();
		for(j=0;j<n;j++)
			if(ok(primes[i],primes[j]))
				adj[i].push_back(j);
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		bfs(a,b);
	}
	return 0;
}
