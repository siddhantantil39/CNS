#include<bits/stdc++.h>
#include<arpa/inet.h>

using namespace std;

int createServer(int port)
{
    int sersock = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr = {AF_INET,htons(port), INADDR_ANY};
    bind(sersock,(struct sockaddr*) &addr,sizeof(addr));
    cout<<"Waiting for client"<<endl;
    listen(sersock,5);
    int sock = connect(sersock,NULL,NULL);
    cout<<"Client found"<<endl;

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
    cout<<"enter port number:"<<endl;
    cin>>port;

    int sock = createServer(sock);

    int q,a;
    cout<<"enter q and q is prime"<<endl; cin>>q;
    cout<<"enter alpha"<<endl; cin>>a;
    int xs,ys,ks;
    xs = rand()%(q-2) + 2;
    ys = powerMod(a,xs,q);
    int yc;
    send(sock,&ys,sizeof(ys),0);
    recv(sock,&yc,sizeof(yc),0);
    ks = powerMod(yc,xs,q);
    int m;
    cout<<"enter message"<<endl; cin>>m;
    int cipher = m^ks;
    send(sock,&cipher,sizeof(cipher),0);

    return 0;
}