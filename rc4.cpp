#include<bits/stdc++.h>

using namespace std;

int main()
{
    string p,k,d="";
    int pt[256],ct[256],dt[256];
    int S[256],T[256],key[256];

    p = "Heywelcome";
    k = "keyishere";

    int n  = p.length();

    cout<<"PLAIN TEXT=";
     for(int i = 0;i<n;i++)
    {
        pt[i] = p[i];
        cout<<pt[i]<<" ";
    }
    cout<<endl;

    for(int i = 0;i<n;i++)
    {
        S[i] = i;
        T[i] = (int)k[i%k.length()];
    }

    int j = 0;
    for(int i = 0;i<n;i++)
    {
        j = (j+S[i]+T[i])%256;
        swap(S[i],S[j]);
    }

    int i = 0;
    j=0;

    for(i=0;i<n;i++)
    {
        j = (j+S[i])%256;
        swap(S[i],S[j]);
        int t = (S[i]+S[j])%256;
        key[i]=S[t];
    }

    cout<<"Encrypted text=";
    for(i=0;i<n;i++)
    {
        ct[i] = pt[i]^key[i];
        cout<<ct[i]<<" ";
    }
    cout<<endl;

     for(i = 0;i<n;i++)
    {
       dt[i] = ct[i]^key[i];
       d+=(char)dt[i];
    }

    cout<<"Decrypted text="<<d<<endl;
}