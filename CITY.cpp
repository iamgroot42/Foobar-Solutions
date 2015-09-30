#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long t,l,i;
    long long house;
    int done;
    cin>>t;
    while(t--)
    {
        cin>>l;
        house=1;
        done=0;
        vector<unsigned long> a(l);
        for(i=0;i<l;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<l;i++)
        {

           house=(house-a[i])*2;

        }

        if(house==0)
        {
            cout<<"Yo\n";
        }
        else{
            cout<<"Nope\n";
        }

    }
}
