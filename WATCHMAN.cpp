#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long i,n,t,j;
    unsigned long long s,to;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<unsigned long> a(n);
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        to=100000000;
        for(i=0;i<n;i++)
        {
            s=0;
            for(j=0;j<n;j++)
            {
                s+=labs(a[i]-a[j]);
            }
            if(s<to){to=s;}
        }
    cout<<to<<"\n";
    }
    return 0;
}
