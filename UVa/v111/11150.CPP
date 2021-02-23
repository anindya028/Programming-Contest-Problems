#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int recur(int n)
{
	if(n==1) return 0;
	else if(n==2) return 1;
	else return ((n/3)+recur(n/3 + n%3));
}
int main()
{
	int n;
	while(scanf("%d",&n)==1)
		printf("%d\n",recur(n)+n);
	return 0;
}













