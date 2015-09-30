#include<bits/stdc++.h>

using namespace std;

//GCD : http://codereview.stackexchange.com/questions/37189/euclids-algorithm-greatest-common-divisor

int gcd(int m,int n)
{
	int r;

    /* Check For Proper Input */
    if((m == 0) || (n == 0))
        return 0;
    do
    {
        r = m % n;
        if(r == 0)
            break;
        m = n;
        n = r;
    }
    while(true);

    return n;

}
int main()
{
	ios_base::sync_with_stdio(0);
	int t,i,n,ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		for(i=0;i<n;i++) cin>>a[i];
		ans=a[0];
		for(i=1;i<n;i++)
		{
			ans=gcd(ans,a[i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}