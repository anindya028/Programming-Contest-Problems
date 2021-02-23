/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	 long bcg,bgc,gbc,gcb,cgb,cbg,min;
	 long bot[3][3];
	while(scanf("%ld%ld%ld%ld%ld%ld%ld%ld%ld",&bot[0][0],&bot[0][1],&bot[0][2],&bot[1][0],&bot[1][1],&bot[1][2],&bot[2][0],&bot[2][1],&bot[2][2])==9)
	{
		bgc=bot[0][1]+bot[0][2]+bot[1][0]+bot[1][2]+bot[2][0]+bot[2][1];
		bcg=bot[0][1]+bot[0][2]+bot[1][0]+bot[1][1]+bot[2][0]+bot[2][2];
		min=bcg<=bgc?bcg:bgc;
		gbc=bot[0][0]+bot[0][2]+bot[1][1]+bot[1][2]+bot[2][0]+bot[2][1];
		min=gbc<=min?gbc:min;
		gcb=bot[0][0]+bot[0][2]+bot[1][1]+bot[1][0]+bot[2][2]+bot[2][1];
		min=gcb<=min?gcb:min;
		cbg=bot[0][0]+bot[0][1]+bot[1][1]+bot[1][2]+bot[2][0]+bot[2][2];
		min=cbg<=min?cbg:min;
		cgb=bot[0][0]+bot[0][1]+bot[1][0]+bot[1][2]+bot[2][2]+bot[2][1];
		min=cgb<=min?cgb:min;
		if(min==bgc)printf("BGC %ld\n",bgc);
		else if(min==bcg)printf("BCG %ld\n",bcg);
		else if(min==gcb)printf("GCB %ld\n",gcb);
		else if(min==gbc)printf("GBC %ld\n",gbc);
		else if(min==cbg)printf("CBG %ld\n",cbg);
		else printf("CGB %ld\n",cgb);
	}
	return 0;
}*/
# include <stdio.h> 
# include <string.h> 

long long a[6]; 
long long bin1[4]; 
long long bin2[4]; 
long long bin3[4]; 

char ch[6][10] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };

int main() 
{    
   long long min, index; 
    
   while( scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &bin1[1], &bin1[2], &bin1[3], &bin2[1], &bin2[2], &bin2[3], &bin3[1], &bin3[2], &bin3[3])==9 )
   { 
      min =2147483648;
       
      a[0] =  bin2[1] + bin3[1] + bin1[3] + bin3[3] + bin1[2] + bin2[2]; 
      if ( min > a[0] ) 
      { 
         min = a[0]; 
         index = 0; 
      } 
             
      a[1] =  bin2[1] + bin3[1] + bin1[2] + bin3[2] + bin1[3] + bin2[3]; 
      if ( min > a[1] ) 
      { 
         min = a[1]; 
         index = 1; 
      } 
       
      a[2] =  bin2[3] + bin3[3] + bin1[1] + bin3[1] + bin1[2] + bin2[2]; 
      if ( min > a[2] ) 
      { 
         min = a[2]; 
         index = 2; 
      } 
       
      a[3] =  bin2[3] + bin3[3] + bin1[2] + bin3[2] + bin1[1] + bin2[1]; 
      if ( min > a[3] ) 
      { 
         min = a[3]; 
         index = 3; 
      } 
       
      a[4] =  bin2[2] + bin3[2] + bin1[1] + bin3[1] + bin1[3] + bin2[3]; 
      if ( min > a[4] ) 
      { 
         min = a[4]; 
         index = 4; 
      } 

      a[5] =  bin2[2] + bin3[2] + bin1[3] + bin3[3] + bin1[1] + bin2[1]; 
      if ( min > a[5] ) 
      { 
         min = a[5]; 
         index = 5; 
      } 
       
      printf("%s %lld\n", ch[index], a[index]); 
   } 
    
   return 0; 
}













