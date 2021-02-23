#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<algorithm>
using namespace std;
#define inf 210000000.
int main()
{
	int n,i,j,k,l=0;
	double u,p,I,mult;
	char s1[15],s2[15],line[10000];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(line);
		u=p=I=inf;
		j=0;
		while(!((line[j]=='U' || line[j]=='I' || line[j]=='P') && line[j+1]=='='))
			j++;
		for(k=j+2,l=0;isdigit(line[k]) || line[k]=='.';k++,l++)
			s1[l]=line[k];
		s1[l]='\0';
		mult=1.;
		if(line[k]=='m')mult=.001;
		else if(line[k]=='M')mult=1000000.;
		else if(line[k]=='k')mult=1000.;
		if(line[j]=='U')
		{
			sscanf(s1,"%lf",&u);
			u*=mult;
		}
		else if(line[j]=='I')
		{
			sscanf(s1,"%lf",&I);
			I*=mult;
		}
		else if(line[j]=='P')
		{
			sscanf(s1,"%lf",&p);
			p*=mult;
		}
		j+=l;
		while(!((line[j]=='U' || line[j]=='I' || line[j]=='P') && line[j+1]=='='))
			j++;
		for(k=j+2,l=0;isdigit(line[k]) || line[k]=='.';k++,l++)
			s2[l]=line[k];
		s2[l]='\0';
		mult=1.;
		if(line[k]=='m')mult=.001;
		else if(line[k]=='M')mult=1000000.;
		else if(line[k]=='k')mult=1000.;
		if(line[j]=='U')
		{
			sscanf(s2,"%lf",&u);
			u*=mult;
		}
		else if(line[j]=='I')
		{
			sscanf(s2,"%lf",&I);
			I*=mult;
		}
		else if(line[j]=='P')
		{
			sscanf(s2,"%lf",&p);
			p*=mult;
		}
		printf("Problem #%d\n",i+1);
		if(u==inf)
		{
			u=p/I;
			printf("U=%.2lfV\n\n",u);
		}
		else if(I==inf)
		{
			I=p/u;
			printf("I=%.2lfA\n\n",I);
		}
		else
		{
			p=u*I;
			printf("P=%.2lfW\n\n",p);
		}
	}
	return 0;
}













