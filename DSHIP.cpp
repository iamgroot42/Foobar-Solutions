#include<iostream>
#include<string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int i,t,j,la,lb,m,A[26],B[26],done;
    string a,b;
    cin>>t;
    while(t--)
    {
        cin>>a;
        cin>>b;
        la=a.size();
        lb=b.size();
        for(i=0;i<26;i++)
        {
            A[i]=B[i]=0;
        }
        for(i=0;i<la;i++)
        {
            A[a[i]-97]++;
        }
        for(i=0;i<lb;i++)
        {
            B[b[i]-97]++;
        }
        done=1;
        for(i=0;i<26;i++)
        {
            if(A[i]!=B[i]) {done=0; break;}
        }
        if(done==1)
        {
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }


    }
    return 0;
}
