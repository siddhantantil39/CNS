#include<bits/stdc++.h>
#include<arpa/inet.h>

using namespace std;

int createServer(int port)
{
    int sersock = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr = {AF_INET,htons(port),INADDR_ANY};
    bind(sersock,(struct sockaddr*) &addr, sizeof(addr));
    cout<<"client to come:"<<endl;
    int sock = accept(sersock,NULL,NULL);
    return sock;
}

int minverse(int num)
{
    for(int i = 1;i<num;i++)
    {
        if((num*i)%26==1)
        {
            return i;
        }
        else
            continue;
    }
}

int powerMod(int a, int b, int N)
{
    res=1;
    for(int i = 0;i<b;i++)
    {
        res=(res*a)%N;
    }
    return res;
}

int enc(int M)
{
    return M^1234
}

int main(){
    int port;
    cout<<"enter port number"<<endl; //cin>>port;

    int num = 45;
    cout<< minverse(num)<<endl;


    return 0 ;

}