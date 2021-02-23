#include<stdio.h>
#include<math.h>

#define PI 2*acos(0.0)

int main(void)
{
    double a,b,s,l,r,h,v1,v2;
    while(1)
    {
        scanf("%lf%lf",&a,&b);
        if(a==0 && b==0)
        {
            break;
        }
        if(a<b)
        {
            s=a;
            l=b;
        }
        else
        {
            s=b;
            l=a;
        }
        r=(s/(2*PI));
        h=l-(2*r);
        v1=PI*r*r*h;
       
        r=l/(2+2*PI);
        if((2*r)>=s)
        {
            r=s/2.0;
        }

        v2=r*r*PI*s;

        if(v1<v2)
        {
            v1=v2;
        }

        printf("%.3lf\n",v1);
    }
    return 0;
}
