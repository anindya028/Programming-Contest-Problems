#include<iostream> 
#include<cstdio> 
#include<cstring> 
using namespace std; 
#define inf 1000000 
int pathcost[200][200],pre[200][200]; 
int takeinput() 
{ 
      int k=0; 
      char c; 
      while(cin.get(c) &&  c!='\n') 
      { 
         if((c>='0' && c<='9') || (c=='-')) 
		 { 
               cin.unget(); 
               cin>>pathcost[0][k]; 
               if(pathcost[0][k]==-1) 
               {
				   pathcost[0][k]=inf;
				   pre[0][k]=inf;
			   }
			   else pre[0][k]=0; 
               k++; 
         } 
      } 
      return k; 
} 
int main() 
{ 
      int m1,citytax[1000],w,i,j,k,t1,t2,t,w1,w2; 
      char c;        
      scanf("%d",&m1); 
      w1=m1; 
      getchar();//one for \n and anthor for blank line 
      getchar(); 
      while(m1--) 
      { 
         if(m1!=w1-1) 
           printf("\n"); 
         w=takeinput(); 
         for( i=1;i<w;i++) 
            for( j=0;j<w;j++) 
            { 
               cin>>pathcost[i][j]; 
               if(pathcost[i][j]==-1) 
               {
				   pathcost[i][j]=inf;
				   pre[i][j]=inf;
			   }
			   else pre[i][j]=i;
            } 
         for(i=0;i<w;i++) 
            cin>>citytax[i]; 
          getchar(); 
         for(k=0;k<w;k++) 
         { 
            for(i=0;i<w;i++) 
            { 
                for(j=0;j<w;j++) 
                { 
                     if(pathcost[i][j]>(pathcost[i][k]+pathcost[k][j]+citytax[k])) 
                     { 
                        pathcost[i][j]=pathcost[i][k]+pathcost[k][j]+citytax[k]; 
                        pre[i][j]=pre[k][j]; 
                     } 
                } 
            } 
         } 
         w2=0;    
         while(cin.get(c) && c!='\n') 
         { 
              if(w2!=0) 
                  printf("\n"); 
              w2=1; 
              cin.unget(); 
              cin>>t1>>t2; 
              printf("From %d to %d :\n",t1,t2); 
              printf("Path: "); 
              j=t1-1; 
			  k=t2-1; 
              t=t2-1; 
              printf("%d",(j+1)); 
              while(j!=k) 
              { 
                   while(j!=pre[j][t]) 
                   { 
                          t=pre[j][t]; 
                   } 
                   printf("-->%d",(t+1)); 
                   j = t; 
                   t = k; 
              } 
              printf("\n"); 
              printf("Total cost : %d\n",pathcost[t1-1][t2-1]); 
              getchar(); 
         } 
                   
             
      }
	  return 0;
}
