#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    double pro=1;
	bool a[50];
	double b[20],n;
	int i,j,c,t;
	cin>>t;
	c=0;
	for(i=0;i<50;i++) a[i]=1;
	a[0]=a[1]=0;
	for(i=2;i<50;i++)
	{
		for(j=2*i;j<50;j+=i)
		{
			a[j]=0;
		}
	}
	for(i=2;i<50;i++)
	{
		if(a[i]) {pro*=i; b[c]=pro; c++; }
	}
    while(t--)
    {
       cin>>n;
       if(n==1)
       {
           cout<<"1\n";
           continue;
       }
       for(i=1;i<20;i++)
       {
           if(n>=b[i-1] && n<b[i]) { cout<<fixed<<setprecision(0)<<b[i-1]<<"\n"; break;}

       }
    }
    return 0;
}
