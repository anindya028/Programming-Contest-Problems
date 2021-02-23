//Adhoc
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<algorithm>
using namespace std;
char temp[25];
int gcd(int m,int n)
{
	if(!m)return n;
	else return gcd((n%m),m);
}
bool dash(void)
{
	int i;
	for(i=0;temp[i];i++)
		if(temp[i]=='-')
			return true;
	return false;
}
bool by(void)
{
	int i;
	for(i=0;temp[i];i++)
		if(temp[i]=='/')
			return true;
	return false;
}
int main()
{
	int t,i,j,num,den,a,b,c,k;
	char line[10000];
	scanf("%d\n",&t);
	for(i=0;i<t;i++)
	{
		gets(line);
		num=den=1;
		for(j=0;line[j];j++)
		{
			if(isdigit(line[j]))
			{
				for(k=0;line[j]!=' ' &&  line[j];k++,j++)
					temp[k]=line[j];
				temp[k]='\0';
				if(dash())
				{
					sscanf(temp,"%d-%d/%d",&a,&b,&c);
					num*=(a*c+b);
					den*=c;
				}
				else if(by())
				{
					sscanf(temp,"%d/%d",&a,&b);
					num*=a;
					den*=b;
				}
				else 
				{
					sscanf(temp,"%d",&a);
					num*=a;
				}
			}
			if(!line[j])break;
		}
		c=gcd(num,den);
		if(num%den==0)printf("%d\n",num/den);
		else if(num/den)printf("%d-%d/%d\n",num/den,(num%den)/c,den/c);
		else printf("%d/%d\n",num/c,den/c);
	}
	return 0;
}













