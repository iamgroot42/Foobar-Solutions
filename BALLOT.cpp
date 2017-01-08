#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> P;


struct Order
{
	bool operator()(P const& a, P const& b) const
	{
		return (a.first * b.second) < (a.second * b.first);
	}
};


int main(){
	ios_base::sync_with_stdio(0);
	int n,b;
	cin>>n>>b;
	long long x;
	priority_queue< P, vector<P>, Order> heap;
	for(int i=0;i<n;++i){
		cin>>x;
		heap.push(make_pair(x,1));
	}
	b -= n;
	while(b){
		P temp = heap.top();
		heap.pop();
		heap.push(make_pair(temp.first, temp.second+1));
		b--;
	}
	double num = (heap.top()).first;
	double den = (heap.top()).second;
	double answer = num / den;
	cout<<ceil(answer)<<endl;
	return 0;
}
