#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,i;
    long long sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        for(i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                sum+=i;
                if(n/i!=i)
                {
                    sum+=n/i;
                }
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}
