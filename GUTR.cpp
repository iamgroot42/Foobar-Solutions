#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int f,s,t;
	cin>>t;
	while(t--)
	{
		cin>>f>>s;
		switch(f)
		{
		case 1:	f=5; break;
		case 2: f=2; break;
		case 3: f=0; break;
		case 4: f=4; break;
		case 5: f=1; break;
		case 6: f=5; break;
		}
		switch((f+s)%7)
		{
			case 0: cout<<"G\n"; break;
			case 1: cout<<"A\n"; break;
			case 2: cout<<"B\n"; break;
			case 3: cout<<"C\n"; break;
			case 4: cout<<"D\n"; break;
			case 5: cout<<"E\n"; break;
			case 6: cout<<"F\n"; break;
		}
	}
	return 0;
}
