#include<stdio.h>

char c[100];
long l[100],i,n,max,v,g,k,t;

void main(){
	while(gets(c)){
		sscanf(c,"%ld",&n);
		if(!n)
			break;
		max=0;
		for(k=0;k<n;k++){
			gets(c);
			l[k]=0;
			for(i=0;i<25;i++)
				if(c[i]=='X') l[k]++;
			if(l[k]>max)
				max=l[k];
		}
		for(k=0,v=0;k<n;k++)
			if(l[k]<max) v+=max-l[k];
		printf("%ld\n",v);
	}
}