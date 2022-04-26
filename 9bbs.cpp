#include<bits/stdc++.h>

using namespace std;

int rem3mod4()
{
    while(true){
    int min = 10000;
    int max = 100000;
    int range = max-min+1;
    int num = rand()%range+min;

    if(num%4!=3) continue;

    bool prime = true;

    for(int i=2; i <=sqrt(num);i++)
    {
        if(num%i==0)
        {
            prime=false;
        }
    }

    if(prime==true)
    {
        return num;
    }

    }
}

int bbs(int p,int q)
{
    long long n = (long long)p*q;
    long long s;
    bool flags=true;
    while(flags)
    {
        s = rand();
        if(s%n!=0||s!=0)
        {
            flags = false;
        }
        else{
            continue;
        }
            
    }
    int B = 0;
    long long x = (s*s)%n;
    for(int  i =0;i<10;i++)
    {
        x = (x*x)%n;
        B = B<<1 | (x & 1);
    }
    return B;
}

int powModN(int a, int b, int n) {

int res=1;
for(int i=0; i<b; i++)
{
    res = (res * a) % n;
}
return res;
}

void rabinMiller(int n)
{
int k = 0;
int q = n-1;
while(q % 2 == 0) 
{
q = q/2 ;
k++ ;
}
int min = 1;
 int max = n-1;
int range = max-min+1;
int a = rand()%range+min;
if(powModN(a,q,n) == 1) cout<<"inconclusive"<<endl;
for(int j=0; j<k ; j++)
{
if(powModN(a, pow(2,j)*q, n) == n-1)  cout<<"inconclusive"<<endl;
}
 cout<<"composite"<<endl;
}

int main()
{
    int p = rem3mod4();
    int q = rem3mod4();
    cout<<"P:"<<p<<endl;
    cout<<"Q:"<<q<<endl;
    int B = bbs(p,q);
    cout<<"BBS random no:"<<B<<endl;
    rabinMiller(B);
    return 0;
}