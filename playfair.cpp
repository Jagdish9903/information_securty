#include<bits/stdc++.h>
using namespace std;
int m[5][5];
string ans,dec_ans;
int flag = 0;
void matrix(string s,string key)
{
    int a[26] = {0};
    for(int i=0;i<key.size();i++)
    {
        if(isalpha(key[i]))
        {
            key[i] = toupper(key[i]);
            a[key[i]-'A']=1;
            if(key[i]=='J' || key[i]=='I')
            {
                if(key[i] == 'J' && flag == 0) flag=10;
                if(key[i] == 'I' && flag == 0) flag=9;
                a[8] = 2;
                a[9] = 2;
            }
        }
    }
    int r=0,c=0;
    for(int i=0;i<key.size();i++)
    {
        if(a[key[i]-'A']==1)
        {
            m[r][c++] = int(key[i]);
            a[key[i]-'A'] = -1;
        }
        else if(a[key[i]-'A']==2)
        {
            m[r][c++] = int(key[i]);
            if(key[i] == 'I' && flag == 0) flag = 9;
            else if(key[i] == 'J' && flag == 0) flag = 10;
            a[8] = -1;
            a[9] = -1;
        }
        if(c==5)
        {
            r++;
            c=0;
        }
    }
    for(int i=0;i<26;i++)
    {
        if(a[i]==0)
        {
            if(i==8)
            {
                m[r][c++] = int('A'+i);
                i++;
            }
            else
            m[r][c++] = int('A'+i);
        }
        if(c==5)
        {
            r++;
            c=0;
        }
    }
    cout<<"matrix is : \n\n";
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<(char)(m[i][j])<<"\t";
        }
        cout<<"\n";
    }
}
string duplicate(string s)
{
    string dup;
    for(int i=0;i<s.length();i++)
    {
        if(!isalnum(s[i]))
        {
            continue;
        }
        else
        {
            dup += toupper(s[i]);
        }
    }
    return dup;
}

string convert(string &dup)
{
    string dup2;
    for(int i=0;i<dup.size();i++)
    {
        if(dup[i] == dup[i+1] || ((dup[i] == 'I' || dup[i+1] == 'I') && (dup[i] == 'J' || dup[i+1] == 'J')))
        {
            dup2 += dup[i];
            if(dup[i] != 'X')
                dup2 += 'X';
            else
                dup2 += 'Y';

            dup2 += ' ';
        }
        else
        {
            dup2 += dup[i];
            dup2 += dup[i+1];
            dup2 += ' ';
            i++;
        }
    }
    int count = 0;
    int n = dup2.length();
    for(int i=0;i<n;i++)
    {
        if(isalpha(dup2[i]))
            count++;
    }
    if(count%2)
    {
        if(dup2[n-3]!='X')
        dup2[n-2] = 'X';
        else
        dup2[n-2] = 'Y';
    }
    return dup2;
}
void lastenc(int p,int q)
{
    int find[4];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(m[i][j] == char(p))
            {
                find[0] = i;
                find[1] = j;
            }
            if(m[i][j] == char(q))
            {
                find[2] = i;
                find[3] = j;
            }
        }
    }
    if(find[0] == find[2])
    {
        ans += char(m[find[0]][(find[1]+1)%5]);
        ans += char(m[find[2]][(find[3]+1)%5]);
        ans += ' ';
    }
    else if(find[1] == find[3])
    {
        ans += char(m[(find[0]+1)%5][find[1]]);
        ans += char(m[(find[2]+1)%5][find[3]]);
        ans += ' ';
    }
    else
    {
        ans += char(m[find[0]][find[3]]);
        ans += char(m[find[2]][find[1]]);
        ans += ' ';
    }
}
void encrypt(string dup2)
{
    int p,q;
    for(int i=0;i<dup2.length()-1;i+=3)
    {
        p = dup2[i];
        q = dup2[i+1];
        if(flag == 9)
        {
            if(p == 'J')
                p = 'I';
            if(q == 'J')
                q = 'I';
        }
        else if(flag == 10)
        {
            if(p == 'I')
                p = 'J';
            if(q == 'I')
                q = 'J';
        }
        lastenc(p,q);
    }
}
void decription(int p,int q)
{
    int find[4];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(m[i][j] == char(p))
            {
                find[0] = i;
                find[1] = j;
            }
            if(m[i][j] == char(q))
            {
                find[2] = i;
                find[3] = j;
            }
        }
    }
    if(find[0] == find[2])
    {
        dec_ans += char(m[find[0]][(find[1]-1+5)%5]);
        dec_ans += char(m[find[2]][(find[3]-1+5)%5]);
        dec_ans += ' ';
    }
    else if(find[1] == find[3])
    {
        dec_ans += char(m[(find[0]-1+5)%5][find[1]]);
        dec_ans += char(m[(find[2]-1+5)%5][find[3]]);
        dec_ans += ' ';
    }
    else
    {
        dec_ans += char(m[find[0]][find[3]]);
        dec_ans += char(m[find[2]][find[1]]);
        dec_ans += ' ';
    }
}
void decrypt(string ans)
{
    int p,q;
    for(int i=0;i<ans.length()-1;i+=3)
    {
        p = ans[i];
        q = ans[i+1];
        decription(p,q);
    }
}
int main()
{
    string s,key;
    cout<<"enter the plain text : ";
    getline(cin,s);
    cout<<"enter the key : ";
    cin>>key;
    matrix(s,key);
    string dup = duplicate(s);
    string dup2 = convert(dup);
    cout<<"\nPaired-up plain text : " <<dup2<<"\n";
    encrypt(dup2);
    cout<<"\nFinal Encrypted text : "<<ans<<"\n";
    decrypt(ans);
    cout<<"\nFinal Decrypted text : "<<dec_ans<<"\n";
}
