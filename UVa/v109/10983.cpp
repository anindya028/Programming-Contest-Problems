#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

#define MIN(a,b) ((a)<(b)?(a):(b))

const int MAXV = 1005, MAXE = 100005, INF = 1000000005;
const long CAPINF = 2 * INF;

struct Dinic
{
                int V, source, sink;
                int eind, eadj [MAXE], enext[MAXE], elast [MAXV], start[MAXV];
                int front, back, q [MAXV], dist [MAXV];
                int ecap [MAXE];
                inline void init(int v)
                {
                        V = v;
                        eind = 0;
                        if(V > 0)
                                memset(elast, -1, V * sizeof(int));
                }
                inline void addedge(int a, int b, int cap1, int cap2)
                {
                        eadj [eind] = b;
                        ecap [eind] = cap1;
                        enext [eind] = elast [a];
                        elast [a] = eind++;
                        eadj [eind] = a;
                        ecap [eind] = cap2;
                        enext [eind] = elast [b];
                        elast [b] = eind++;
                }
                bool bfs()
                {
                        int i;
                        for(i = 0; i <= V; i++)
                                dist[i] = INF;
                        front = back = 0;
                        q [back++] = source;
                        dist [source] = 0;
                        while(front < back)
                        {
                                int top = q [front++];
                                for (int i = elast [top]; i != -1; i = enext [i])
                                        if(ecap[i] > 0 && dist [top] + 1 < dist [eadj[i]])
                                        {
                                                dist [ eadj [i]] = dist [top] + 1;
                                                q [back++] = eadj [i];
                                        }
                        }
                        return dist [sink] < INF;
                }
                int dfs(int num, int pcap)
                {
                        if( num == sink)
                                return pcap;
                        int total = 0;
                        for(int &i = start [num]; i != -1; i = enext [i])
                                if(ecap [i] > 0 && dist [num] + 1 == dist [eadj [i]])
                                {
                                        int p = dfs(eadj [i], MIN(ecap [i], pcap));
                                        ecap [i] -= p;
                                        ecap [i ^ 1] += p;
                                        pcap -= p;
                                        total += p;
                                        if(pcap == 0)
                                                break;
                                }
                        return total;
                }
                int flow(int _source, int _sink)
                {
                        if(V == 0)
                                return -1;
                        source = _source;
                        sink = _sink;
                        int total = 0;
                        while( bfs())
                        {
                                memcpy(start, elast, V * sizeof(int));
                                total += dfs(source, CAPINF);
                        }
                        return total;
                }
}G;

struct edges
{
	int u,v,c,p,e;
}ee[2005];

int tot;

bool check(int val,int n,int m,int d)
{
	G.init((d+1)*n+2);
	int i,j;
	for(i=0;i<n+m;i++)
		if(ee[i].c <= val)
		{
			if(ee[i].e == -1)
				G.addedge(ee[i].u,ee[i].v,ee[i].p,0);
			else
				G.addedge(ee[i].e*n+ee[i].u,ee[i].e*n+n+ee[i].v,ee[i].p,0);
		}

	for(i=1;i<=n;i++)
		for(j=0;j<d;j++)
			G.addedge(j*n+i,j*n+n+i,10000,0);
	
	return ((G.flow(0,d*n+n)) >= tot);
}

int main()
{
	int t,cs,n,d,m,i;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d%d",&n,&d,&m);
		for(i=0;i<m;i++)
			scanf("%d%d%d%d%d",&ee[i].u,&ee[i].v,&ee[i].p,&ee[i].c,&ee[i].e);
		for(i=tot=0;i<n;i++)
		{
			ee[i+m].u = 0;
			ee[i+m].v = i+1;
			ee[i+m].c = 0;
			scanf("%d",&ee[i+m].p);
			tot += ee[i+m].p;
			ee[i+m].e = -1;
		}

		int lo = 0, hi = 100005, mid, got = 0,ans;
		while(lo<=hi)
		{
			mid = (lo+hi)/2;
			if(check(mid,n,m,d))
				got = 1, ans = mid, hi = mid-1;
			else
				lo = mid + 1;
		}
		if(got)
			printf("Case #%d: %d\n",cs+1,ans);
		else
			printf("Case #%d: Impossible\n",cs+1);
	}
	return 0;
}