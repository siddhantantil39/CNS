#include<bits/stdc++.h>
#include<arpa/inet.h>

using namespace std;


int Client(int port)
{
    int sock = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr = {AF_INET,htons(port),INADDR_ANY};
    while(connect(sock, (struct sockaddr*) &addr, sizeof(addr))<0);
    cout<<"connection found:"<<endl;

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

int main(){

    int port;
    cout<<"Enter port no"<<endl; cin>>port;
    int sock = Client(port);

    int q,a;
    cout<<"enter q and q is prime"<<endl; cin>>q;
    cout<<"enter alpha"<<endl; cin>>a;

    int xc,yc,kc;
    xc = rand()%(q-2) + 2;
    yc = powerMod(a,xc,q);
    int ys;
    send(sock,&yc,sizeof(yc),0);
    recv(sock,&ys,sizeof(ys),0);
    kc = powerMod(ys,xc,q);
    int cipher;
    recv(sock,&cipher,sizeof(cipher),0);
    int plain = cipher^kc;
    cout<<"decrypted text:"<<plain<<endl;
}

