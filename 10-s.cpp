#include<bits/stdc++.h>
#include<arpa/inet.h>

using namespace std;

int createServer(int port)
{
    int sersock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {AF_INET, htons(port), INADDR_ANY};

    bind(sersock, (struct sockaddr *) &addr, sizeof(addr));
    cout<<"\n Server Online. Set client..."<<endl;

    listen(sersock, 5);
    int sock = accept(sersock,NULL,NULL);
    cout<<"Connection Established"<<endl;

    return sock;
}

int encrypt(int M, int PU[2])
{
    int C = 1;
    for(int i=1;i<=PU[0];i++)
    {
        C = (C*M)%PU[1];
    } 
    return C;
}

int main()
{
    int port;
    cout<<"\n Enter port:"; cin>>port;
    int sock = createServer(port);

    int PU[2];
    recv(sock,&PU,sizeof(PU),0);
    cout<<"Public Key recieved"<<PU[0]<<PU[1]<<endl;

    int M;
    cin>>M;
    int C = encrypt(M,PU);
    send(sock,&C,sizeof(C),0);
    cout<<"Sent to Client"<<endl;
    
}