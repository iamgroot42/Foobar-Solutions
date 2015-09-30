#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007

int main()
{
	ios_base::sync_with_stdio(0);
	int t,i,la,lb;
	long long temp1,temp2,ans;
	string a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		la=a.size();
		lb=b.size();
		temp1=a[0]-'0';
		for(i=1;i<la;i++)
		{
			temp1=(((temp1*10)%mod)+(a[i]-'0')%mod)%mod;
			temp1=temp1%mod;
		}
		temp2=b[0]-'0';
		for(i=1;i<lb;i++)
		{
			temp2=(((temp2*10)%mod)+(b[i]-'0')%mod)%mod;
			temp2=temp2%mod;
		}
		ans=((temp1%mod)*(temp2%mod))%mod;
		cout<<ans<<"\n";
	}
	return 0;
}