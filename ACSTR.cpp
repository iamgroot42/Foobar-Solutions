#include<iostream>
#include<string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string a,b;
    int c[26],d[26],t,i,j;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        for(i=0;i<26;i++) {c[i]=0;d[i]=0;}
        for(i=0;i<a.length();i++) {c[a[i]-'a']++; d[b[i]-'a']++;}
        for(i=0;i<26;i++)
        {
            for(j=0;j<min(c[i],d[i]);j++) cout<<char(i+'a');
        }
        cout<<endl;
    }
    return 0;
}
