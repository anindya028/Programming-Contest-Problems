#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

inline int cell(int r,int c)
{
	return r*5+c;
}

bool ok(int r,int c)
{
	return (r>=0 && r<5 && c>=0 && c<5);
}

int dr[]={1,-1,2,-2,1,-1,2,-2};
int dc[]={2,2,1,1,-2,-2,-1,-1};

struct board
{
	int state;
	int khali;
	board(){state = 0;}
	board(int _st,int _kh){ state = _st, khali = _kh;}
};

bool operator==(board u,board v)
{
	return (u.state==v.state && u.khali==v.khali);
}

#define mod 1000000
vector< pair<board,int> > got[mod+3];

void gene(board now,int lev)
{
	int i,j,r,c,rr,cc;
	pair<board,int> u(now,0),v;
	queue< pair<board,int> > q;
	q.push(u);
	got[u.first.state % mod].push_back(u);
	while(!q.empty())
	{
		v = q.front();
		q.pop();

		if(v.second == lev)
			continue;
		
		u.second = v.second + 1;
		r = v.first.khali / 5;
		c = v.first.khali % 5;
		for(i=0;i<8;i++)
		{
			rr = r + dr[i];
			cc = c + dc[i];
			if(!ok(rr,cc))
				continue;

			u.first.state = v.first.state;
			if(v.first.state & 1<<cell(rr,cc))
			{
				u.first.state ^= (1<<cell(rr,cc));
				u.first.state |= (1<<cell(r,c));
			}
			u.first.khali = cell(rr,cc);

			int idx = u.first.state % mod;
			int ok = 1;
			for(j = 0; j < got[idx].size();j++)
				if(got[idx][j].first == u.first)
					ok = 0;
			if(ok)
				got[idx].push_back(u),q.push(u);
		}
	}
}

vector< pair<board,int> > found[mod+3];
char mark[mod+3];
int cs;

int calc(board now,int lev)
{
	int i,j,r,c,rr,cc;
	pair<board,int> u(now,0),v;
	queue< pair<board,int> > q;
	q.push(u);
	j = u.first.state % mod;
	if(mark[j]!=cs)
		mark[j] = cs,
		found[j].clear();
	found[j].push_back(u);

	for(i=0;i<got[j].size();i++)
		if(got[j][i].first == u.first)
			return got[j][i].second;

	while(!q.empty())
	{
		v = q.front();
		q.pop();

		if(v.second == lev)
			continue;
		
		u.second = v.second + 1;
		r = v.first.khali / 5;
		c = v.first.khali % 5;
		for(i=0;i<8;i++)
		{
			rr = r + dr[i];
			cc = c + dc[i];
			if(!ok(rr,cc))
				continue;

			u.first.state = v.first.state;
			if(v.first.state & 1<<cell(rr,cc))
			{
				u.first.state ^= (1<<cell(rr,cc));
				u.first.state |= (1<<cell(r,c));
			}
			u.first.khali = cell(rr,cc);

			int idx = u.first.state % mod;
			int ok = 1;
			for(j = 0; j < got[idx].size();j++)
				if(got[idx][j].first == u.first)
					return (got[idx][j].second + u.second);

			if(mark[idx]!=cs)
				mark[idx] = cs,
				found[idx].clear();
			
			for( j = 0; j < found[idx].size(); j++)
				if(found[idx][j].first == u.first)
					ok = 0;

			if(ok)
				found[idx].push_back(u),q.push(u);
		}
	}
	return -1;
}

char s[10][10];
board decode(void)
{
	board ret;
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(s[i][j]=='1')
				ret.state |= (1<<cell(i,j));
			else if(s[i][j] == ' ')
				ret.khali = cell(i,j);
	return ret;
}

int main()
{
	int t,i,j;
	gets(s[0]);
	sscanf(s[0],"%d",&t);
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		{
			if(i==2 && j==2)
			{
				s[i][j] = ' ';
				continue;
			}
			if(j>i || (j==i && i<2))
				s[i][j] = '1';
			else
				s[i][j] = '0';
		}

	board ini = decode();
	int lev = 6;
	gene(ini,lev);
	while(t--)
	{
		cs++;
		for(i=0;i<5;i++)
			gets(s[i]);
		board now = decode();
		int ans = calc(now,10-lev);
		if(ans == -1)
			printf("Unsolvable in less than 11 move(s).\n");
		else
			printf("Solvable in %d move(s).\n",ans);
	}
	return 0;
}