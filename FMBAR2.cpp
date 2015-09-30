#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007

int main()
{
	ios_base::sync_with_stdio(0);
	int n,m,q,i,t;
	long long ans,temp1,temp2;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>q;
		vector<int> a(q+2),b(q+2);
		for(i=0;i<q;i++)
		{
			cin>>a[i]>>b[i];
		}
		a[q]=b[q]=0;
		a[q+1]=n+1;
		b[q+1]=m+1;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		temp1=0;
		temp2=0;
		for(i=1;i<q+2;i++)
		{
			if((a[i]-(a[i-1]+1))>temp1) temp1=a[i]-(a[i-1]+1);
		}
		for(i=1;i<q+2;i++)
		{
			if((b[i]-(b[i-1]+1))>temp2) temp2=b[i]-(b[i-1]+1);
		}
		ans=temp1*temp2;
		cout<<ans<<"\n";
	}
	return 0;	
}