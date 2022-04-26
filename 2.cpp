#include<bits/stdc++.h>

using namespace std;

void getPosition(char c,int arr[2],int mat[5][5])
{
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(c == mat[i][j])
            {
                arr[0]=i;
                arr[1]=j;
            }
}


void encrypt(int mat[5][5],string plain)
{
    string c="";
    for(int i=0;i<plain.length();i+=2)
    {
        int arr1[2];
        getPosition(plain[i],arr1,mat);
        int arr2[2];
        getPosition(plain[i+1],arr2,mat);

        if(arr1[1]==arr2[1])
        {
            c+=(char)mat[arr1[1]][arr1[2]%5];
            c+=(char)mat[arr2[1]][arr2[2]%5];

        }
        else if(arr1[2]==arr2[2])
        {
            c+=(char)mat[arr1[1]%5][arr1[2]];
            c+=(char)mat[arr2[1]%5][arr2[2]];

        }
        else
        {
            c+=(char)mat[arr1[1]][arr2[2]];
            c+=(char)mat[arr2[1]][arr1[2]];
        }

    }

    cout<<c<<endl;
}

void createMatrix(string key,string plain){

    int mat[5][5]={0};
    int flag[26]={0};
   
    //entering key into matrix
    int keyit=0;
    int i,j;
    for( i = 0;i<5 && keyit<key.length();i++)
    {
        j=0;
        while(j<5)
        {
            if(flag[key[keyit]-'a']==0){
                mat[i][j++]=key[keyit];
                flag[key[keyit]-'a']=1;
            }
            keyit++;
        }

    }
    i=i-1;
    //entering rest of values into the matrix
    keyit=0;
    while(i<5)
    {
       while(j<5)
        {
            if(flag[keyit]==0){
                mat[i][j]=keyit+97;
                j++;
            }
            keyit++;
        }
        i++;
        j=0;
    }

    encrypt(mat,plain);
}



int main(){

    string key;
    cin>>key;
    string plain;
    cin>>plain;
    cout<<"Plain text:"<<plain<<endl;
    cout<<"Key text:"<<key<<endl;
    transform(key.begin(),key.end(),key.begin(),::tolower);
    createMatrix(key,plain);



    return 0;
}