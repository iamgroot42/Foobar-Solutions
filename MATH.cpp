#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t,n,i,d;
	cin>>t;
	while(t--)
	{
		cin>>n>>d;
		for(i=0;i<n-2;i++) cout<<"1 ";
		cout<<"2 ";
		cout<<n+d<<"\n";
	}
	return 0;	
}