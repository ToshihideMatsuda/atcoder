#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

#define debug false

#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 

typedef long long ll;
#define MOD 1000000000+7
#define MAX_N 2*100000+5


vector<ll> G[MAX_N];
ll check[MAX_N];
set<ll> ss[MAX_N];
int main(){
	ll N,M;cin >> N >> M;
	
	rep(i,M){
		ll a,b;
		cin >> a >>b;
		if(b<a)swap(a,b);
		if(ss[a].count(b))continue;
		
		
		G[a].push_back(b);
		G[b].push_back(a);
		ss[a].insert(b);
		ss[b].insert(a);
	}
	ll ans =0;
	
	reps(i,1,N+1){
		if(check[i]==0){
			ll idx = 1;
			
			queue<ll> Q;
			Q.push(i);
			while(Q.size()>0){
				auto q =Q.front();Q.pop();
				if(check[q]>0) continue;
				check[q]=idx;
				ans = max(ans,idx);
				idx++;
				for(auto g:G[q]) if(check[g]==0)
				{
					Q.push(g);
				}
			}
		}
	}
	cout << ans <<endl;
    return 0;
}
