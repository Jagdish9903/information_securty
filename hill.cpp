#include<bits/stdc++.h>
using namespace std;
int n;
void encrypt(string l, string key)
{
    string p;
    for(int i=0;i<l.length();i++)
    {
        if(isalnum(l[i]))
        p.push_back(l[i]);
    }
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
                    a[i][j] = toupper(key[k])%'A';
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
        s[i][0] = toupper(p[k++])%'A';

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
void decrypt(string l, string key)
{
    string p;
    for(int i=0;i<l.length();i++)
    {
        if(isalnum(l[i]))
            p.push_back(l[i]);
    }
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
                    a[i][j] = toupper(key[k])%'A';
                else if(isdigit(key[k]))
                    a[i][j] = key[k]%'0';
            }
            k++;
        }
    }
    int det;
    if(n==3)
        det = a[0][0] * ((a[1][1]*a[2][2]) - (a[2][1]*a[1][2])) -a[0][1] * (a[1][0]
        * a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
    else if(n==2)
        det = a[0][0]*a[1][1] - a[1][0]*a[0][1];
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
    int tmp = (det + 26000) % 26;
    if(26 % tmp == 0 || tmp%2 == 0)
    {
        cout<<"it is not possible to decrypt this text with given key!\n";
        return;
    }
    vector<int> xx = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
    vector<int> yy = {1, 9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25};
    cout<<"inverse matrix : \n";
    long div;
    if(find(xx.begin(),xx.end(),tmp) != xx.end())
    {
        auto it = find(xx.begin(),xx.end(),tmp);
        int i = it - xx.begin();
        div = yy[i];
    }
    cout<<"det = "<<det<<endl;
    cout<<"div = "<<div<<endl;
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[i][j] = (b[i][j] * det)/(int)(c[i][i]);
            cout<<b[i][j]<<"\t";
        }
        cout<<"\n";
    }*/
    int flag = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[j][i] = a[(i+1)%3][(j+1)%3]*a[(i+2)%3][(j+2)%3] - a[(i+2)%3][(j+1)%3]*a[(i+1)%3][(j+2)%3];
            b[j][i] *= flag;
            cout<<b[j][i]<<" ";
            flag *= -1;
        }
        cout<<endl;
    }
    int f[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            f[i][j] = (((((int)b[i][j] + 26000) % 26)) * div) % 26;
            cout<<f[i][j]<<"\t";
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
        s[i][0] = toupper(p[k++])%'A';

        int decipher[n][1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<1;j++)
            {
                decipher[i][j] = 0;
                for(int l=0;l<n;l++)
                {
                    decipher[i][j] += f[i][l]*s[l][j];
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

