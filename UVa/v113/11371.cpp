//Adhoc :Hard
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdlib>

using namespace std;


char S[20];

long long getval(char* str)
{
	int i;
	int l=strlen(str);
	i=0;
	long long sum=0;
	while(str[i])
	{
		sum*=10;
		sum+=S[i]-'0';
		i++;
	}
	return sum;
}

int main(void)
{
	char temp;
	while(gets(S))
	{
		int l=strlen(S);
		sort(S,S+l);

		int i,j;
		i=0;
		j=l-1;
		while(i<j)
		{
			temp=S[i];
			S[i]=S[j];
			S[j]=temp;
			i++;
			j--;
		}
		long long hi;//=atoi(S);
		hi=getval(S);

		i=0;
		j=l-1;
		while(i<j)
		{
			temp=S[i];
			S[i]=S[j];
			S[j]=temp;
			i++;
			j--;
		}

	
		i=0;
		while(S[i]=='0')i++;
		temp=S[0];
		S[0]=S[i];
		S[i]=temp;

		
		long long lo=getval(S);	
		long long div=(hi-lo)/9;

		printf("%lld - %lld = %lld = 9 * %lld\n",hi,lo,hi-lo,div);
	}
	return 0;
}

