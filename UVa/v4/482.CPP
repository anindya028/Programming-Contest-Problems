#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
using namespace std;
//#define Long __int64
//#define Long long long
struct num
{
	int ind;
	char s[50];
};
bool operator<(num a,num b)
{
	return a.ind<b.ind;
}
int main()
{
	int n,i,j,k;
	num *a;
	char temp[10000];
	gets(temp);
	sscanf(temp,"%d",&n);
	for(i=0;i<n;i++)
	{
		gets(temp);
		if(i)
		{
			gets(temp);
			printf("\n");
		}
		a=(num *)calloc(1000,sizeof(num));
        k=0;
		gets(temp);
		for(j=0;temp[j];j++,k++)
		{
			while(isdigit(temp[j]))
			{
				a[k].ind=a[k].ind*10+(temp[j]-'0');
				j++;
			}
			if(temp[j]=='\0')j--;
		}
		for(j=0;j<k;j++)scanf("%s",a[j].s);
		sort(a,a+k);
                for(j=0;j<k;j++)printf("%s\n",a[j].s);
		free(a);
    }
	return 0;
}













