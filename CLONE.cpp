#include <iostream>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	int N,t,a[101],i,j;
	cin>>N;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<t;i++)
	{
		if(N-a[i]<=0)
		{
			cout<<-1<<"\n";
			continue;
		}
		for(j=0;j<N-a[i];j++)
		{
			cout<<a[i]<<"\n";
		}
	}
	return 0;
}
