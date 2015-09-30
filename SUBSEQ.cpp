#include<bits/stdc++.h>

using namespace std;

//Coding LIS first time ; wrote code on my own after reading from http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/

int main()
{
    ios_base::sync_with_stdio(0);
    int t,i,l,j,ans;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        l=s.size();
        int a[l];
        for(i=0;i<l;i++)a[i]=1;
        for(i=1;i<l;i++)
        {
            for(j=0;j<i;j++)
            {
                if(s[i]>=s[j] && a[i]<a[j]+1)
                    a[i]=a[j]+1;
            }
        }
        ans=0;
        for(i=0;i<l;i++) if(a[i]>ans) ans=a[i];
		cout<<ans<<endl;
    }
    return 0;
}
