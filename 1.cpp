#include<bits/stdc++.h>

using namespace std;

// string readPlainText()
// {
// ifstream fin;
// string ptext;
// fin.open("plaintext.txt");
// fin >> ptext;
// fin.close();
// return ptext;
// }

int randoms(int key)
{
    int max=122;
    int min=97;
    int range = max - min + 1;
    int num = rand() % range + min;
    return num;
}

string genKey(string plain)
{
    unordered_map<int,int> map1;
    unordered_map<int,int> count;
    string cipher="";
    for(int i=0;i<plain.length();i++)
    {
        map1[plain[i]]=randoms((int)plain[i]);
        count[plain[i]]++;
    }

    for(auto& it : map1)
    {
        cipher+=(char)it.second;
    }
    cout<<"\nFrequency\t\tPlaintext Character\t\tCiphertext character" <<endl;

    cout<<"=========\t\t===================\t\t====================" <<endl;
    for(int i=0 ; i<plain.length() ; i++)
    {
        cout<<(float)count[plain[i]]/plain.length()<<"\t\t\t\t" << plain[i] << "\t\t\t\t" << (char)map1[plain[i]]<<endl;
    }
    return cipher;

}

string randomiseKey(string key)
{
    sort(key.begin(),key.end());
    while(next_permutation(key.begin(),key.end()))
    {
        cout<<key<<endl;
    }

    return key;

}

int main()
{
    string plain;cin>>plain;
    cout<<"Plain text:"<<plain<<endl;
    transform(plain.begin(),plain.end(),plain.begin(),::tolower);
    string key = genKey(plain);
    key = randomiseKey(key);
    cout<<"Key generated/Encrypted Text:"<<key<<endl;
}