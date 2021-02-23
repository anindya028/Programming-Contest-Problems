//Searching
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define size 100000
struct word
{
	char eng[15];
	char dict[15];
}w[size];
char temp[50];
long bisearch(long n)
{
	long low=0,high=n-1,mid,t;
	while(low<=high)
	{
		mid=(low+high)/2;
                t=strcmp(w[mid].dict,temp);
		if(!t)return mid;
		else if(t<0)high=mid-1;
		else low=mid+1;
	}
	return -1;
}
bool operator<(word a,word b)
{
	if(strcmp(a.dict,b.dict)>=0)return 1;
	return 0;
}
int main()
{
        long i=0,n;
	while(gets(temp))
	{
		if(!temp[0])break;
		sscanf(temp,"%s%s",w[i].eng,w[i].dict);
                i++;
	}
	sort(w,w+i);
	while(gets(temp))
	{
		n=bisearch(i);
		if(n<0)printf("eh\n");
		else printf("%s\n",w[n].eng);
	}
	return 0;
}

