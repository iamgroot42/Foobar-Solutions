#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007

ll modular_pow(ll base, ll exponent,ll mod)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result*base)%mod;
        exponent = exponent >> 1;
        base = (base*base)%mod;
    }
    return result;
}

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(0);
    ll a,b,ans,left,x;
    cin>>a>>b;
    ans=a;
    left=0;
    x=a;
    // 6,3
    //1 1
    //8,0,6
    while(x>=b)
    {
        ans+=x/b;
        left=x%b;
        x=(x/b)+left;
    }
    cout<<ans<<"\n";
    return 0;
}