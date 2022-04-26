#include<bits/stdc++.h>
#include<arpa/inet.h>>

using namespace std;

int client(int port)
{
    int sock = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr = {AF_INET,htons(port),INADDR_ANY};
    while(connect(sock,(struct sockaddr*) &addr,sizeof(addr))<0;)
    cout<<"waiting:"<<endl;

    return sock;
}