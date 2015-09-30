#include <iostream>
using namespace std;

int main() {
	int t,i,n,sum,temp;
    cin>>t;
	while (t>0)
	{
		sum=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
		cin>>temp;
		sum+=temp/3;
		}
    cout<<sum<<"\n";
	t-=1;
	}
	return 0;
}
