#include<bits/stdc++.h>
#include <cmath>


using namespace std;

string encrypt(string p, string k)
{
    int col = k.length();
    int row = ceil((float)p.length()/k.length());

    cout<<row<<" "<<col<<endl;


    int mat[row][col]={0};

    int z=0;
    for(int i = 0;i<row && z<p.length();i++)
    {
        for(int j=0;j<col && z<p.length();j++)
        {
            mat[i][j]=p[z++];
        }
    }

    int enc[row][col];
    string enc1="";

  for(int i = 0; i < row ; i++)
  {
      for(int j = 0;j< col ;j++)
      {
          enc[i][j]=mat[i][k[j]-49];
          enc1+=enc[i][j];
      }
  }

return enc1;

}

string decrypt(string enc,string key)
{
    int col = key.length();
    int row = ceil((float)enc.length()/key.length());



    int mat[row][col]={0};

    int z=0;
    for(int i = 0;i<row && z<enc.length();i++)
    {
        for(int j=0;j<col && z<enc.length();j++)
        {
            mat[i][j]=enc[z++];
        }
    }

    int dec[row][col];
    string dec1="";

  for(int i = 0; i < row ; i++)
  {
      for(int j = 0;j< col ;j++)
      {
          dec[i][key[j]-49]=mat[i][j];
      }
  }

for(int i = 0; i < row ; i++)
  {
      for(int j = 0;j< col ;j++)
      {
          dec1+=dec[i][j];
      }
  }


return dec1;
}


int main(){
     
     string plainText;
     cin>>plainText;
    string key;
    cin>>key;
    string enc=encrypt(plainText,key);
    cout<<"encrypted text:"<<enc<<endl;
    string dec=decrypt(enc,key);
    cout<<"Decrypted text:"<<dec<<endl;

     return 0;

}