#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define size 250
void rev(char *p)
{
	int i=0,j=strlen(p)-1;
        char temp;
	while(i<j)
	{
		temp=p[i];
		p[i]=p[j];
		p[j]=temp;
		i++;
		j--;
	}
}
char *multi(char *a,char *b)
{
	char *ans;
	int n1=strlen(a);
	int n2=strlen(b);
        rev(a),rev(b);
	int l=n1+n2,carry=0,sum,i,j,d1,d2;
        ans=(char *)malloc((l+1)*sizeof(char));
	for(i=0;i<l-1;i++)
	{
		sum=0;
		for(j=(i<n2?0:(i-n2+1));j<=i;j++)
		{
			if(j>=n1)break;
			d1=a[j]-'0';
                        d2=b[i-j]-'0';
			sum+=d1*d2;
		}
		ans[i]=(sum+carry)%10+'0';
		carry=(carry+sum)/10;
	}
	if(carry)
	{
		ans[i]=carry+'0';
		ans[i+1]=NULL;
	}
        else ans[i]=NULL;
	rev(ans);
	return ans;
}
int cuttrzero(char *num)
{  			 //clear trailing zeros
	int i,count=0,len;
	len=strlen(num);
	for(i=len-1;i>0;i--){
		if(num[i]=='0'){
			num[i]='\0';
			count++;
		}
		else
			break;
	}
	return count;			//number of zeros been cut
}

int cutldzero(char *num){	//clear leading zeros
	int count;
	rev(num);
	count=cuttrzero(num);
	rev(num);
	return count;			//number of zeros been cut
}
void main ()
{
	char *a,b[size],c[size];
        int i;
	while(scanf("%s%s",b,c)==2)
	{
		i=cutldzero(b);
                i=cutldzero(c);
		if(strlen(b)<strlen(c))a=multi(c,b);
		else a=multi(b,c);
		i=cutldzero(a);
                printf("%s\n",a);
                
	}
}