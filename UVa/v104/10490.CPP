//Nmuber Theory
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int prime[32]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1};
int main()
{
        /*per[2]=6;
	per[3]=28;
	per[5]=496;
	per[7]=8128;
	per[13]=33550336;
	per[17]=8589869056;
	per[19]=137438691328;
	per[31]=2305843008139952128;*/
	long n;
	while(scanf("%ld",&n)==1)
	{
        	if(!n)break;
		if(prime[n])
		{
			if(n==11||n==23||n==29)printf("Given number is prime. But, NO perfect number is available.\n");
			else if (n==2)printf("Perfect: 6!\n");
			else if (n==3)printf("Perfect: 28!\n");
			else if (n==5)printf("Perfect: 496!\n");
			else if (n==7)printf("Perfect: 8128!\n");
			else if (n==13)printf("Perfect: 33550336!\n");
			else if (n==17)printf("Perfect: 8589869056!\n");
			else if (n==19)printf("Perfect: 137438691328!\n");
			else if (n==31)printf("Perfect: 2305843008139952128!\n");
			//else printf("Given number is prime. But, NO perfect number is available.\n");
		}
		else printf("Given number is NOT prime! NO perfect number is available.\n");
	}
	return 0;
}













