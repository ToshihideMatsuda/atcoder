#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i-- ) 
#define revs(i,m,n)  for(ll i = m; i > n; i-- ) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5


void solve(){
	ll N;string S, X;
	cin >> N>>S>>X;
	vector<set<ll>>dp(N+1);
	dp[N]={0};
	rev(i,N-1){
		ll c = S[i]-'0';
		rep(r,7){
			if(X[i]=='T'){
				if(dp[i+1].count((10*r)%7)||
				   dp[i+1].count((10*r+c)%7)){
				   	dp[i].insert(r);
				}
			} else{ //A
				if(dp[i+1].count((10*r)%7)&&
				   dp[i+1].count((10*r+c)%7)){
				   	dp[i].insert(r);
				}
			}
		}
	}
	/*
	rev(i,N){
		cout<<"dp["<<i<<"]={";
		for(auto p :dp[i]){
			cout << p << ",";
		}
		cout <<"}"<<endl;
	}
	*/
	if(dp[0].count(0))cout<<"Takahashi";
	else cout<<"Aoki";
	

}

int main(){
    solve();
    return 0;
}

