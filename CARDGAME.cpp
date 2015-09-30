#include<iostream>
#include<math.h>

using namespace std;
//Raach has bee submitted,this the the code for Cardgame
int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long long n,m,x,y,mod=1000000007;
    unsigned long t,q;
    double k;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cin>>q;
        while(q--)
        {
            cin>>k;
            x=ceil(n/k);
            y=ceil(m/k);

            cout<<((x%mod)*(y%mod))%mod<<"\n";

        }
    }
    return 0;
}
