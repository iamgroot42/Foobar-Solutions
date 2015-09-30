#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int x,a1,a2,flag,i;
	cin>>x>>a1>>a2;
	flag=0;
	for(i=a1;i<=a2;i++)
	{
		if(i>x)
		{
			flag=1;
			break;
		}
	}
	if(flag) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}