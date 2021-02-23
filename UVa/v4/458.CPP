#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	char c;
	while((c=getchar())!=EOF)
	{
		if(c=='\n')printf("%c",c);
		else printf("%c",c-7);
	}
	return 0;
}













