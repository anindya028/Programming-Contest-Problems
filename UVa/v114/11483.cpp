#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string>
using namespace std;

#define INF 1<<30
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Foro(i,n) For(i,0,n)

int main()
{
	char s[1000];
	int i,n,cs=0,j;
	while(scanf("%d",&n)==1 && n)
	{
		printf("Case %d:\n",++cs);
		printf("#include<string.h>\n#include<stdio.h>\n");
		printf("int main()\n{\n");
		gets(s);
		Foro(i,n)
		{
			gets(s);
			printf("printf(\"");
			for(j=0;s[j];j++)
				if(s[j]=='"')
					printf("\\\"");
                else if(s[j]=='\\')
                    printf("\\\\");
                else
					printf("%c",s[j]);
			printf("\\n\");\n");
		}
		printf("printf(\"\\n\");\n");
		printf("return 0;\n}\n");
	}
	return 0;
}
