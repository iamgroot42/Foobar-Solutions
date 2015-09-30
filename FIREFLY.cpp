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
	ll n,h,i,x,ans,y;
	cin>>n>>h;
	ll a[h+1];
	for(i=0;i<h+1;i++) a[i]=0;
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(i%2==0)
		{
			a[h-x]-=1;
		}
		else
		{
			a[x]+=1;
		}
	}
	a[0]=-n/2;
	for(i=1;i<=h;i++)
	{
		a[i]+=a[i-1];
	}
	for(i=1;i<=h;i++) a[i]=abs(a[i]);
	ans=0;
	y=*min_element(a+1,a+h+1);
	for(i=1;i<=h;i++)
	{
		if(a[i]==y)
		{
			ans++;
		}
	}
	cout<<y<<" "<<ans<<"\n";
	return 0;
}