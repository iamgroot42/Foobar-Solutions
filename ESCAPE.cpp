#include<bits/stdc++.h>

using namespace std;

int aloo2(int x,int y)
{
    if(x>y) return y;
    else return x;
}

int aloo(int a,int b,int c)
{
    int m=a;
    if(m>b) m=b;
    if(m>c) m=c;
    return m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t,m,i,j,temp;
    cin>>t;
    while(t--)
    {
        cin>>m;
        int a[m][m],b[m][m];
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++) cin>>a[i][j];
        }
        for(i=0;i<m;i++) b[m-1][i]=a[m-1][i]; // Duh -_-
        //Bottom-up approach

        i=m-1;
        while(i--)
        {
            for(j=1;j<m-1;j++)
            {
                b[i][j]=aloo(b[i+1][j],b[i+1][j-1],b[i+1][j+1])+a[i][j];
            }
            b[i][0]=aloo2(b[i+1][0],b[i+1][1])+a[i][0];
            b[i][m-1]=aloo2(b[i+1][m-1],b[i+1][m-2])+a[i][m-1];
        }

        temp=b[0][0];
        for(i=0;i<m;i++)
        {
            if(b[0][i]<temp) temp=b[0][i];
        }
        cout<<temp<<"\n";
    }
    return 0;
}
