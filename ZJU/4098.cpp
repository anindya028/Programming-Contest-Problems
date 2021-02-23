// no. of visible points in an l*w*h lattice
// stading on 1,1,1
// l,w,h<=10^6
// AC in 1.64 sec in ZJU

#include<stdio.h>
#include<algorithm>

using namespace std;

#define SZ 1000000
#define LL long long
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

char p[SZ+2];
int pr[80000];

int nece[SZ+2],tot,tot1,tot2;
char fr[SZ+2];
int num[SZ+2],num1[SZ+2],num2[SZ+2];
int cum1[SZ+2],cum2[SZ+2];

int gene(int n)
{
	int i,j;
	for(i=2;i*i<=n;i++)
		if(!p[i])
			for(j=i*i;j<=n;j+=i)
				p[j]=1;
	j=0;
	for(i=2;i<=n;i++)
		if(!p[i])
			pr[j++]=i;
	return j;
}

int main()
{
	int m=gene(SZ);
	int i,j,k;
	for(i=2;i<=SZ;i++)
	{
		int temp=i;
		if(!p[i])
		{
			nece[i]=1;
			num[tot]=i;
			num1[tot1++]=i;
			cum1[i]++;
			fr[tot]=1;
			tot++;
			continue;
		}
		for(j=0;pr[j]*pr[j]<=temp && j<temp;j++)
			if(temp%pr[j]==0)
			{
				temp/=pr[j];
				if(temp%pr[j]==0)
					break;
				if(nece[temp])
				{
					nece[i]=nece[temp]+1,num[tot]=i,fr[tot]=nece[i],tot++;
					if(nece[i] & 1)
						num1[tot1++]=i,cum1[i]++;
					else
						num2[tot2++]=i,cum2[i]++;
				}
				break;
			}
		
	}
	for(i=2;i<=SZ;i++)
		cum1[i]=cum1[i-1]+cum1[i],
		cum2[i]=cum2[i-1]+cum2[i];
	int cs=0;
	int l,w,h,hi,lo;
	LL ret;

	while(scanf("%d%d%d",&l,&w,&h)==3)
	{
		cs++;
		ret=3;
		l--,w--,h--;
		int hhe[3];
		hhe[0]=l,hhe[1]=w,hhe[2]=h;
		sort(hhe,hhe+3);
		l=hhe[0],w=hhe[1],h=hhe[2];

		ret+=((LL)l*(LL)w);
		ret+=((LL)w*(LL)h);
		ret+=((LL)h*(LL)l);
		ret+=((LL)l*(LL)w*(LL)h);
		
		LL v1,v2,v3,val;
		for(i=0;i<tot1;++i)
		{
			v1= l/num1[i] , v2 = w/num1[i] , v3 = h/num1[i];

			if(v3<=2)
				break;
			val = v1*(v2 + v3) + v2*v3*(1+v1);
			ret-=val;
		}
		
		for(i=0;i<tot2;++i)
		{
			v1= l/num2[i] , v2 = w/num2[i] , v3 = h/num2[i];

			if(v3<=2)
				break;
			val = v1*(v2 + v3) + v2*v3*(1+v1);
			ret+=val;
		}

		
		for(i=1;i<=2;i++)
			for(j=i;j<=2;j++)
				for(k=j;k<=2;k++)
				{
					v1=i,v2=j,v3=k;
					val = v1*(v2 + v3) + v2*v3*(1+v1);
					hi = Min(l/i,Min(w/j,h/k));
					lo = Max(l/(i+1),Max(w/(j+1),h/(k+1)));
					if(hi<lo)
						continue;
					ret-= (val * (LL)(cum1[hi]-cum1[lo]));
					ret+= (val * (LL)(cum2[hi]-cum2[lo]));
				}
		
		for(j=1;j<=2;j++)
			for(k=j;k<=2;k++)
			{
				v1=0,v2=j,v3=k;
				val = v1*(v2 + v3) + v2*v3*(1+v1);
				hi = Min(w/j,h/k);
				lo = Max(l,Max(w/(j+1),h/(k+1)));
				if(hi<lo)
					continue;
				ret-= (val * (LL)(cum1[hi]-cum1[lo]));
				ret+= (val * (LL)(cum2[hi]-cum2[lo]));
			}
		
		printf("%lld\n",ret);
	}
	return 0;
}