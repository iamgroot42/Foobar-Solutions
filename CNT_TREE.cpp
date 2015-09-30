#include<bits/stdc++.h>

//Read Cormen Yesterday :D

using namespace std;

#define mod 1000000007

long long modex(long long a,long long b)
{
	if(b==0) return 1;
	if(b==1) return a%mod;
	long long temp=modex(a,b/2);
	if(b%2==0)
	{
		return ((temp%mod)*(temp%mod))%mod;
	}
	else
	{
		return ((((temp%mod)*(temp%mod))%mod)*(a%mod))%mod;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	int t,i,n;
	cin>>t;
	long long ans,temp,temp2,temp3;
	while(t--)
	{
		ans=temp=temp2=1;
		cin>>n;
		for(i=1;i<=2*n;i++)
		{
			temp=((temp%mod)*(i%mod))%mod;
		}
		// cout<<temp<<":\n";
		for(i=1;i<=n+1;i++)
		{
			temp2=((temp2%mod)*(i%mod))%mod;
		}
		// cout<<temp2<<":\n";
		temp3=modex(temp2,mod-2)%mod;
		ans=((temp%mod)*(temp3%mod))%mod;
		cout<<ans<<"\n";
	}
	return 0;
}