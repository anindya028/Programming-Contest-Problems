#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	double w,h,size,maxsize,temp;
	int n,i,num;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		for(i=maxsize=0;i<n;i++)
		{
			size=0;
			scanf("%lf%lf",&w,&h);
			if(h==w)size=h/2;
			else if(h>w)
			{
				if(h>=4.*w)size=w;
				else if(w>=h/4)size=h/4;
				if(w/2.>size)size=w/2.;
			}
			else
			{
				temp=h;
				h=w;
				w=temp;
				if(h>=4*w)size=w;
				else if(w>=h/4)size=h/4;
				if(w/2.>size)size=w/2.;	
			}
			if(size>maxsize)
			{
				maxsize=size;
				num=i+1;
			}
		}
		printf("%d\n",num);
	}
	return 0;
}













