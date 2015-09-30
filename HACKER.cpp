#include<iostream>
#include<vector>

using namespace std;
typedef unsigned long ul;
int main()
{
    int t;
    cin>>t;
    ul m,n,i,temp,junk,c,l;
    while(t--)
    {
        cin>>n>>m;
        c=0;
        vector<ul> a(n);
        for(i=0;i<n;i++)
        {
            a[i]=0;
        }
        for(i=0;i<m;i++)
        {
            cin>>junk>>temp;
            a[temp-1]=1;
        }
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                c++;
                l=i;
            }
        }
        if(c==1)
        {
            cout<<l+1<<"\n";
        }
        else{
            cout<<"-1\n";
        }

    }
    return 0;

}
