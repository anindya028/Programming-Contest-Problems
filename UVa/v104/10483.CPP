//Simulation
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define eps 1e-10
struct Triplet
{
	int a,b,c;
	int sum;
}tri[1000];
bool operator<(Triplet x,Triplet y)
{
	if(x.sum==y.sum)return (x.a<y.a);
	else return x.sum<y.sum;
}
int binsearch(int key,int n)
{
	int low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(tri[mid].sum>=key)high=mid;
		else low=mid+1;
	}
	if(tri[low].sum>=key)return low;
	else return -1;
}
int gener(void)
{
	int count=0;
	int i,j,k;
	for(i=1;i*i*i<=256000000;i++)
		for(j=i;j*j*i<=256000000 && (i+2*j)<=25600;j++)
		{
			if(i*j<=10000)continue;
			k=((i+j)*10000)/(i*j-10000);
			if(((i+j)*10000)%(i*j-10000)==0 && k>=j)
			{
				tri[count].a=i;
				tri[count].b=j;
				tri[count].c=k;
				tri[count].sum=i+j+k;
				count++;
			}
		}
	sort(tri,tri+count);
	return count;
}
int main()
{
	int i,j,count;
	double low,high;
	count=gener();
	while(scanf("%lf%lf",&low,&high)==2)
	{
		i=binsearch((int)(low*100.+eps),count);
		for(j=i;tri[j].sum<=(high*100.0+eps);j++)
		{
			printf("%.2lf = %.2lf + %.2lf + %.2lf = %.2lf * %.2lf * %.2lf\n",tri[j].sum/100.0,tri[j].a/100.0,tri[j].b/100.0,tri[j].c/100.0,tri[j].a/100.0,tri[j].b/100.0,tri[j].c/100.0);
		}
	}
	return 0;
}













