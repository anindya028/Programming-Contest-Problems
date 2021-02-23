#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

pair<int,int> u,v;

map< pair<int,int>,int > mp;

int mat[205][205];

int main()
{
	int t,n,m,i,j,k,ans;
	double ux,uy,vx,vy;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&m);
		mp.clear();
		for(i=0;i<202;i++)
			for(j=0;j<202;j++)
				mat[i][j]=0;
		for(i=ans=n=0;i<m;i++)
		{
			scanf("%lf%lf%lf%lf",&ux,&uy,&vx,&vy);
			u.first=(int)floor(10*(ux+1e-7));
			u.second=(int)floor(10*(uy+1e-7));
			v.first=(int)floor(10*(vx+1e-7));
			v.second=(int)floor(10*(vy+1e-7));
			if(mp.find(u)==mp.end())
				mp[u]=n++;
			if(mp.find(v)==mp.end())
				mp[v]=n++;
			j=mp[u];
			k=mp[v];
			mat[j][k]=mat[k][j]=1;
		}
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(mat[i][j])
				for(k=j+1;k<n;k++)
					if(mat[j][k] && mat[k][i])
						ans++;
		printf("%d\n",ans);
	}
	return 0;
}
