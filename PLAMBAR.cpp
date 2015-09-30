#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        i=2;
        while(i*i<n)
        {
            if(n%i==0) n/=i;
            else i++;
        }
        cout<<n<<"\n";
    }
    return 0;
}
