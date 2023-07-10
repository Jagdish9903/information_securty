#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cout<<"enter string : ";
    getline(cin,a);
    int n=0;
    while(a[n])
    {
        n++;
    }
    cout<<"\nlength of the string : "<<a.length()<<endl;
    string b;
    for(int i=0;i<n;i++)
    {
        b += a[n-1-i];
    }
    cout<<"\nreversed string is : "<<b<<endl;
    int count = 1;
    if(a.size() == 0)
    {
        count=0;
    }
    else
    {
        int flag=0;
        for(int i=0;i<n-1;i++)
        {
            if(isalpha(a[i]))
                flag=1;
            if(a[i]==' ' && flag==0) continue;
            else if(a[i]==' ' && isalnum(a[i+1]))
                count++;
        }
    }
    cout<<"\nthere are total "<<count<<" keywords\n";
    int s[26] = {0};
    cout<<"\nfrequency matrix of all alphabets : \n";
    for(int i=0;i<a.length();i++)
    {
        a[i] = tolower(a[i]);
        s[a[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        cout<<char(i+'a')<<" : "<<s[i]<<"\n";
    }
    int m;
    string cipher;
    cout<<"enter the number to rotate and convert string to ceaser cipher : ";
    cin>>m;
    for(int i=0;i<n;i++)
    {
        if(isalpha(a[i]))
            cipher += (char)((a[i]-'a'+m)%26 + 'a');
        else
            cipher += a[i];
    }
    cout<<"cipher text is : "<<cipher<<"\n";
}
