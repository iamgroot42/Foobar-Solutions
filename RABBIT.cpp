#include<iostream>

#define mod 1000000007

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,i;
    unsigned long long a,b,temp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a=b=1;
        n--;
        for(i=0;i<n;i++)
        {
            a%=mod;
            b%=mod;
            temp=(a+b)%mod;
            a=b;
            b=temp;
            a%=mod;
            b%=mod;

        }
        cout<<a%mod<<"\n";
    }
}
