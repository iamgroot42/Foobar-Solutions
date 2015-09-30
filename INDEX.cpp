#include<bits/stdc++.h>

using namespace std;

#define mid(a,b) ((a)+((b-a)/2))

struct segtree
{
    int n,index;
};

segtree* segt;
int *a;

int zeroes(int x)
{
    int i=0;
    if(!x) return 1;
    while(x)
    {
        if(x%10==0) i++;
        x/=10;
    }
    return i;
}

int getmin(int s,int e,int k,int b) //a is segtree array,s is starting index,e is ending index ,qs and qe are query indices ,b is the current index
{
    int m;
    if(k>segt[b].n) return -1; //If number of zeroes exceed total zeroes
    if(segt[b].index!=-1) //If last level is reached
    return segt[b].index;
    m=mid(s,e);
    if(k<=segt[2*b+1].n)
    {
        return getmin(s,m,k,2*b+1);
    }
    else
    {
        return getmin(m+1,e,k-segt[2*b+1].n,2*b+2);
    }
}

void update(int s,int e,int t,int upd,int b) //a,s,e are same,t is the index to be updated,upd is the new value,b is the current index
{
    int m;
    m=mid(s,e);
    if(t<s || t>e)
        return;
    if(s!=e)
    {
        update(s,m,t,upd,2*b+1);
        update(m+1,e,t,upd,2*b+2);
        segt[b].n=segt[2*b+1].n+segt[2*b+2].n;
    }
    if(s==e) segt[b].n=upd;
}

int construct(int s,int e,int b)
{
    if(s==e)
    {
        segt[b].n=a[s];
        segt[b].index=s;
        return segt[b].n;
    }
    int m;
    m=mid(s,e);
    segt[b].n=construct(s,m,2*b+1)+construct(m+1,e,2*b+2);
    segt[b].index=-1; //Every level except the last has corresponding index '-1' 
    return segt[b].n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n,q,i,x,y,z;
    cin>>n;
    segt=(segtree*)malloc(sizeof(segtree)*4*n);
    a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]=zeroes(a[i]);
    }
    construct(0,n-1,0);
    cin>>q;
    while(q--)
    {
        cin>>x;
        if(x==1)
        {
            cin>>y;
            cout<<getmin(0,n-1,y,0)<<"\n";
        }
        else
        {
            cin>>y>>z;
            a[y]=zeroes(z);
            update(0,n-1,y,a[y],0);
        }
    }
    return 0;    
}
