#include<iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long t,n,m,k;
    long long mod=1000000007;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        if(n+1<k || m+1<k)
        {
            cout<<"0\n";
            continue;
        }
        cout<<(((n+1-k)%mod)*((m+1-k)%mod))%mod<<"\n";
    }
    return 0;
}
