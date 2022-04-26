#include<bits/stdc++.h>
#include<arpa/inet.h>

using namespace std;

int Client(int port)
{
   int sock = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr={AF_INET,htons(port),INADDR_ANY};
    while(connect(sock,(struct sockaddr*) &addr, sizeof(addr))<0);
    cout<<"server found"<<endl;

    return sock;
}


int powerMod(int a,int b,int N)
{
    int res=1;
    for(int i=0;i<b;i++)
    {
        res=(res*a)%N;
    }
    return res;
}

int dec(int text, int PR[2])
{
    return powerMod(text,PR[0],PR[1]);
}

int main()
{
    int port;
    cout<<"enter port number"<<endl; cin>>port;
    int sock = Client(port);

    int p,q;
    cout<<"enter p and q"<<endl;
    int phi = (p-1)*(q-1);
    int n = p*q;

    
    int e,d;
    while(true)
    {
        e = rand()%(phi-2)+2;
        if(phi%e!=0)
        {
            return false;
        }

        else{
            continue;
        }
    }

    while(true)
    {
        d = rand()%(phi-2)+2;
        if((d*e)%phi!=0)
        {
            return false;
        }
        else{
            continue;
        }
    }

    int PU[2]={e,n};
    send(sock,&PU,sizeof(PU),0);
    int PR[2]={d,n};
    int C;
    string msg="";

    while(true)
    {
        recv(sock,&C,sizeof(C),0);
        if(C==-1)
        {
            return false;
        }
        int de = dec(C,PR);
        msg+=de/100;
        msg+=de%100;
    }

    cout<<msg<<"This is the message"<<endl;


    return 0;
}