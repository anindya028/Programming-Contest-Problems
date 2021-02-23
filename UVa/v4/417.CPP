#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iostream.h>
#define SIZE 83655
long count,count2,count3,count4;
char str[SIZE][6];
long bisearch(char *p,int l)
{
	long low=0,high,mid,a;
	if(l==2)high=count2-1;
	else if(l==3)
	{
		low=count2;
		high=count3-1;
	}
	else if(l==4)
	{
		low=count3;
		high=count4-1;
	}
	else
	{
		low=count4;
		high=count-1;
	}
	while(low<=high)
        {
		mid=(low+high)/2;
		a=strcmp(p,str[mid]);
		if(!a)return mid;                        	
		else if(a>0)low=mid+1;
		else high=mid-1;
	}
        return -1;
}
void generate(void)
{
	int i,j,k,m,n;
	for(i=0;i<25;i++)
	{
		for(j=i+1;j<26;j++)
		{
                	str[count][0]='a'+i;
			str[count][1]='a'+j;
                        str[count][2]='\0';
                        count++;
		}
	}
	count2=count;
	for(i=0;i<24;i++)
        {
		for(j=i+1;j<25;j++)
		{
			for(k=j+1;k<26;k++)
			{
				str[count][0]='a'+i;
				str[count][1]='a'+j;
				str[count][2]='a'+k;
                                str[count][3]='\0';
				count++;
				if(count==SIZE)return;
			}
		}
	}
	count3=count;
	for(i=0;i<23;i++)
	{
		for(j=i+1;j<24;j++)
		{
			for(k=j+1;k<25;k++)
			{
				for(m=k+1;m<26;m++)
				{
					str[count][0]='a'+i;
					str[count][1]='a'+j;
					str[count][2]='a'+k;
					str[count][3]='a'+m;
                                        str[count][4]='\0';
					count++;
					if(count==SIZE)return;
				}
		 	}
		}
	}
	count4=count;
	for(i=0;i<22;i++)
	{
		for(j=i+1;j<23;j++)
		{
			for(k=j+1;k<24;k++)
			{
				for(m=k+1;m<25;m++)
				{
					for(n=m+1;n<26;n++)
					{
						str[count][0]='a'+i;
						str[count][1]='a'+j;
						str[count][2]='a'+k;
						str[count][3]='a'+m;
						str[count][4]='a'+n;
						str[count][5]='\0';
						count++;
						if(count==SIZE)return;
					}
				}
			}
		}
    }
	return;
}
void main ()
{
	char s[6];
	long m; 
	int flag,i,l;
	generate();
	while(scanf("%s",s)==1)
	{
        	flag=0;
                if(s[0]==EOF&&s[1]==NULL)break;
		l=strlen(s);
		if(l==1)
		{
			if(islower(s[0]))
			{
				printf("%d\n",s[0]-96);
			}
		}
		else
		{
			for(i=0;islower(s[i])&&i<(l-1);i++)
			{
				if(s[i]>=s[i+1])
				{
					printf("0\n");
                	        	flag=1;
					break;
				} 
			}
			if(!flag)
			{
                        	m=bisearch(s,l);
				printf("%d\n",m+27);
        	        }
		}
        }

}


