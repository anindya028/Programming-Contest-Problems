#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct place
{
	char s[100];
	double lat,lon;
}pl[105];
#define pye 2*acos(0.0)
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
	int n,i=0,j,k;
	char a[105],b[105];
	while(scanf("%s",pl[i].s)==1)
	{
		if(pl[i].s[0]=='#' && pl[i].s[1]=='\0')
			break;
		scanf("%lf%lf",&pl[i].lat,&pl[i].lon);
		pl[i].lat=pl[i].lat*pye/180;
		pl[i].lon=pl[i].lon*pye/180;
		i++;
	}
	n=i;
	sort(pl,pl+n);
	while(scanf("%s%s",a,b)==2)
	{
		if(a[0]=='#' && a[1]=='\0' && b[0]=='#' && b[1]=='\0')
			break;
		j=binsearch(a,n);
		k=binsearch(b,n);
		if(j==-1 || k==-1)
		{
			printf("%s - %s\nUnknown\n",a,b);
			continue;
		}
		printf("%s - %s\n%.0lf km\n",a,b,greatCircle(pl[j].lat,pl[j].lon,pl[k].lat,pl[k].lon));
	}
	return 0;
}













