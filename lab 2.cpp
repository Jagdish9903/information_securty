#include<iostream>
using namespace std;
int main()
{
    string s,cipher,decrepted;
    int n,m;
    cout<<"----------on the sender side :---------- \n";
    cout<<"\nenter plain text : ";
    getline(cin,s);
    do
    {
        cout<<"\nenter the shift key value to convert to ceaser cipher text : ";
        cin>>n;
    }while(n>26 || n<0);
    for(int i=0;i<s.length();i++)
    {
        if(isalpha(s[i]))
        {
            if(isupper(s[i]))
                cipher += (char)((s[i]-'A'+n)%26 + 'A');
            else
                cipher += (char)((s[i]-'a'+n)%26 + 'a');
        }
        else
            cipher += s[i];
    }
    //char r[s.length()];
    cout<<"\n----------on the receiver side :---------- \n";
    cout<<"\nreceived ceaser cipher text is : "<<cipher<<"\n";
    cout<<"\nenter the shift key value to decrypt the text : ";
    cin>>m;
    /*cout<<"\nenter the cipher text : ";
    for(int i=0;i<=s.length();i++)
    {
        scanf("%c",&r[i]);
    }*/
    string r=cipher;
    for(int i=0;i<=s.length();i++)
    {
        if(isalpha(r[i]))
        {   if(isupper(r[i]))
                decrepted += (char)((r[i]-'A'-m+26)%26 + 'A');
            else
                decrepted += (char)((r[i]-'a'-m+26)%26 + 'a');
        }
        else
            decrepted += r[i];
    }
    cout<<"\ndecrypted text is : "<<decrepted<<"\n";
    return 0;
}
