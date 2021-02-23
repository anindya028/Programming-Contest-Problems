//Nasty Parsing + Dijkstra
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<list>
#include<iostream>
using namespace std;
#define inf 10000000.0
#define eps 1e-9
#define myabs(a) (((a)>0)?(a):-(a))
#define Min(a,b) (((a)<(b))?(a):(b))
#define size 310

struct point 
{
	double x,y;
}p[size];
struct node
{
	int dest;
	double cost;
}temp;

double dist(point a ,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
	int t,cs,i,j,bs,dbs,n,pos,st;
	char c;
	double tx,ty,d[size],ds,mn;
	list<node> adj[size];
	list<node>::iterator iter;
	bool visited[size];
	char s[1000];
	gets(s);
	sscanf(s,"%d",&t);
	gets(s);
	for(cs=0;cs<t;cs++)
	{
		if(cs)printf("\n");
		gets(s);
		for(i=0;i<size;i++)
		{
			visited[i]=false;
			adj[i].clear();
			d[i]=inf;
		}
		sscanf(s,"%lf%lf%lf%lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y);
		j=2;
		while(cin.get(c) && c!='\n')
		{
			cin.unget();
			st=j;
			//bs=dbs=0;
			//while(sscanf(s+bs,"%lf%lf%n",&tx,&ty,&dbs)==2 && !(tx<0) && !(ty<0))
			while(scanf("%lf%lf",&tx,&ty)==2 && !(tx<0))
			{
				//bs+=dbs;
				p[j].x=tx;
				p[j].y=ty;
				j++;
			}
			gets(s);
			for(i=st;i<j-1;i++)
			{
				temp.dest=i+1;
				ds=dist(p[i],p[i+1]);
				temp.cost=ds/666.6666666667;
				adj[i].push_back(temp);
				temp.dest=i;
				adj[i+1].push_back(temp);
			}
		}
		n=j;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				temp.dest=j;
				ds=dist(p[i],p[j]);
				temp.cost=ds/166.6666666667;
				adj[i].push_back(temp);
				temp.dest=i;
				adj[j].push_back(temp);
			}
		}
		d[0]=0;
		while(1)
		{
			mn=inf;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(d[i]<mn)
					{
						mn=d[i];
						pos=i;
					}
			if(myabs(mn-inf)<eps)break;
			visited[pos]=true;
			for(iter=adj[pos].begin();iter!=adj[pos].end();iter++)
			{
				d[iter->dest]=Min(d[iter->dest],d[pos]+iter->cost);
			}
		}
		printf("%.0lf\n",floor(d[1]+0.5));
	}
	return 0;
}













