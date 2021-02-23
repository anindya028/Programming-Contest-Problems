#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

struct point
{
	int x,y,ind;
}p[305];

struct line
{
	vector<point> pp;
};

int is[305][305];

inline int triarea(point a,point b,point c)
{
	return ((a.x-b.x)*(b.y-c.y) - (a.y-b.y)*(b.x-c.x));
}

bool operator < (point a,point b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}

bool operator == (point a,point b)
{
	return a.x==b.x && a.y==b.y;
}

bool operator < (line a,line b)
{
	int i;
	for(i=0;i<a.pp.size() && i<b.pp.size();i++)
	{
		if(a.pp[i]==b.pp[i])
			continue;
		return a.pp[i]<b.pp[i];
	}
	return a.pp.size()<b.pp.size();
}

int main()
{
	int i,j,k,n=0,x,y;
	vector<line> ans;
	while(scanf("%d%d",&p[n].x,&p[n].y)==2)
	{
		if(!p[n].x && !p[n].y)
			break;
		p[n].ind=n;
		n++;
		while(scanf("%d%d",&p[n].x,&p[n].y)==2)
		{
			if(!p[n].x && !p[n].y)
				break;
			p[n].ind=n;
			n++;
		}
		
		ans.clear();

		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				is[i][j]=1;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				if(!is[i][j])
					continue;
			
				line temp;
				for(k=j+1;k<n;k++)
					if(!triarea(p[i],p[j],p[k]))
						temp.pp.push_back(p[k]);
				if(!temp.pp.size())
					continue;
				temp.pp.push_back(p[i]);
				temp.pp.push_back(p[j]);
				for(k=0;k<temp.pp.size();k++)
					for(int l=k+1;l<temp.pp.size();l++)
						is[temp.pp[k].ind][temp.pp[l].ind]=0,
						is[temp.pp[l].ind][temp.pp[k].ind]=0;
				sort(temp.pp.begin(),temp.pp.end());
				ans.push_back(temp);
			}
		
		sort(ans.begin(),ans.end());
		if(!ans.size())
			printf("No lines were found\n");
		else
		{
			printf("The following lines were found:\n");		//space hobe ??
			for(i=0;i<ans.size();i++)
			{
				for(j=0;j<ans[i].pp.size();j++)
					printf("(%4d,%4d)",ans[i].pp[j].x,ans[i].pp[j].y);
				printf("\n");
			}
		}
		n=0;
	}
	return 0;
}