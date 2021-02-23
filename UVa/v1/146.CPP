#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;
	

int main()
{
	
	char s[60];
	while(scanf("%s",s)==1)
	{
		if(s[0]=='#')
			break;
		if(!next_permutation(s,s+strlen(s)))
			printf("No Successor\n");
		else
			printf("%s\n",s);
	}
	return 0;
}
