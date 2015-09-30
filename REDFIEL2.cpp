#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll modular_mul(ll a, ll b,ll mod)
{
    ll result = 0;
    while (b > 0)
    {
        if (b % 2 == 1)
            result = (result + a) % mod;
        b = b >> 1;
        a = (a + a) % mod;
    }
    return result;
}

ll modular_pow(ll base, ll exponent,ll mod)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = modular_mul(result,base,mod);
        exponent = exponent >> 1;
        base = modular_mul(base,base,mod);
    }
    return result;
}

ll modular_pow(ll base, ll exponent)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = result*base;
        exponent = exponent >> 1;
        base = base*base;
    }
    return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	ll n,k,c,m,i,sum,temp,temp2,temp3,sum2;
	cin>>n>>k>>c>>m;
	ll p[n],alpha[n];
	sum=1;
	for(i=0;i<n;i++)
	{
		cin>>p[i]>>alpha[i];
		sum=((sum%m)*((alpha[i]%m)+1))%m;
	}
	sum=((sum%m)*(c%m))%m;
	sum2=1;
	//(a%bm)/(b)=reqd
	for(i=0;i<n;i++)
	{
		temp=(modular_pow(p[i],k)-1); //Denominator
        // cout<<temp<<"\n";
        temp2=(modular_pow(p[i],alpha[i]*k+k,m*temp)-1); //Numerator
        // cout<<temp2<<"\n";
        temp3=(temp2/temp);
        // cout<<temp2/temp<<" balle\n";
        // cout<<temp3<<"\n";
        sum2=((sum2%m)*(temp3%m));
	}
	sum=((sum%m)+(sum2%m))%m;
	cout<<sum<<"\n";
	return 0;	
}