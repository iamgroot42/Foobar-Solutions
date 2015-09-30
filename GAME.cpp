#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t,i,l,a[26],flag;
	string s;
	char temp;
	cin>>t;
	while(t--)
	{
		cin>>s;
		flag=0;
		l=s.size();
		for(i=0;i<26;i++) a[i]=0;
		for(i=0;i<l;i++) a[s[i]-'a']++;
		for(i=0;i<26;i++)
		{
			if(a[i]>l/2) { temp=i+'a'; flag=1; break;}
		}
		if(flag) cout<<temp<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}