#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007

vector<bool> a(1300000);
vector<long long> b(100000);

long long temp;

long long modex(long long a,long long b)
{
    if(b==0) return 1;
    if(b==1) return a%mod;
    if(b%2)
    {
        temp=modex(a,b/2)%mod; return((temp%mod * temp%mod + mod)%mod * a%mod + mod)%mod;
    }
    else
    {
        temp=modex(a,b/2)%mod; return((temp%mod * temp%mod+mod)%mod + mod)%mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int i,j,k,t;
    long long n,pro;
    fill(a.begin(),a.end(),true);
    fill(b.begin(),b.end(),0);
    a[0]=a[1]=0;
    k=0;
    for(i=2;i<1300000;i++)
    {
        if(a[i]) b[k++]=i;
        for(j=2*i;j<1300000;j+=i) a[j]=0;
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        n=b[n-1]%mod;
        pro=modex(n,n)%mod;
        cout<<pro<<"\n";
    }
    a.clear();
    b.clear();
    return 0;
}
