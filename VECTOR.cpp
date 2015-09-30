#include<bits/stdc++.h>

using namespace std;

int prime(int n)
{
    for(int i=2;i<=(n/2);i++)
    {
        if(n%i==0) {return 0;}
    }
    if(n==1 || n==0) {return 0;}
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,sx,sy,sz,t1,t2,t3;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sx=sy=sz=0;
        for(int i=0;i<n;i++)
        {
            cin>>t1>>t2>>t3;
            sx+=t1;
            sy+=t2;
            sz+=t3;
        }
        if(prime(sx) && prime(sy) && prime(sz)) {cout<<"YES\n";}
        else {cout<<"NO\n";}

    }
}
