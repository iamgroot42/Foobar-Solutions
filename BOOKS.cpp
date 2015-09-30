#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll modex(ll a,ll b)
{
	if(b==0) return 1;
	ll temp=modex(a,b/2);
	if(b%2)
	{
		return (((temp*temp))*a);
	}
	else
	{
		return (temp*temp);
	}
}

ll lg10(ll x){ll i=0;while(x>=10){x/=10;i++;}return i;}

int main()
{
	ios_base::sync_with_stdio(0);
	ll n,temp,ans,i;
	cin>>n;
	i=1;
	ans=0;
	temp=1;
	while(temp*10<=n)
	{
		ans+=temp*9*i;
		i++;
		temp*=10;
	}
	ans+=(n+1-temp)*(i);
	// if(n<10) ans=n;
	cout<<ans<<"\n";

}