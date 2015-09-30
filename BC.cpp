#include<iostream>

using namespace std;

int main()
{
    int t,ans;
    long long n;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        while(n)
        {
            if(n&1==1) ans++;
            n/=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
