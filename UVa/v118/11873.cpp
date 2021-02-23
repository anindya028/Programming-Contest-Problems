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



int main(){

    LL r;
    int cs=0;
    while(cin>>r)
    {
        if(!r)
            break;
        LL p=6*r,q=6*r*r,n=8*r*r,s=2*r*r,t=32*r*r*r*r;
        printf("Case %d: %lld %lld %lld %lld %lld\n",++cs,p,q,n,s,t);
    }
    return 0;
}
