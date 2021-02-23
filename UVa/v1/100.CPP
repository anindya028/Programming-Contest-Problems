#include<stdio.h>

int vvvv(int c)
{
	int e=1;
	int c1=c;
	while(c1!=1)
    {
		e++;
		if(c1%2==0) c1=c1/2;
		else c1=3*c1+1;
	}
	return e;
}

int main()
{
	int p=0,q=0,max=0,x=0,g=0,tmp,p1,q1;
	while(scanf("%d%d",&p,&q)==2)
    {
		p1=p;q1=q;
		if(p>q){
			tmp=p;
			p=q;
			q=tmp;
		}
		max=1;
		for (x=p;x<=q;x++)
        {
			g=vvvv(x);
			if (g > max) max=g;
		}
		printf("%d %d %d\n",p1,q1,max);
	}
	return 0;
}