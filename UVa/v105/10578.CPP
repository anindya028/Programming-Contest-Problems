#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
int *freq;
int ans[32][5][5][5][5][5][5];
bool make(int sum)
{
	int i;
	bool flag=false;
	if(ans[sum][freq[1]][freq[2]][freq[3]][freq[4]][freq[5]][freq[6]])
	{
		if(ans[sum][freq[1]][freq[2]][freq[3]][freq[4]][freq[5]][freq[6]]==1)
			return true;
		else 
			return false;
	}
	if(sum==31)
		return false;
	if(31-sum<=6)
		if(freq[31-sum]>0)
			return true;
	for(i=1;i<=6;i++)
		if(freq[i]>0 && (sum+i)<=31)
		{
			freq[i]--;
			flag=(flag || !make(sum+i));
			freq[i]++;
		}
	if(flag)
		ans[sum][freq[1]][freq[2]][freq[3]][freq[4]][freq[5]][freq[6]]=1;
	else
		ans[sum][freq[1]][freq[2]][freq[3]][freq[4]][freq[5]][freq[6]]=2;
	return flag;
}
int main()
{
	int sum,i;
	char s[100];
	while(gets(s))
	{
		freq=(int *)calloc(10,sizeof(int));
		for(i=sum=0;s[i];i++)
		{
			sum+=(s[i]-'0');
			freq[s[i]-'0']++;
		}
		for(i=1;i<=6;i++)
			freq[i]=4-freq[i];
		if(strlen(s)%2)
		{
			if(make(sum))
				printf("%s B\n",s);
			else
				printf("%s A\n",s);
		}
		else 
		{
			if(make(sum))
				printf("%s A\n",s);
			else 
				printf("%s B\n",s);
		}
		free(freq);
	}
	return 0;
}













