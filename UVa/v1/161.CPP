//this is my code:wa,wa,wa,ac 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int sig[105],j,i,*freq,flag,ans,min;
	while(scanf("%d",&sig[0])==1)
	{
		if(!sig[0])
		{
			scanf("%d%d",&sig[1],&sig[2]);
			break;
		}
		min=sig[0];
		i=1;
		while(scanf("%d",&sig[i++])==1)
		{
			if(sig[i-1] && sig[i-1]<min)min=sig[i-1];
			if(!sig[i-1])break;
		}
		freq=(int *)calloc((5*60*60+5),sizeof(int));
		for(i=flag=0;sig[i];i++)
		{
			for(j=sig[i]-5+1;j<=(5*60*60+1);j++)
			{
				freq[j]=1;
				if(j%sig[i]==0 && (j/sig[i])%2==0)j+=(sig[i]-5);
			}
		}
		for(i=min;i<=(5*60*60+1);i++)
		{
			if(!freq[i])
			{
				flag=1;
				ans=i-1;
				break;
			}
		}
		if(!flag)
		{
			printf("Signals fail to synchronise in 5 hours\n");
			continue;
		}
		printf("%02d:%02d:%02d\n",ans/3600,(ans%3600)/60,(ans%3600)%60);
		free(freq);
	}
	return 0;
}
/*int main() 
{ 
   int sig[101]; // input, cycle time 
   const int mt=5*60*60+1; // max time 
   int green[mt]; // how many signals are green 
   int count, i; 
    
   for (;;) 
   { 
      // read input 
      for (count=0;; count++)   { 
         scanf("%d", &sig[count]); 
         if (sig[count] == 0) break; 
      } 
      if (sig[0] == 0) break; // exit condition 

      for (i=0; i < mt; i++) green[i] = 0; 
       
      for (i=0; i < count; i++) // for every signal 
      { 
         for (int k=0; k < mt; k+=sig[i]*2) // for every cycle 
         { 
            for (int m=0; m < sig[i]-5; m++) // mark when it's green 
               if (k+m < mt) green[k+m] += 1; 
         } 
      } 

      // check when all signals were green 
      for (i=sig[0]+1; i < mt; i++) 
      { 
         if (green[i]==count) break; 
      } 
      if (i == mt) printf("Signals fail to synchronise in 5 hours\n"); 
      else { 
         int g = i/3600; 
         int m = (i-g*3600)/60; 
         int s = i-g*3600-m*60; 
         printf("0%d:", g); 
         if (m < 10) printf("0"); 
         printf("%d:", m); 
         if (s < 10) printf("0"); 
         printf("%d\n", s); 
      } 
   }// for (;;) 

   scanf("%d", &sig[0]); // read following zeros 
   scanf("%d", &sig[0]); 
   return 0; 
}












