#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define fore(e,es) for(auto e:es)

int main(){
	int n;
	cin >> n;
	
	vector<int> A(n);
	map<int,int>cnt;
	long long sum=0;
	
	rep(i,n) cin >> A[i];
	rep(i,n) {
		cnt[A[i]]+=1;
	}
	
	rep(i,n){
		sum+=(n-i)-cnt[A[i]];
		cnt[A[i]]-=1;
	}
	
	cout<<sum<<endl;
	
	return 0;
}
