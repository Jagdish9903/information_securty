#include<bits/stdc++.h>
using namespace std;
string key,p;
string encrypt(string s, string key)
{
    p = "";
    for(int i=0;i<s.size();i++)
    {
        if(isalnum(s[i]))
            p += toupper(s[i]);
    }
    int n = key.size();
    int m = p.size()/n;
    if(p.size()%n != 0)
        m++;
    char a[m][n];
    int k = 0;
    char c = 'A';
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(k >= p.size()) a[i][j] = c++;
            else a[i][j] = toupper(p[k++]);
        }
    }
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<key[i]<<"\t";
    }
    cout<<"\n\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n";
    string cipher;
    for(int i=0;i<n;i++)
    {
        int row = 0;
        int j = key.find(i+'0'+1);
        while(row<m)
        {
            cipher += a[row++][j];
        }
    }
    cout<<"\n";
    cout<<"cipher text : \n\n";
    for(int i=0;i<cipher.size();i++)
    {
        if(i%m == 0 && i>0) cout<<" ";
        cout<<cipher[i];
    }
    cout<<"\n";
    return cipher;
}
string decrypt(string s, string key)
{
    p = "";
    for(int i=0;i<s.size();i++)
    {
        if(isalnum(s[i]))
            p += toupper(s[i]);
    }
    int n = key.size();
    int m = p.size()/n;
    char a[m][n];
    int k=0;
    for(int i=0;i<n;i++)
    {
        int col = key.find('0'+i+1);
        int row=0;
        while(row<m)
        {
            a[row++][col] = p[k++];
        }
    }
    string decipher;
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<key[i]<<"\t";
    }
    cout<<"\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<"\t";
            decipher += a[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"decrypted text is : \n\n";
    cout<<decipher;
    cout<<"\n";
    return decipher;
}
int main()
{
    cout<<"enter the plain text : ";
    getline(cin,p);
    cout<<"enter the key : ";
    cin>>key;
    int choice;
    cout<<"\n";
    cout<<"1) enctyption 2) decryption 3) exit\n";
    cout<<"enter your choice : ";
    cin>>choice;
    if(choice == 1)
    string cipher = encrypt(p,key);
    else if(choice == 2)
    string decipher = decrypt(p,key);
    return 0;
}
