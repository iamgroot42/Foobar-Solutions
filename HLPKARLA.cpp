#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    long n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(long(sqrt(n))==sqrt(n))
        {
            cout<<"1\n";
        }
        else
        {
            cout<<"0\n";
        }

    }
    return 0;
}
