#include<stdio.h>
#include<math.h>

#define SIZE 25000
int pr[8600];
bool p[SIZE];
int gene(int n)
{
        int i,j;
	for(i=3;i*i<=n;i+=2)
	{
		if(!p[i/2])
		{
			for(j=i*i;j<n+1;j+=(2*i))p[j/2]=1;
		}
	}
	j=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
	{
		if(!p[i])
        {
			pr[j]=i*2+1;
			j++;
        }
	}
    return j;
}

int now[20000],n,f[20000];
int factor[20000],tot;

void bktk(int pos,int num)
{
	if(num>33000)
		return;
	if(pos==n)
	{
		factor[tot]=num;
		tot++;
		return;
	}
	bktk(pos+1,num);
	int i,j=num;
	for(i=1;i<=f[pos];i++)
		j*=now[pos],bktk(pos+1,j);
}

int main()
{
//	freopen("p3.in","r",stdin);
//	freopen("math.out","w",stdout);

	int m=gene(SIZE*2);	
	int i,p,q,t,cs;
	scanf("%d",&t);
	
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&p,&q);
		if(!p && !q)
		{
			printf("Case %d:\n0 0\n",cs+1);
			continue;
		}
		int x,y,found=0,temp=p;
		int ansx=1000000000,ansy;

		if(!p)
		{
			if(q<0)
				goto done;
			x=(int)sqrt((double)q)-1;
			for(i=0;i<5;i++,x++)
				if(x*x==q && x<32768)
					ansx=x,ansy=0,found=1;

			if(q%2==0 && !found)
			{
				q/=2;
				x=(int)sqrt((double)q)-1;
				for(i=0;i<5;i++,x++)
					if(x*x==q && x<32768)
						ansx=x,ansy=-x,found=1;
			}
done:
			if(found)
				printf("Case %d:\n%d %d\n",cs+1,ansx,ansy);
			else
				printf("Case %d:\nImpossible.\n",cs+1);
			continue;
		}
		
		if(temp<0)
			temp*=-1;
		n=0;
		for(i=0;i<m && pr[i]*pr[i]<=temp;i++)
			if(temp%pr[i]==0)
			{
				now[n]=pr[i];
				f[n]=0;
				while(temp%pr[i]==0)
					temp/=pr[i],f[n]++;
				n++;
			}
		if(temp>1)
			now[n]=temp,f[n]=1,n++;
		tot=0;
		bktk(0,1);
		
		for(i=0;i<tot;i++)
		{
			y=factor[i];
			x=p/y-y;
			if(x>=y && (x-y)*x==q && x>=-32768 && x<32768)
			{
				found=1;
				if(x<ansx)
					ansx=x,ansy=y;
			}
			y=-factor[i];
			x=p/y-y;
			if(x>=y && (x-y)*x==q && x>=-32768 && x<32768)
			{
				found=1;
				if(x<ansx)
					ansx=x,ansy=y;
			}
		}
		if(found)
			printf("Case %d:\n%d %d\n",cs+1,ansx,ansy);
		else
			printf("Case %d:\nImpossible.\n",cs+1);
	}
	return 0;
}
