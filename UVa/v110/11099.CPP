//Number theory
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 600
long pr[170];
bool p[size];
long gene(long n)
{
	int root=ceil(sqrt(n));
        long i,j;
	for(i=3;i<=root;i+=2)
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
int main()
{
	int n,*fact,m,temp,plus,min,count,j,found,last;
	register int i;
	int ans;
	m=gene(1000);
	while(scanf("%d",&n)==1)
	{
		fact=(int *)calloc(m,sizeof(int));
		temp=n;
		found=1;
		if(n>=1000000 || n<2)
		{
			printf("Not Exist!\n");
			free(fact);
			continue;
		}
		for(i=ans=count=last=0,plus=1;i<m;++i)
		{
			if(pr[i]*pr[i]>temp)break;
			while(temp%pr[i]==0)
			{
				fact[i]++;
				temp/=pr[i];
			}
			if(fact[i])
			{
				plus*=pr[i];
				count++;
			}
			if(count==1)min=pr[i];
		}
		if(temp!=1 && temp!=n)
		{
			plus*=temp;
			last=temp;
			count++;
		}
		if(plus==1 && temp==n)
		{
			if(temp>1415)
				printf("Not Exist!\n");
			else
				printf("%d\n",temp*temp);
			free(fact);
			continue;
		}
		if(count==1)ans=n*min;
		else if(count==2 && min*last==n)ans=n*min;
		else
		{
			found=0;
			for(i=n+plus;i<=2000000 && !found;i+=plus)
			{
				temp=i;
				temp/=plus;
				for(j=0;j<m && !found;j++)
				{
					if(temp%pr[j]==0 && !fact[j] && pr[j]!=last)break;
					else
					{
						while(temp%pr[j]==0)
							temp/=pr[j];
					}
					if(temp==1)
					{
						found=1;
						ans=i;
					}
				}
				if(temp!=1 && last)
				{
					while(temp%last==0)
						temp/=last;
				}
				if(temp==1)
				{
					found=1;
					ans=i;
				}
			}
		}
		if(ans>=2000000 || !found)printf("Not Exist!\n");
		else printf("%d\n",ans);
		free(fact);
	}
	return 0;
}













