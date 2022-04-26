#include<bits/stdc++.h>

using namespace std;

int permChoiceOne[] = {
57, 49, 41, 33, 25, 17, 9 ,
1 , 58, 50, 42, 34, 26, 18,
10, 2 , 59, 51, 43, 35, 27,
19, 11, 3 , 60, 52, 44, 36,
63, 55, 47, 39, 31, 23, 15,
7 , 62, 54, 46, 38, 30, 22,
14, 6 , 61, 53, 45, 37, 29,
21, 13, 5 , 28, 20, 12, 4 };

int permChoiceTwo[] = {
14, 17, 11, 24, 1 , 5 , 3 , 28,
15, 6 , 21, 10, 23, 19, 12, 4 ,
26, 8 , 16, 7 , 27, 20, 13, 2 ,
41, 52, 31, 37, 47, 55, 30, 40,
51, 45, 33, 48, 44, 49, 39, 56,
34, 53, 46, 42, 50, 36, 29, 32 };

int leftShiftTable[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};


string rotateString(string key,int rot)
{
    return key.substr(rot,key.length()-rot)+key.substr(0,rot);
}

string permutationOne(string key)
{
    string res=" ";
    for(int i =0;i<56;i++)
    {
        res+=permChoiceOne[key[i]-1];
    }
    return res;
}

string permutationTwo(string key)
{
    string res=" ";
    for(int i =0;i<48;i++)
    {
        res+=permChoiceTwo[key[i]-1];
    }
    return res;
}


void keyGen(string left,string right)
{
    for(int i = 0;i<16;i++)
    {
        string res=" ";
        left=rotateString(left,leftShiftTable[i]);
        right=rotateString(right,leftShiftTable[i]);
        res = left+right;
        res=permutationTwo(res);
        cout<<"Key"<<i<<" "<<res<<endl;
        
    }

}



int main()
{
    unsigned long long keyH;
    cout<<"enter hex key"<<endl;
    cin>>hex>>keyH;

    string key = bitset<64>(keyH).to_string();

    cout<<"Binary key:"<<key<<endl;

    string key56 = permutationOne(key);
    keyGen(key56.substr(0,28),key56.substr(28,28));



    return 0;
}