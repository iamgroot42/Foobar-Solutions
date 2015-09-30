#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,psize,i,j,c=0,done;
    char a[100];
    string parent;
    cin>>parent;
    cin>>t;
    psize=parent.size();
    while(t--)
    {
        cin>>n;
        done=0;
        c=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<psize;i++)
        {
            if(parent[i]==a[0])
            {
                for(j=0;j<n;j++)
                {
                    if(parent[i+j]!=a[j]) {done=1; break;}
                    done=2;
                }
            }
            if(done==2) {c++;done=0;i+=(n-1);}
        }



            cout<<c<<"\n";

    }
    return 0;
}
