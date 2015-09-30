#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,ans;
    long n,k;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>k;
        if(long(sqrt(k))==sqrt(k)) {ans=1;}
        if(n%2==0)
        {
            if(ans) cout<<"on\n";
            else cout<<"off\n";
        }
        else
        {
            if(ans) cout<<"off\n";
            else cout<<"on\n";
        }

    }
    return 0;
}
