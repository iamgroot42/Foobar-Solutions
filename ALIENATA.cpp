#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007

void multiply(long F[2][2], long M[2][2]) // Function for matrix multiplication
{
  long x =  ((F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod)%mod;
  long y =  ((F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod)%mod;
  long z =  ((F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod)%mod;
  long w =  ((F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod)%mod;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void power(long F[2][2], int n)
{
  if( n == 0 || n == 1)
      return;
  long M[2][2] = {{0,1},{2,1}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

int alien(int n)
{
  long F[2][2] = {{0,1},{2,1}};
  if (n == 0)
    return 0;
  if (n==1)
    return 2;
  power(F, n-1);
  return ((F[0][0]*2)%mod + (F[0][1]*7)%mod)%mod;
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<alien(n)%mod<<"\n";
    }
    return 0;
}
