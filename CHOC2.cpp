#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	unsigned long long a[100],k,s;
	int t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		s=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			s=s%(1000000009)+(a[i]%k)%(1000000009);
		}
		cout<<s%1000000009<<"\n";
	}
	return 0;
}

