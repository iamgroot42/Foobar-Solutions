#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int t;
    double n,m,k;
    long long x;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        if(n<=m)
        {
            cout<<"1\n";
        }
        else if(m<n && m<k)
        {
            cout<<"-1\n";
        }
        else if(m>k && m<n){
                x=ceil((n-m)/(m-k));
                x++;
            cout<<x<<"\n";
        }
        else{
            cout<<"-1\n";
        }
    }
    return 0;
}
