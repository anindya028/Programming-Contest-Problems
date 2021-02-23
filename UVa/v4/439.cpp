#include <stdio.h>

char a1,b1,dummy;
int a,ax,b,bx,n;

void DFSknight(int x,int y,int m) 
{
	if ((n>m) && (x>0) && (x<=8) && (y>0) && (y<=8)) 
	{
		if ((x==b) && (y==bx) && (m<n)) n=m;
		DFSknight(x+2,y+1,m+1);
		DFSknight(x+1,y+2,m+1);
		DFSknight(x-2,y+1,m+1);
		DFSknight(x-1,y+2,m+1);
		DFSknight(x+2,y-1,m+1);
		DFSknight(x+1,y-2,m+1);
		DFSknight(x-2,y-1,m+1);
		DFSknight(x-1,y-2,m+1);
	}
	return;
}
int main() 
{
	while(scanf("%c%d %c%d%c",&a1,&ax,&b1,&bx,&dummy)==5) 
	{
	    a=a1-'a'+1;
		b=b1-'a'+1;
		n=6;

		DFSknight(a,ax,0);

		printf("To get from %c%d",a1,ax);
		printf(" to %c%d takes",b1,bx);
		printf(" %d knight moves.\n",n);
	}
	return 0;
}