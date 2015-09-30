#include<iostream>
#include<string.h>
#include<string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,m,sum;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>n>>m;
        cin>>a;
        while(m--)
        {
            cin>>b;
            sum=0;

            for(size_t i=a.find(b) ; i!=string::npos ; i=a.find(b,i+b.length())  ) { sum+=(i+1); }
            // string::npos!=i check whether i contains a legit position or not,i.e. if the string was found or not
            //THe rest is quite obvious
             if(sum==0) {cout<<"-1\n";}
        else
        {cout<<sum<<"\n";}
        }

    }


        return 0;


    }

