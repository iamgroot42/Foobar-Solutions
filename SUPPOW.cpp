#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007

long long expo(long a,long n)
{
    long ans=1;
    while(n)
    {
        if(n%2!=0) ans=( (ans%mod) * (a%mod) )%mod;
        n/=2;
        a=( (a%mod) * (a%mod) );
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,i,k;
    long long bin;
    cin>>t;
    while(t--)
    {
        cin>>n;
        k=2;
        bin=0;
        for(i=2;i<=n/2;i++)
        {
            if(n%i==0) k++;
        }
        if(n==1) k=1;
        i=0;
        while(k)
        {
            bin+=pow(10,i)*(k&1);
            //cout<<"pow(10,i) is "<<pow(10,i)<<"\n";
            //cout<<"k&1 is "<<(k&1)<<"\n";
            k=k>>1;
            i++;
        }
        //cout<<"bin in decimal form is "<<bin<<"\n";
        cout<<fixed<<expo(2,bin*2)<<"\n";
    }
    return 0;
}

