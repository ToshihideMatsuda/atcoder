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
	ll N; cin>>N;
	ll A[3005][5];
	rep(i,N)rep(j,5)cin>>A[i][j];
	
	ll ub =1000000009,lb=0;
	while(lb+1<ub){
		//cout<<"["<<lb<<","<<ub<<")"<<endl;
		ll mid =(ub+lb)/2;

        set<ll> valids;

		rep(i,N){
            ll ret = 0;
            rep(j,5){
			    if(mid<=A[i][j]){
				    ret |= (1<<j);
			    }
		    }
            valids.insert(ret);
        }

		bool ret = false;

        for(ll x : valids)for(ll y : valids)for(ll z : valids) {
            if((x|y|z) == 31) ret = true;
        }

		next:
		if(ret){
			lb=mid;
		} else {
			ub=mid;
		}
		
	}
	
	cout <<lb<<endl;
}

int main(){
    solve();
    return 0;
}

