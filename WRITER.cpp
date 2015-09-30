#include <iostream>
#include <string.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int m,n,i,last,p;
	char word[10000],lele;
	string jlt;
	cin>>m>>n;
	last=m;
	for(i=0;i<m;i++)
	{
		cin>>word[i];
	}
	while(n--)
	{
	cin>>lele;
	if(lele=='T')
	{

		cin>>jlt;
		last+=jlt.size();
	}
	else if(lele=='C')
	{
		cout<<last<<"\n";
	}
	else if(lele=='W')
	{
	cin>>p;
	last-=p;
	}
	}
	return 0;
}
