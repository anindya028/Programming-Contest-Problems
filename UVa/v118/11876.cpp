//team14
#pragma warning(disable:4786)
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<cmath>
#include<cctype>
#include<iostream>
#include<sstream>
#include<stack>
#include<utility>

using namespace std;

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

typedef long long LL;
typedef pair<int,int> PII;

int p[10000],pr[10000];

int gene(int n)
{
   int i,j;
   for(i=2;i*i<=n;i++)
        for(j=i*i;j<=n;j+=i)
            p[j]=1;
    j=0;
    for(i=2;i<=n;i++)
        if(!p[i])
            pr[j++]=i;
    return j;
}

int fr[1000005],cum[1000005];

int main(){

    int m=gene(10000);
    fr[1]=1;
    fr[2]=1;
    int now=2,i,j;
    while(now<=1000000)
    {
        int n=now,ans=1,f;
            for(i=0;pr[i]*pr[i]<=n;i++)
            if(n%pr[i]==0)
            {
                f=0;
                while(n%pr[i]==0)
                    n/=pr[i],f++;
                ans*=(f+1);
            }
        if(n!=1)
            ans*=2;
        now+=ans;
        fr[now]=1;

    }
    for(i=1;i<=1000000;i++)
        cum[i]=cum[i-1]+fr[i];
    int cs,t,a,b;
    scanf("%d",&t);
    for(cs=0;cs<t;cs++)
    {
            scanf("%d%d",&a,&b);
            printf("Case %d: %d\n",cs+1,cum[b]-cum[a-1]);
    }
    return 0;
}
