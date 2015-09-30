#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,i,q,m,c;
    cin>>n>>k;
    bool a[n];
    for(i=0;i<n;i++) {cin>>a[i];}
    cin>>q;
    while(q--)
    {
        cin>>m;
        c=0;


        for(i=0;i<m;i++)
        {
            if(!a[i]) {c=-1; break;}
            else{c++;}
        }
        if(c>k+1 || c==-1) {cout<<"NO\n";}
        else {cout<<"YES\n";}

    }
return 0;

}
