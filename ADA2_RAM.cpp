#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	int n;
	int nways[2000002] = {0};
	for(int i=1;i<=100;++i){
		for(int j=i;j<=100;++j){
			nways[i*i*i + j*j*j]++;
		}
	}
	cin>>n;
	for(int i=1;i<=n;++i){
		if(nways[i] >= 2){
			cout<<i<<endl;
		}
	}
	return 0;
}
