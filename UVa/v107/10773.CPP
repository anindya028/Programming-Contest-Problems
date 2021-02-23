//this is my code-wa,wa,wa,wa,wa,ce,wa,wa,wa
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define eps 1e-13
double format(double x)
{
    if(x < 0.0005)
        return 0;
    else
        return floor(x*1000. + 0.5) / 1000.;
}
int main()
{
	double d,v,u,ans;
	int n,i;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&d,&v,&u);
			if(u<=eps || v<=eps)
			{
				printf("Case %d: can't determine\n",i+1);
				continue;
			}
			if((u+eps)<=v)
			{
				printf("Case %d: can't determine\n",i+1);
				continue;
			}
			ans=d/sqrt(u*u-v*v)-d/u;
			printf("Case %d: %.3lf\n",i+1,format(ans));
		}
	}
	return 0;
}
//this is code of nafi
#include<stdio.h>
#include<math.h>

#define PI (2.*acos(0.))

#define myabs(x) ((x>0)?(x):-(x))

double format(double x){
    if(x < 0.0005)
        return 0;
    else
        return floor(x*1000. + 0.5) / 1000.;
}

int main(){
    int N,ks;
    double d,v,u;
    scanf("%d",&N);
    for(ks=1;ks<=N;ks++){
        scanf("%lf%lf%lf",&d,&v,&u);
        if(u < 1e-13 || v < 1e-13 || u <=v)
            printf("Case %d: can't determine\n",ks);
        else
            printf("Case %d: %.3lf\n",ks,format(d * (1/sqrt(u*u-v*v) - 1/u)) );
    }
    return 0;
}




                                              







