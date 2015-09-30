#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007

int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

bool ps(int a)
{
	if(a==1) return 0;
	if(int(sqrt(a))==sqrt(a)) return 1;
	return 0;
}

bool rev(int a,int b)
{
	return a>b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int t,i,n,k;
	long long ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		k=0;
		ans=1;
		priority_queue<int> b;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			b.push(a[i]);
		}
		for(i=0;i<n;i++)
		{
			if(ps(gcd(i+1,a[i]))) k++;
		}
		for(i=0;i<k;i++)
		{
			ans=((ans%mod)*((b.top())%mod))%mod;
			b.pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}