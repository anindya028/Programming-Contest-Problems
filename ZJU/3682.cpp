#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

int cs;
int xy[1005][1005],yz[1005][1005],xz[1005][1005];

vector<int> xx[1005][2];

int main()
{
	int n,m,t;
	scanf("%d",&t);
	char buf[100],s1[100],s2[100];
	while(t--)
	{
		cs++;
		int ans=0,x[1005][2],y[1005][2],z[1005][2],i,j,d1,d2,k;
		
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			xx[i][0].clear(),xx[i][1].clear();
		for(i=0;i<m;i++)
		{
			scanf("%s",buf);
			for(j=0;buf[j];j++)
				if(buf[j]=='=' || buf[j]==',')
					buf[j]=' ';
			sscanf(buf,"%s%d%s%d",s1,&d1,s2,&d2);
			if(d1<1 || d1>n || d2<1 || d2>n)
				continue;
			if(s1[0]>s2[0])
				swap(s1[0],s2[0]),swap(d1,d2);
			if(s1[0]=='X' && s2[0]=='Y')
			{
				if(xy[d1][d2]!=cs)
					ans+=n,x[d1][0]++,y[d2][0]++,xx[d1][0].push_back(d2);
				xy[d1][d2]=cs;
			}
			else if(s1[0]=='X' && s2[0]=='Z')
			{
				if(xz[d1][d2]!=cs)
					ans+=n,x[d1][1]++,z[d2][0]++,xx[d1][1].push_back(d2);
				xz[d1][d2]=cs;
			}
			else
			{
				if(yz[d1][d2]!=cs)
					ans+=n,y[d1][1]++,z[d2][1]++;
				yz[d1][d2]=cs;
			}
		}
		for(i=1;i<=n;i++)
			ans-=x[i][0]*x[i][1],
			ans-=y[i][0]*y[i][1],
			ans-=z[i][0]*z[i][1];

		for(i=1;i<=n;i++)
			for(j=0;j<xx[i][0].size();j++)
				for(k=0;k<xx[i][1].size();k++)
					if(yz[xx[i][0][j]][xx[i][1][k]]==cs)
						ans++;
		printf("%d\n",ans);
	}
	return 0;
}