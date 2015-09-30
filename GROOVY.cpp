#include<iostream>

using namespace std;

// Problem is based on Langford Sequence

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%4==0 || n%4==3)
        {
            cout<<"YOLO\n";
        }
        else{
            cout<<"NADA\n";
        }
    }
    return 0;
}
