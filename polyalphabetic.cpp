#include<bits/stdc++.h>
using namespace std;
string s,cipher,key,p;
string vernam(string p,string key)
{
    for(int i=0;i<p.size();i++)
    {
        if(key[i] == p[i])
            cipher += '0';
        else
            cipher += '1';
    }
    return cipher;
}
void vigenere_decrypt(string p, string key)
{
    for(int i=0;i<p.size();i++)
    {
        if(isalpha(key[i]) && isalpha(p[i]))
        {
            cipher += (p[i] - 'A' - (key[i] - 'A') + 26)%26 + 'A';
        }
        else if(isdigit(p[i]))
        {
            cipher += (p[i] - '0' - (key[i] - 'A') + 26)%26 + 'A';
        }
        else if(isdigit(key[i]))
        {
            cipher += (p[i] - 'A' - (key[i] - '0') + 26)%26 + 'A';
        }
        else
        {
            cipher += (p[i] - '0' - (key[i] - '0') + 26)%26 + 'A';
        }
    }
    cout<<"vigenere cipher decryption : "<<cipher<<"\n";
}
void vigenere(string p, string key)
{
    for(int i=0;i<p.size();i++)
    {
        if(isalpha(key[i]) && isalpha(p[i]))
        {
            cipher += (p[i] -'A' + key[i] - 'A')%26 + 'A';
        }
        else if(isdigit(p[i]))
        {
            cipher += (key[i] - 'A' + p[i] - '0')%26 + 'A';
        }
        else if(isdigit(key[i]))
        {
            cipher += (key[i] - '0' + p[i] - 'A')%26 + 'A';
        }
        else
        {
            cipher += (p[i] - '0' + key[i] - '0')%26 + 'A';
        }
    }
    cout<<"vigenere cipher : "<<cipher<<"\n";
}
int main()
{
    int f,l;
    string k;
    cout<<"enter the plain text : ";
    getline(cin,s);
    cout<<"enter the key : ";
    getline(cin,k);
    cout<<"1) vigener cipher\n2) vernam cipher\n";
    cout<<"enter your choice : ";
    cin>>f;
    cout<<"1) encryption\n2) decryption\n";
    cout<<"enter your choice : ";
    cin>>l;
    for(int i=0;i<s.length();i++)
    {
        if(isalnum(s[i]))
            p += toupper(s[i]);
    }
    for(int i=0;i<k.size();i++)
    {
        if(isalnum(k[i]))
            key += toupper(k[i]);
    }
    int n = key.size();
    if(p.size() > key.size())
    {
        for(int i=n;i<p.size();i++)
        {
            key += key[i-n];
        }
    }
    cout<<"plain text : "<<p<<"\n";
    cout<<"key : "<<key<<"\n";
    if(f==1)
    {
        if(l==1)
            vigenere(p,key);
        else if(l==2)
            vigenere_decrypt(p,key);
    }
    else if(f==2)
    {
        if(l==1)
        {
            cipher = vernam(p,key);
            cout<<"vernam cipher encryption : "<<cipher<<"\n";
        }
        else
        {
            cipher = vernam(p,key);
            cout<<"veranm cipher decryption : "<<cipher<<"\n";
        }
    }
}
