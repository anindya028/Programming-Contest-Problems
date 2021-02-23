#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct Numb
{
	char s[1000];
	int len;
}num[100];
bool operator<(Numb a,Numb b)
{
	char s1[1000],s2[1000];
	sprintf(s1,"%s%s",a.s,b.s);
	sprintf(s2,"%s%s",b.s,a.s);
	return strcmp(s1,s2)>0;
}
int main()
{
	int n,i;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		for(i=0;i<n;i++)
		{
			scanf("%s",num[i].s);
			num[i].len=strlen(num[i].s);
		}
		sort(num,num+n);
		for(i=0;i<n;i++)
			printf("%s",num[i].s);
		printf("\n");
	}
	return 0;
}