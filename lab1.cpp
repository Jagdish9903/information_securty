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
        goto label;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==' ')
            count++;
    }
    label: cout<<"\nthere are total "<<count<<" keywords\n";
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
}
