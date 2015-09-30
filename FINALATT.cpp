#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool a[n][n];
        int b[n][n];
        for(i=0;i<n;i++) for(j=0;j<n;j++) cin>>a[i][j];
        for(i=0;i<n;i++) for(j=0;j<n;j++) b[i][j]=2*n+1; //2n+1,as the longest route from b[0][0] to b[n-1][n-1] can be of size 2n
        b[n-1][n-1]=0;
        for(j=n-2;j>0;j--)
        {
            if(a[n-1][j]) b[n-1][j]=b[n-1][j+1]+1;
            else a[n-1][j-1]=0;
        }
        if(a[n-1][0]) b[n-1][0]=b[n-1][1]+1;
        for(i=n-2;i>0;i--)
        {
            if(a[i][n-1]) b[i][n-1]=b[i+1][n-1]+1;
            for(j=n-2;j>=0;j--)
            {
                if(b[i+1][j+1]==(2*n+1) && b[i][j+1]==(2*n+1) && b[i+1][j]==2*n+1) b[i][j]=2*n+1;
                else if(a[i][j]) b[i][j]=min(b[i+1][j+1],min(b[i][j+1],b[i+1][j]))+1;
            }
        }
        if(a[0][n-1]) b[0][n-1]=b[1][n-1]+1;
        for(j=n-2;j>0;j--)
        {
            if(b[1][j+1]==(2*n+1) && b[0][j+1]==(2*n+1) && b[1][j]==2*n+1) b[0][j]=2*n+1;
            else if(a[0][j]) b[0][j]=min(b[1][j+1],min(b[0][j+1],b[1][j]))+1;
        }
        b[0][0]=min(b[1][j+1],min(b[0][j+1],b[1][j]))+1;
        if(b[0][0]<=2*n)cout<<b[0][0]<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}
