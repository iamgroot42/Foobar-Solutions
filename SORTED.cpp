#include<iostream>

using namespace std;

//FooBar hates me -_-

int main()
{
    ios_base::sync_with_stdio(0);
    int t,x,i,j;
    cin>>t;
    while(t--)
    {
        cin>>x;
        long a[x];
        long long ans=0;
        j=0;
        for(i=0;i<x;i++)
        {
            cin>>a[i];
        }


       for(i=1;i<x;i++)
       {

		if(a[i]>a[i-1]) // When order changes to decreasing,run inner part
			{

				ans+=a[j]-a[i-1];
				j=i;
			}

       	}
       	ans+=a[j]-a[i-1];



            cout<<ans<<"\n";
        }

    return 0;
}

