//searching
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
char s1[1000005],s2[1000005];
int give(int i,int j)
{
	for(;s2[j];j++)
	{
		if(s2[j]==s1[i])
		{
			if(s1[++i])return give(i,++j);
			else return 1;
		}
	}
	return 0;
}
int main()
{
	
	while(scanf("%s%s",s1,s2)==2)
	{
		if(give(0,0))printf("Yes\n");
		else printf("No\n");
        }
	return 0;
}













