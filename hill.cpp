#include<bits/stdc++.h>
using namespace std;
int n;
void encrypt(string p, string key)
{
    if(key.length() <= 4)
        n = 2;
    else if(key.length() > 4)
        n = 3;
    int a[n][n];
    char c = 'A';
    int k = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(k >= key.length())
                a[i][j] = c % 'A';
            else
            {
                if(isalpha(key[k]))
                    a[i][j] = key[k]%'A';
                else if(isdigit(key[k]))
                    a[i][j] = key[k]%'0';
            }
            k++;
        }
    }
    k = 0;
    int s[n][1];
    while(p.length()%n != 0)
    {
        p += 'A';
    }
    int m = p.length();
    cout<<p<<"\n";
    cout<<"cipher text : \n";
    while(m>0)
    {
        for(int i=0;i<n;i++)
        s[i][0] = p[k++]%'A';

        int cipher[n][1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<1;j++)
            {
                cipher[i][j] = 0;
                for(int l=0;l<n;l++)
                {
                    cipher[i][j] += a[i][l]*s[l][j];
                }
                cipher[i][j] %= 26;
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<char(cipher[i][0]+'A');
        }

        m-=n;
    }
}
void decrypt(string p, string key)
{
    int n;
    if(key.length() <= 4)
        n = 2;
    else if(key.length() > 4)
        n = 3;
    int a[n][n];
    char d = 'A';
    int k = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(k >= key.length())
                a[i][j] = d % 'A';
            else
            {
                if(isalpha(key[k]))
                    a[i][j] = key[k]%'A';
                else if(isdigit(key[k]))
                    a[i][j] = key[k]%'0';
            }
            k++;
        }
    }
    double c[n][n],b[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j] = a[i][j];
            if(i==j) b[i][j] = 1;
            else b[i][j] = 0;
        }
    }
    double x,y;
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            x = c[i][k];
            y = c[k][k];
            for(int j=0;j<n;j++)
            {
                if(i!=k)
                {
                    c[i][j] = c[i][j]*y - c[k][j]*x;
                    b[i][j] = b[i][j]*y - b[k][j]*x;
                }
            }
        }
    }
    cout<<"inverse matrix : \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[i][j] = b[i][j]/c[i][i];
            cout<<b[i][j]<<"\t";
        }
        cout<<"\n";
    }

    k = 0;
    int s[n][1];
    while(p.length()%n != 0)
    {
        p += 'A';
    }
    int m = p.length();
    cout<<p<<"\n";
    cout<<"cipher text : \n";
    while(m>0)
    {
        for(int i=0;i<n;i++)
        s[i][0] = p[k++]%'A';

        int decipher[n][1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<1;j++)
            {
                decipher[i][j] = 0;
                for(int l=0;l<n;l++)
                {
                    decipher[i][j] += b[i][l]*s[l][j];
                }
                decipher[i][j] %= 26;
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<char(decipher[i][0]+'A');
        }
        m-=n;
    }
}
int main()
{
    string key, p;
    cout<<"enter the text : ";
    getline(cin,p);
    cout<<"enter the key : ";
    cin>>key;
    int choice;
    cout<<"1) encryption 2) decryption \n";
    cout<<"enter your choice : ";
    cin>>choice;
    if(choice == 1)
    {
        encrypt(p,key);
    }
    else if(choice == 2)
    {
        decrypt(p, key);
    }
}
