#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define pye 2*acos(0.0)
#define inf 1000000000
#define min(a,b) (a<b?a:b)
struct place
{
	char s[100];
	double lat,lon;
}pl[105];

bool operator<(place A,place B)
{
	int a=strcmp(A.s,B.s);
	return a<0;
}
int binsearch(char str[],int n)
{
	int low=0,high=n-1,mid,a;
	while(low<=high)
	{
		mid=(low+high)/2;
		a=strcmp(pl[mid].s,str);
		if(!a)return mid;
		else if(a>0)high=mid-1;
		else low=mid+1;
	}
	return -1;
}
double greatCircle( double laa, double loa, double lab, double lob )
{
    double PI = acos( -1.0 ), R = 6378.0;
    double u[3] = { cos( laa ) * sin( loa ), cos( laa ) * cos( loa ), sin( laa ) };
    double v[3] = { cos( lab ) * sin( lob ), cos( lab ) * cos( lob ), sin( lab ) };
    double dot = u[0]*v[0] + u[1]*v[1] + u[2]*v[2];
    bool flip = false;
    if( dot < 0.0 )
    {
        flip = true;
        for( int i = 0; i < 3; i++ ) v[i] = -v[i];
    }
    double cr[3] = { u[1]*v[2] - u[2]*v[1], u[2]*v[0] - u[0]*v[2], u[0]*v[1] - u[1]*v[0] };
    double theta = asin( sqrt( cr[0]*cr[0] + cr[1]*cr[1] + cr[2]*cr[2] ) );
    double len = theta * R;
    if( flip ) len = PI * R - len;
    return len;
}
int main()
{
	int n,m,q,i,j,k,mat[105][105],cs=0;
	char a[105],b[105];
	while(scanf("%d%d%d",&n,&m,&q)==3)
	{
		if(!n && !m && !q)
			break;
		if(cs)
			printf("\n");
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				mat[i][j]=inf;
		for(i=0;i<n;i++)
		{
			scanf("%s%lf%lf",pl[i].s,&pl[i].lat,&pl[i].lon);
			pl[i].lat=pl[i].lat*pye/180;
			pl[i].lon=pl[i].lon*pye/180;
		}
		sort(pl,pl+n);
		for(i=0;i<m;i++)
		{
			scanf("%s%s",a,b);
			j=binsearch(a,n);
			k=binsearch(b,n);
			mat[j][k]=(int)(greatCircle(pl[j].lat,pl[j].lon,pl[k].lat,pl[k].lon)+0.5);
		}
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
		printf("Case #%d\n",++cs);
		for(i=0;i<q;i++)
		{
			scanf("%s%s",a,b);
			j=binsearch(a,n);
			k=binsearch(b,n);
			if(mat[j][k]>=inf)printf("no route exists\n");
			else printf("%d km\n",mat[j][k]);
		}
	}
	return 0;
}













