#include<iostream>
#include<math.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    int t;
    unsigned long long a,b,c,d,p,q;
    cin>>t;
    while(t--)
    {
     cin>>a>>b>>c>>d;
     p=b*log2(a);
     q=d*log2(c);

     if (p>q)
     {
       cout<<"Alien\n";
     }
     else
     {
         cout<<"Warrior\n";
     }


    }
    return 0;
}
