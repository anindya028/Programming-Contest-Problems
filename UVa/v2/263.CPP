#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
void rev(char *t)
{
	int i=0,j=strlen(t)-1;
	char temp;
	while(i<j)
	{
		temp=t[i];
		t[i]=t[j];
		t[j]=temp;
		i++;
		j--;
	}
	return;
}
int sort_function( const void *a, const void *b)
{
	return strcmp((char *)a,(char *)b);
}
int main()
{
	long n,n1,n2,len,*prev,i,j,flag,chain,cur;
	char temp1[15],temp2[15];
	while(scanf("%ld",&n)==1)
	{
		if(!n)break;
		chain=0;
		printf("Original number was %ld\n",n);
		cur=n;
		prev=(long *)calloc(1005,sizeof(long));
                j=flag=0;
                while(1)
		{
			sprintf(temp1,"%ld",cur);
			len=strlen(temp1);
			qsort((void *)temp1,len, sizeof(temp1[0]),sort_function);
			strcpy(temp2,temp1);
			rev(temp1);
			sscanf(temp1,"%ld",&n1);
			sscanf(temp2,"%ld",&n2);
			cur=n1-n2;
			printf("%ld - %ld = %ld\n",n1,n2,cur);
                        chain++;
			for(i=0;i<j;i++)
				if(prev[i]==cur)flag=1;
			if(flag)break;
			prev[j]=cur;
			j++;
		}
		printf("Chain length %ld\n\n",chain);
	}
	return 0;
}













