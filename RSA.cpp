#include<bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
    bool flag = true;
    for(int i=2;i<=n/2;i++)
    {
        if(n%i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
long long int rsa(int m, int e, int n)
{
    int c = 1;
    int count = 0;
    while(count < e)
    {
        c = ((c % n) * (m % n)) % n;
        count++;
    }
    return c;
}
int main()
{
    int p, q, m;
    cout<<"enter prime numbers p and q!"<<endl;
    do
    {
        cout<<"enter p : ";
        cin>>p;
    }while(!isprime(p));
    do
    {
        cout<<"enter q : ";
        cin>>q;
    }while(!isprime(q));
    cout<<"enter the message : ";
    cin >> m;
    int n = p * q;
    cout<<"\nn = "<<n<<"\n";
    int phi = (p-1)*(q-1);
    cout<<"phi(n) = "<<phi<<"\n";
    long long int e,d = 1;
    for(int i=2;i<phi;i++)
    {
        if(__gcd(i,phi) == 1)
        {
            e = i;
            break;
        }
    }
    cout<<"e = "<<e<<"\n";
    while(1)
    {
        if((d * e) % phi == 1)
            break;
        d++;
    }
    cout<<"d = "<<d<<"\n";
    long long int cipher, decipher;
    cipher = rsa(m,e,n);
    cout<<"public key : { "<<e<<", "<<n<<" }\n";
    cout<<"private key : { "<<d<<", "<<n<<" }\n";
    cout<<"\nEncrypted message : "<<cipher<<"\n";
    decipher = rsa(cipher,d,n);
    cout<<"\nDecrypted message : "<<decipher<<"\n";
}
