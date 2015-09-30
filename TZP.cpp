#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<"8\n";
        }
        else
        {
            cout<<8*(n) + 6*(n-1)<<"\n";
        }
    }
    return 0;
}
