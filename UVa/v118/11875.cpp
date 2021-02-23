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

//typedef long long LL;
typedef pair<int,int> PII;



int main(){

    int cs,i,t,n,num[20];
    scanf("%d",&t);
    for(cs=0;cs<t;cs++)
    {
            scanf("%d",&n);
            for(i=0;i<n;i++)
                scanf("%d",&num[i]);
            printf("Case %d: %d\n",cs+1,num[n/2]);
    }
    return 0;
}
