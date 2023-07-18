#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
string plain = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int a[26] = {0};
string encode(string key)
{
    string encrypt;
    int f[26] = {0};
    for(int i=0;i<key.size();i++)
    {
        key[i] = toupper(key[i]);
        if(f[key[i]-'A']==0 && isalpha(key[i]))
        {
            encrypt += key[i];
            f[key[i]-'A'] = 1;
        }
    }
    for(int i=0;i<26;i++)
    {
        if(f[i]==0)
        {
            encrypt += char(i+'A');
        }
    }
    for(int i=0;i<encrypt.size();i++)
    {
        a[i] = int(encrypt[i]-'A');
    }
    cout<<"\n";
    for(int i=0;i<26;i++)
    {
        cout<<char(i+'A')<<" | ";
    }
    cout<<"\n";
    for(int i=0;i<26;i++)
    {
        cout<<char(a[i]+'A')<<" | ";
    }
    return encrypt;
}
void mono(string encrypt, string s)
{
    string ans;
    cout<<"\n";
    for(int i=0;i<s.size();i++)
    {
        if(isalpha(s[i]))
        {
            s[i] = toupper(s[i]);
            ans += char(a[s[i]-'A'] + 'A');
        }
        else
        {
            ans += s[i];
        }
    }
    cout<<"\nMono alphabetic cipher : "<<ans<<"\n";
}
void dec(string encrypt,string s)
{
    string ans;
    for(int i=0;i<s.size();i++)
    {
        if(isalpha(s[i]))
        {
            s[i] = toupper(s[i]);
            int b = encrypt.find(s[i]);
            ans += char(b+'A');
        }
        else
        {
            ans += s[i];
        }
    }
    cout<<"\n\nDecrypted text : "<<ans<<"\n";
}
int main()
{
    string key,s;
    int choice;
    cout<<"enter the message : ";
    getline(cin,s);
    cout<<"enter the key : ";
    cin>>key;
    cout<<"1) encryption\n2) decryption\n3) exit\n";
    cout<<"enter the choice : ";
    cin>>choice;
        if(choice == 1)
        {
            string encrypt = encode(key);
            mono(encrypt,s);
        }
        else if(choice == 2)
        {
            string encrypt = encode(key);
            dec(encrypt,s);
        }
    return 0;
}
