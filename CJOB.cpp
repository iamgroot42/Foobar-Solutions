#include<bits/stdc++.h>

using namespace std;

struct aloo
{
	int d,c;
	int k;
};

bool potato(aloo p,aloo q)
{
	return p.c*q.d > p.d*q.c;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		aloo a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i].d>>a[i].c;
			a[i].k=i+1;
		}
		stable_sort(a,a+n,potato);
		for(i=0;i<n;i++)
		{
			cout<<a[i].k<<" ";
		}
		cout<<"\n";
	}
	return 0;
}