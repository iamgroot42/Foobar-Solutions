#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=0;
        }

        for(i=n-1;i>=0;i--)
        {
            for(j=0;j<n;j++)
            {
                if(a[i]==0 && b[j]==0)
                {
                    b[j]=i+1;


                    break;
                }
                if(b[j]==0)
                {
                    a[i]--;

                }
            }
        }

       for(i=0;i<n;i++)
        {
            cout<<b[i]<<" ";
        }
        cout<<"\n";
    }
}
