#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int l,b,h,t,a;
	long long ans;
	cin>>t;
	while(t--)
	{
		cin>>l>>b>>h>>a;
		ans=(l/a)*(b/a)*(h/a);
		cout<<ans<<"\n";
	}
	return 0;
}