#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
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
int main()
{
	unsigned long m,n1,n2,i,count;
        char temp1[size],temp2[size];
        scanf("%lu",&m);
	for(i=0;i<m;i++)
	{
		scanf("%lu",&n1);
		count=1;
	       	sprintf(temp1,"%lu",n1);
		rev(temp1);
		sscanf(temp1,"%lu",&n2);
		n1+=n2;
		while(1)
		{
			sprintf(temp1,"%lu",n1);
                        strcpy(temp2,temp1);
			rev(temp2);
			if(!strcmp(temp1,temp2))break;
			count++;
                        sscanf(temp2,"%lu",&n2);
			n1+=n2;
                }
		printf("%lu %lu\n",count,n1);
	}
	return 0;
}