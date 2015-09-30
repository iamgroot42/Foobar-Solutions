#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,done;
    long n,x,i,median,sum,comp;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        sum=0;
        done=0;
        vector<long> a(n);
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.begin()+n);
        median=a[n/2];
        comp=a[0]%x;
        for(i=0;i<n;i++)
        {
            if(a[i]%x!=comp)
            {
                cout<<"IMPOSSIBLE\n";
                done=1;
                break;
                    }
                    sum+=abs(a[i]-median);
                    sum;

        }
        if(!done)
        {
            cout<<"POSSIBLE "<<sum/x<<"\n";
        }



    }
}
