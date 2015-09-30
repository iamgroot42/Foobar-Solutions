#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t,n,i;
	double temp,ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		for(i=0;i<n;i++)
		{
			cin>>temp;
			ans+=temp;
		}
		ans/=2;
		cout<<setprecision(2)<<fixed<<ans<<"\n";
	}
	return 0;	
}