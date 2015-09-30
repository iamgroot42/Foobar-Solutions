#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,i,ans,yolo;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=1;
        for(i=0;i<n;i++)
        {
            cin>>yolo;
            if(yolo>ans) ans=yolo;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
