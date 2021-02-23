#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define MAX 1005
struct bigint
{
	char num[MAX];
	int len;
}big[3];

int singlemod(bigint num1,int d)
{
	bigint s1;
	int i,a,b,carry,j;
	for(i=carry=j=0;i<num1.len;i++)
	{
		a=carry*10+num1.num[i]-'0';
		b=a/d;
		s1.num[j]=b+'0';
		j++;
		carry=a-b*d;
	}
	s1.num[j]='\0';
	/*cutldzero(s1.num);
	s1.len=strlen(s1.num);
	if(!carry)
		big[0]=s1;*/
	return carry;
}

int main()
{
	int t,i,n,a[15],flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",big[0].num);
		big[0].len=strlen(big[0].num);
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=flag=0;i<n && !flag;i++)
			if(singlemod(big[0],a[i]))
				flag=1;
		if(flag)printf("%s - Simple.\n",big[0].num);
		else printf("%s - Wonderful.\n",big[0].num);
	}
	return 0;
}













