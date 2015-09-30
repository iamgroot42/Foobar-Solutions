#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define mod 1000000007

ll modmul(ll a,ll b){if(b==0) return 0;ll temp;temp=modmul(a,b/2);if(b%2==0){return (temp+temp)%mod;}else{return (((temp+temp)%mod)+a)%mod;}}
ll modex(ll a,ll b){if(b==0) return 1;ll temp;temp=modex(a,b/2);if(b%2==0){return (temp*temp)%mod;}else{return (((temp*temp)%mod)*a)%mod;}}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lg10(ll x){ll i=0;while(x>=10){x/=10;i++;}return i;}

int main()
{
	ios_base::sync_with_stdio(0);
	ll m,M;
	bool flag;
	cin>>m>>M;
	flag=true;
	while(M>0)
	{
		if(!(M%m==0 || M%m==1 || M%m==(m-1))) flag=false;
		M/=m;
	}
	if(flag) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}



// +=1 +=m +=m2 +=m3 +=m4 +=m5 +=m100....=M