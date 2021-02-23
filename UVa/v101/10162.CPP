#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
int main()
{
	char s[1000];
	long one[]={1,5,2,8,3,9,2,8,7};
        long *freq,i,digit,len,a,b;
	while(scanf("%s",s)==1)
	{
		if(s[0]=='0'&&s[1]=='\0')break;
		len=strlen(s);
		if(len==1)
		{
			printf("%ld\n",one[s[0]-'1']);
			continue;
		}
		freq=(long *)calloc(10,sizeof(long));
		a=s[len-2]-'0';
                b=s[len-1]-'0';
		for(i=1;i<10;i++)
		{
			freq[i]=a;
			if(b>=i)freq[i]++;
                        freq[i]%=10;
                }
		digit=1*freq[1]+5*freq[5]+6*freq[6]+6*freq[4]+9*freq[9];
		if(freq[8]%2)digit+=6;
                if(freq[3]%2)digit+=7;
		if(freq[2]%2)digit+=4;               
		if(freq[7]%2)digit+=3;
		digit%=10;
		printf("%ld\n",digit);
                free(freq);
	}
	return 0;
}













