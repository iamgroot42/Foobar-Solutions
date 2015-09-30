#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t,i,j;
	vector<int> a(1000001,1);
	a[0]=a[1]=0;
	for(i=2;i<=sqrt(1000001);i++)
	{
		if(a[i])
		{
			for(j=2*i;j<1000001;j+=i) a[j]=0;
		}
	}
	cin>>t;
	long long x,temp;
	while(t--)
	{
		cin>>x;
		temp=sqrt(x);
		if( (temp*temp==x) && (a[sqrt(x)]))
		{
			cout<<"YES\n";
		}
		else cout<<"NO\n";
	}
	return 0;	
}