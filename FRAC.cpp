#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	int t;
	int dp[100001];
	long long answer[100001];
	dp[1] = dp[2] = 1;
	for(int i=3;i<100001;++i){
		dp[i] = (i-1);
		for(int j=2;j<=sqrt(i);++j){
			if(i%j==0){
				dp[i] -= dp[j];
			}
			if((j*j != i) && (i%(i/j)==0)){
				dp[i] -= dp[i/j];
			}
		}
	}
	answer[1] = dp[1];
	for(int i=2;i<100001;++i){
		answer[i] = answer[i-1] + dp[i];
	}
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<(answer[n])<<endl;
	}
	return 0;
}
