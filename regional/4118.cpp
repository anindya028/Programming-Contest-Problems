#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

int vis[25][25][25];
int xx,yy,zz;
int dx[] = {0,0,0,0,1,-1};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {1,-1,0,0,0,0};

map<string,int> DIR;

struct point
{
	int x,y,z,dir;
	void scan()
	{
		scanf("%d%d%d",&x,&y,&z);
		char s[5];
		scanf("%s",s);
		dir = DIR[string(s)];
	}
}st,nd;

bool operator==(point a,point b)
{
	return a.x==b.x && a.y==b.y && a.z==b.z && a.dir==b.dir;
}

point find_next(point now)
{
	point ret;
	ret.x = now.x + dx[now.dir];
	ret.y = now.y + dy[now.dir];
	ret.z = now.z + dz[now.dir];
	ret.dir = now.dir;
	return ret;
}

int ans,lim;

bool ok(point now)
{
	return ( (now.x>=1 && now.x<=xx) && (now.y>=1 && now.y<=yy) && (now.z>=1 && now.z<=zz) && !vis[now.x][now.y][now.z]);
}

void mark(point now,int val)
{
	vis[now.x][now.y][now.z] = val;
}

void dfs(point now,int lev)
{
	if(now==nd)
	{
		if(lev<ans)
			ans = lev;
		return;
	}
	if(lev==lim)
		return;
	//3
	int f = 1,i,j=0;
	point next = now;
	for(i=0;i<3 && f;i++)
	{
		next = find_next(next);
		if(ok(next))
			mark(next,1),j++;
		else
		{
			f = 0;
			break;
		}
	}
	for(i=0;i<6 && f;i++)
	{
		if( (i/2) == (now.dir/2))
			continue;
		next.dir = i;
		point got = find_next(next);
		if(ok(got))
		{
			mark(got,1);
			dfs(got,lev+1);
			mark(got,0);
		}
	}
	next = now;
	for(i=0;i<j;i++)
	{
		next = find_next(next);
		mark(next,0);
	}
	//2
	f = 1 , j = 0;
	next = now;
	for(i=0;i<2 && f;i++)
	{
		next = find_next(next);
		if(ok(next))
			mark(next,1),j++;
		else
		{
			f = 0;
			break;
		}
	}
	for(i=0;i<6 && f;i++)
	{
		if( (i/2) == (now.dir/2))
			continue;
		next.dir = i;
		point got = find_next(next);
		if(ok(got))
		{
			point ngot = find_next(got);
			if(ok(ngot))
			{
				mark(got,1);
				mark(ngot,1);
				dfs(ngot,lev+1);
				mark(got,0);
				mark(ngot,0);
			}
		}
	}
	
	next = now;
	for(i=0;i<j;i++)
	{
		next = find_next(next);
		mark(next,0);
	}
}

int main()
{
	int cs=0,i;
	DIR["+z"] = 0, DIR["-z"] = 1;
	DIR["+y"] = 2, DIR["-y"] = 3;
	DIR["+x"] = 4, DIR["-x"] = 5;
	while(scanf("%d",&xx) && xx)
	{
		scanf("%d%d",&yy,&zz);
		st.scan();	
		st.x -= dx[st.dir];
		st.y -= dy[st.dir];
		st.z -= dz[st.dir];
		
		nd.scan();

	//	memset(vis,0,sizeof(vis));
		ans = 10;
		
		for(i=1;i<=6;i++)
		{
			lim = i;
			dfs(st,0);
			if(ans<10)
				break;
		}
		if(ans==10)
			printf("Case %d: Impossible\n",++cs);
		else
			printf("Case %d: %d\n",++cs,ans);
	}
	return 0;
}