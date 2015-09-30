#include <iostream>
using namespace std;

long expo(long a,long n,long p)
{
    long result=1;
    while(n)
    {
        if(n%2!=0) result=((a%p)*(result%p));
        n/=2;
        a=( (a%p) * (a%p) )%p;
    }
    return result;

}

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	long n,i,pro,ans,p;
	cin>>t;
	while(t--)
	{
		cin>>n>>p;
		pro=1;
		if(n>=p) {cout<<"0\n";}
		else
        {
            for(i=n+1;i<p;i++) {pro=((pro%p) * (i%p) )%p; }
            ans=(expo(pro,p-2,p)%p * (p-1) )%p;
            cout<<ans<<"\n";
        }
	}
	return 0;
}
