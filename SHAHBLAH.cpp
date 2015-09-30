#include<bits/stdc++.h>

using namespace std;

long aloo(long a,long b)
{
    if(a>b) return a;
    else return b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,x,y,z,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>y>>z;
        long a[n+1];
        for(i=1;i<=n;i++) a[i]=-LONG_MAX;
        a[0]=0;
        for(i=1;i<=n;i++)
        {
            if(i>=x) a[i]=aloo(a[i],a[i-x]+1);
            if(i>=y) a[i]=aloo(a[i],a[i-y]+1);
            if(i>=z) a[i]=aloo(a[i],a[i-z]+1);
        }
        cout<<a[n]<<"\n";
    }
    return 0;
}
