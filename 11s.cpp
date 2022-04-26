#include<bits/stdc++.h>
#include<arpa/inet.h>

using namespace std;


int createServer(int port)
{
    int sersock = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr = {AF_INET,htons(port),INADDR_ANY};
    bind(sersock,(struct sockaddr*) &addr, sizeof(addr));
    cout<<"clien waiting"<<endl;

    listen(sersock,5);
    int sock = accept(sersock,NULL,NULL);
    cout<<"Connection done:"<<endl;
    return sock;
}

int powerMod(int a,int b,int n)
{
    int res=1;
    for(int i =0;i<b;i++)
    {
        res=(res*a)%n;
    }
    return res;
}

int enc(int msg,int PU[2])
{
    return powerMod(msg,PU[0],PU[1]);
}

int PU[2];
recv(sock,&PU,sizeof(PU),0);

int main()
{
    int port;
    cout<<"enter port number:"<<endl; cin>>port;
    int sock = createServer(port);

    string msg; cin>>msg;
    for(int i=0;i<msg.length();i+=2)
    {
        int m = (int)(msg[i]/100 + msg[i+1]);
        int en = enc(m,PU);
        send(sock,&en,sizeof(en),0);
    }

    int stop=-1;
    send(sock,&stop,sizeof(stop),0);
    


    return 0;
}