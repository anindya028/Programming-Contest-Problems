#include<stdio.h>
#include<string.h>
#include<math.h>
#define size 100
unsigned long s;
int temp,i;
double tem;
void main ()
{
	
	for(;;i++)
	{
		scanf("%lu",&s);
		if(!s)break;
		temp=(int)sqrt(s);			
		tem=sqrt(s);
		if(temp==tem)printf("yes\n");
		else printf("no\n");
        }
                


}


