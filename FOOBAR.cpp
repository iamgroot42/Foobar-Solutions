#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int i,t,c,d,f[5],m;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        f[0]=f[1]=f[2]=f[3]=f[4]=0;
        d=s.size();
        for(i=0;i<d;i++)
        {
            if(s[i]=='f'){f[0]++;}
            else if(s[i]=='o'){f[1]++;}
            else if(s[i]=='b'){f[2]++;}
            else if(s[i]=='a'){f[3]++;}
            else if(s[i]=='r'){f[4]++;}
        }
        f[1]/=2;
        m=f[0];
        for(i=0;i<5;i++)
        {
            if(m>f[i]){m=f[i];}
        }
        cout<<m<<"\n";

    }
    return 0;
}
