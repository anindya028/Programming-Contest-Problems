#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
char ans[100];
char roman[]={"ivxlc"};
int freq[101][5];
void unit(int n)
{
	switch(n)
	{
		case 3:strcat(ans,"i");
		case 2:strcat(ans,"i");
		case 1:strcat(ans,"i");break;
		case 4:strcat(ans,"i");
		case 5:strcat(ans,"v");break;
		case 6:strcat(ans,"vi");break;
		case 7:strcat(ans,"vii");break;
		case 8:strcat(ans,"viii");break;
		case 9:strcat(ans,"ix");break;
	}
	return;
}
void ten(int n)
{
	switch(n)
	{
		case 3:strcat(ans,"x");
		case 2:strcat(ans,"x");
		case 1:strcat(ans,"x");break;
		case 4:strcat(ans,"x");
		case 5:strcat(ans,"l");break;
		case 6:strcat(ans,"lx");break;
		case 7:strcat(ans,"lxx");break;
		case 8:strcat(ans,"lxxx");break;
		case 9:strcat(ans,"xc");break;
	}
	return;
}
int main()
{
	int n,i,j;
	for(i=1;i<100;i++)
	{
		ans[0]='\0';
		ten(i/10);
		unit(i%10);
                for(j=0;j<5;j++)freq[i][j]=freq[i-1][j];
		for(j=0;ans[j];j++)
		{
			if(ans[j]=='i')freq[i][0]++;
			else if(ans[j]=='v')freq[i][1]++;
			else if(ans[j]=='x')freq[i][2]++;
			else if(ans[j]=='l')freq[i][3]++;
			else freq[i][4]++;
		}
	}
	for(j=0;j<5;j++)freq[i][j]=freq[i-1][j];
        freq[i][4]++;
	while(scanf("%d",&n)==1 && n)printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,freq[n][0],freq[n][1],freq[n][2],freq[n][3],freq[n][4]);
	return 0;
}













