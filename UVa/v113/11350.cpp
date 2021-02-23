#include<cstdio>
#include<cstring>
#include<cstring>
#include<iostream>

using namespace std;

#define SIZE 1000

class node
{
public:
	unsigned long long x,y;
};

char s[SIZE];
char dummy[5];
int main(void)
{
	int t,i;
	node current,left,right,temp;
	scanf("%d",&t);
	gets(dummy);
	while(t--)
	{
		gets(s);

		//initially
		current.x=1;
		current.y=1;

		left.x=0;
		left.y=1;

		right.x=1;
		right.y=0;

		for(i=0;s[i];i++)
		{
			if(s[i]=='R')
			{
				temp=current;
				current.x=current.x+right.x;
				current.y=current.y+right.y;
				left = temp;
			}
			if(s[i]=='L')
			{
				temp=current;
				current.x=current.x+left.x;
				current.y=current.y+left.y;
				right = temp;
			}
		}

		printf("%llu/%llu\n",current.x,current.y);
	/*	current.x.print();
		printf("/");
		current.y.print();
		printf("\n");*/
	}
	return 0;
}