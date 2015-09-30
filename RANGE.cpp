#include<bits/stdc++.h>

using namespace std;

#define mid(a,b) ((a)+((b-a)/2))
#define maxx 1000000001

//Coding segtree for the first time,code referred from http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/

int* segt;
int *a;

int getmin(int s,int e,int qs,int qe,int b) //a is segtree array,s is starting index,e is ending index ,qs and qe are query indices ,b is the current index
{
    int m;
    if(s>=qs && qe>=e)
        return segt[b];
    if(s>qe || qs>e)
        return maxx;
    m=mid(s,e);
    return min(getmin(s,m,qs,qe,2*b+1),getmin(m+1,e,qs,qe,2*b+2));
}

void update(int s,int e,int t,int upd,int b) //a,s,e are same,t is the index to be updated,upd is the difference to be added,b is the current index;
{
    int m;
    m=mid(s,e);
    if(t<s || t>e)
        return;
    if(s!=e)
    {
        update(s,m,t,upd,2*b+1);
        update(m+1,e,t,upd,2*b+2);
        segt[b]=min(segt[2*b+1],segt[2*b+2]);
    }
    if(s==e) segt[b]=upd;
}

int construct(int s,int e,int b)
{
    if(s==e)
    {
        segt[b]=a[s];
        return segt[b];
    }
    int m;
    m=mid(s,e);
    segt[b]=min(construct(s,m,2*b+1),construct(m+1,e,2*b+2));
    return segt[b];
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n,q,i,x,y,z;
    cin>>n>>q;
    segt=(int*)malloc(sizeof(int)*4*n);
    a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<4*n;i++) segt[i]=0;
    construct(0,n-1,0);
    cout<<"\n";
    while(q--)
    {
        cin>>x>>y>>z;
        if(x==1)
        {
            cout<<getmin(0,n-1,y-1,z-1,0)<<"\n";
        }
        else
        {
            update(0,n-1,y-1,z,0);
        }
    }
    return 0;
}
