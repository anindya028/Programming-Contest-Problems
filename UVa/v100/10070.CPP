#include<stdio.h>
#include<string.h>
#include<math.h>
struct D
{
	char yr[16000];
	int leap:1;
	int hulu:1;
	int bulu:1;
}s;
long i,flag,length,j,dif,sum1,sum2;
int eleven(void)
{
	for(j=sum1=0;j<length;j+=2)
	{
		sum1+=(s.yr[j]-'0');
	}
	for(j=1,sum2=0;j<length;j+=2)
	{
		sum2+=(s.yr[j]-'0');
	}
	dif=labs(sum1-sum2);
	if(dif%11==0)return 1;
	else return 0;
}
int three(void)
{
	for(j=sum1=0;j<length;j++)
		sum1+=(s.yr[j]-'0');
	if(sum1%3==0)return 1;
	else return 0;
}
void main()
{
	while(scanf("%s",&s.yr)==1)
	{
		if(s.yr[0]==EOF)break;
                length=strlen(s.yr);
        	if(i)printf("\n");
		s.leap=s.hulu=s.bulu=flag=0;
		if(((s.yr[length-1]-'0')+(s.yr[length-2]-'0')*10)%4==0)
		{
			if(s.yr[length-1]!='0'||s.yr[length-2]!='0')
			{
				s.leap=1;
				if((s.yr[length-1]=='0'||s.yr[length-1]=='5')&&eleven())s.bulu=1;
			}
		}
		if(length>3)
                {
			if(s.yr[length-1]=='0'&&s.yr[length-2]=='0'&&((s.yr[length-3]-'0')+(s.yr[length-4]-'0')*10)%4==0)
			{
				s.leap=1;
				if((s.yr[length-1]=='0'||s.yr[length-1]=='5')&&eleven())s.bulu=1;
			}
		}
		if((s.yr[length-1]=='0'||s.yr[length-1]=='5')&&three())s.hulu=1;
		if(s.leap)
		{
			flag=1;
			printf("This is leap year.\n");
                }
		if(s.hulu)
		{
			flag=1;
			printf("This is huluculu festival year.\n");
                }
		if(s.bulu)
		{
                	flag=1;
			printf("This is bulukulu festival year.\n");
                }
		if(!flag)printf("This is an ordinary year.\n");
                i++;
	}
}













