#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,nc[10],mc[10],nlen,mlen,i,j;
    string n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        nlen=n.size();
        mlen=m.size();
        for(i=0;i<10;i++) {mc[i]=nc[i]=0;}
        for(i=0;i<nlen;i++)
        {
            nc[int(n[i]-48)]++;
        }
        for(i=0;i<mlen;i++)
        {
            mc[int(m[i]-48)]++;
        }


        for(i=9;i>0;i--)
        {
          j=nc[i]>mc[i]?mc[i]:nc[i];
          while(j--) { cout<<i;}
        }
        cout<<"\n";

    }
    return 0;
}

