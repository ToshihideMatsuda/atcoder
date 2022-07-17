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
#define MOD 998244353


int main(){
	ll N,K;cin>>N>>K;
	if(N<2*K){
		cout << -1 <<endl;
	}else {
        vector<ll> seed(2*K);
        rep(i,2*K) seed[i] = (K+i)%(2*K)+1;

        rep(i, N/seed.size() - 1){
            rep(j,seed.size()){
                cout << seed[j] + i*seed.size() << " ";
            }
        }

        ll mc = (N/seed.size() - 1) * seed.size();
        
        if(N-mc > 3* K) {
            set<ll> s;
            reps(i,mc,mc+K){ 
                cout << K+i+1 << " ";
                s.insert(K+i+1);
            }
            rep(i, N-mc-3*K){
                cout << mc + i + 1 << " ";
                s.insert(mc+i+1);
            }
            rep(i,K) {
                cout << N -(K-1-i) << " ";
                s.insert(N-(K-1-i));
            }
            vector<ll> final;
            reps(i,mc,N) if(!s.count(i+1)) final.push_back(i+1);

            for(auto f : final) cout << f << " ";

        } else {
            reps(i,mc,N){
                if(K+i+1 <= N) {
    			    cout << K+i+1 <<" ";
                } else {
    			    cout << mc + (K+i+1) % N <<" ";
                }
	    	}
        }
	}
	
    return 0;
}
