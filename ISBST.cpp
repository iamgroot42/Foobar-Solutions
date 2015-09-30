#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(0);
  int t,n,i,flag;
  cin>>t;
  while(t--)
  {
    cin>>n;
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    flag=0;
    for(i=0;i<n;i++)
    {
      if(2*i+1<n)
      {
        if(a[i]<a[2*i+1])
        {
          flag=1;
          break;
        }
      }
      if(2*i+2<n)
      {
        if(a[i]>a[2*i+2])
        {
          flag=1;
          break;
        }
      }
    }
    if(flag) cout<<"NO\n";
    else cout<<"YES\n";
  }
  return 0;  
}