//Adhoc
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct country
{
	char name[100];
}*c;
bool operator<(country a,country b)
{
	int k=strcmp(a.name,b.name);
	return k<0;
}
int main()
{
	int n,i,count;
	char temp[1000];
	while(scanf("%d\n",&n)==1)
	{
		c=(country *)calloc(n,sizeof(country));
		for(i=0;i<n;i++)
		{
			gets(temp);
			sscanf(temp,"%s",c[i].name);
		}
		sort(c,c+n);
		strcpy(temp,c[0].name);
		for(i=1;i<n;i++)
		{
			count=1;
			while(!strcmp(c[i].name,temp))
			{
				count++;
				i++;
			}
			printf("%s %d\n",temp,count);
			strcpy(temp,c[i].name);
		}
		free(c);
	}
	return 0;
}













