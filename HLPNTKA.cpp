#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(0);
	int i,j,t,n;
	int a[1000001];
	for(i=0;i<1000001;i++) a[i]=2;
	a[0]=a[1]=1;
	for(i=2;i<1000001;i++)
	{
		for(j=2*i;j<1000001;j+=i)
		{
			a[j]++;
		}
	}
	for(i=2;i<1000001;i++) a[i]=(a[i]%mod+a[i-1]%mod)%mod;
	cin>>t;
	while(t--)
    {
        cin>>n;
        cout<<a[n]%mod<<"\n";
    }
	return 0;
}
