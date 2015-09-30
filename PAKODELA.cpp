#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,l,r,sum;
    long pro;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        sum=1;
        pro=1;
        if(r-l>=10) {cout<<"0\n";}
        else{
            for(int i=l;i<=r;i++)
            {
                pro*=i;
            }
            while(pro>0)
            {
                sum*=pro%10;
                pro/=10;
            }
            cout<<sum<<"\n";
        }
    }
}
