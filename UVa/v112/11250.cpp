#include<stdio.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;

#define i64 long long
#define rep(i,n) for(i=0;i<(n);i++)
#define BASE 100000000
#define MAX 8

i64 num[10],den[10];
i64 n,m;

struct BigInt {
    i64 dig[25];
    int len;

    BigInt operator = (string s) {
        len = 0;
        string str; int i;
        reverse(s.begin(),s.end());
        rep(i,s.size()) {
            str += s[i];
            if(str.size() == 8) {
                dig[len++] = atoi(str.c_str());
                str = "";
            }
        }
        if(str.size() > 0) dig[len++] = atoi(str.c_str());
    }


    BigInt operator = (i64 n)
    {
        len = 0;
        while(n) {
            dig[len++] = n % BASE;
            n /= BASE;
        }
    }

    void Multiply(BigInt a,i64 b)
    {
        i64 i,carry=0,t;
        len = a.len;
        rep(i,a.len)
        {
            t = a.dig[i] * b + carry;
            dig[i] = t % BASE;
            carry = t / BASE;
        }
        while(carry)
        {
            dig[len++] = carry % BASE;
            carry /= BASE;
        }
    }

    void Multiply(BigInt a,BigInt b)
    {
         i64 i,carry=0,t,j;
         len = a.len + b.len + 5;
         rep(i,len) dig[i] = 0;
         rep(i,b.len) {
             carry = 0;
             rep(j,a.len)
             {
                 t = a.dig[j] * b.dig[i] + carry + dig[i+j];
                 dig[i+j] = t % BASE;
                 carry = t / BASE;
             }
             while(carry)
             {
                 carry += dig[i+j];
                 dig[i+j] = carry % BASE;
                 carry = carry / BASE;
                 j++;
             }
         }
         for(i=len-1;i>0;i--)
         {
             if(dig[i] > 0) break;
             len--;
         }
    }

    int Length()
    {
        int r=0,i;
        char s[20];
        rep(i,len-1) r += MAX;
        sprintf(s,"%lld",dig[len-1]);
        r += strlen(s);
        return r;
    }

    void Print()
    {
         int i;
         printf("%lld",dig[len-1]);
         for(i=len-2;i>=0;i--) printf("%08lld",dig[i]);
         printf("\n");
    }
};

i64 GCD(i64 a,i64 b) {
    if(b==0) return a;
    return GCD(b,a%b);
}

int main()
{
    int kase=1,i,j,len;
    i64 g;
    BigInt a,b,c;
    //freopen("inp.txt","r",stdin);
    while(scanf(" %lld %lld",&m,&n)==2 && m > 0)
    {
        printf("Case %d:\n",kase++);
        num[0] = m, num[1] = n, num[2] = (m*m+6*m+11), num[3] = (n*n+6*n+11);
        den[0] = 18*18, den[1] = m+1, den[2] = m+2, den[3] = m+3, den[4] = n+1, den[5] = n+2, den[6] = n+3;
        rep(i,4)
        {
            rep(j,7)
            {
                g = GCD(num[i],den[j]);
                num[i] /= g, den[j] /= g;
            }
        }
        a = 1; b = 1;
        rep(i,4)
        {
            c = num[i];
            a.Multiply(a,c);
        }
        rep(j,7)
        {
            c = den[j];
            b.Multiply(b,c);
        }
        a.Print();
        len = b.Length();
        rep(i,len) printf("-"); printf("\n");
        b.Print();
        printf("\n");
    }//while(1);
    return 0;
}
