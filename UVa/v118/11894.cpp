#include<stdio.h>
#include<algorithm>

using namespace std;

struct point
{
	int x,y;
}p[100005],q[100005];

bool operator<(point a,point b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}

int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		sort(p,p+n);
		for(i=0;i<n;i++)
			scanf("%d%d",&q[i].x,&q[i].y);
		sort(q,q+n);

		int f=0,ok,dx,dy;
		ok=1;
		dx=p[0].x-q[0].x;
		dy=p[0].y-q[0].y;
		for(i=1;i<n;i++)
			if(dx!=(p[i].x-q[i].x) || dy!=(p[i].y-q[i].y))
			{
				ok=0;
				break;
			}
		if(ok)
		{
			f=1;
			goto done;
		}
		//90
		ok=1;
		point temp;
		for(i=0;i<n;i++)
			temp=p[i],p[i].x=-temp.y,p[i].y=temp.x;
		sort(p,p+n);
		dx=p[0].x-q[0].x;
		dy=p[0].y-q[0].y;
		for(i=1;i<n;i++)
			if(dx!=(p[i].x-q[i].x) || dy!=(p[i].y-q[i].y))
			{
				ok=0;
				break;
			}
		if(ok)
		{
			f=1;
			goto done;
		}
		//180
		ok=1;
		for(i=0;i<n;i++)
			temp=p[i],p[i].x=-temp.y,p[i].y=temp.x;
		sort(p,p+n);
		dx=p[0].x-q[0].x;
		dy=p[0].y-q[0].y;
		for(i=1;i<n;i++)
			if(dx!=(p[i].x-q[i].x) || dy!=(p[i].y-q[i].y))
			{
				ok=0;
				break;
			}
		if(ok)
		{
			f=1;
			goto done;
		}
		//270
		ok=1;
		for(i=0;i<n;i++)
			temp=p[i],p[i].x=-temp.y,p[i].y=temp.x;
		sort(p,p+n);
		dx=p[0].x-q[0].x;
		dy=p[0].y-q[0].y;
		for(i=1;i<n;i++)
			if(dx!=(p[i].x-q[i].x) || dy!=(p[i].y-q[i].y))
			{
				ok=0;
				break;
			}
		if(ok)
		{
			f=1;
			goto done;
		}
done:;
		if(f)
			printf("MATCHED\n");
		else
			printf("NOT MATCHED\n");
	}
	return 0;
}