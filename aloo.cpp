#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ll i,k,n;
	ll minn,ans;
	cin>>n>>k;
	ll a[n];
	for(i=0;i<n;i++) cin>>a[i];
	ll csum[n+1];
	csum[0]=0;
	for(i=1;i<n+1;i++) csum[i]=csum[i-1]+a[i-1];
	minn=csum[0];
	ans=csum[k];
	for(i=k;i<n+1;i++)
	{
		minn=min(minn,csum[i-k]);
		ans=max(ans,csum[i]-minn);
	}
	cout<<ans<<endl;
	return 0;
}