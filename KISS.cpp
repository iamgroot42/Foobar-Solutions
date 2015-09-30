#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007

long long expo(long long a,long long b)
{
    long result=1;
    while(b)
    {
        if(b%2!=0) result=( (result%mod) * (a%mod) )%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,n,r,i,temp;
    long long perm[500001],inperm[500001];
    perm[0]=1;
    inperm[0]=1;
    for(i=1;i<500001;i++)
    {
        perm[i]=( (perm[i-1])%mod * i)%mod;
        inperm[i]=expo(perm[i],mod-2);
    }
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
        for(i=0;i<n;i++) {cin>>temp; r-=temp;}
        if(r<=0)
        {
            cout<<"0\n";
            continue;
        }
        //cout<<perm(r+n-1,n-1)<<"
        cout<<( ( perm[r+n-1]%mod )* ( ( (inperm[n-1]%mod) * (inperm[r]%mod) )%mod) )%mod<<"\n";
    }
    return 0;
}
