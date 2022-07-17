#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))
#define mkp(a,b) make_pair(a,b)

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 10*100000+5

set<ll> factors[MAX_N];

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

void solve() {
    ll N; cin >> N;
    vector<ll> A(N); rep(i,N) cin >> A[i];
    

    reps(i,2,MAX_N) {
        if(factors[i].size() == 0) {
            for(ll j = i; j < MAX_N; j += i) {
                factors[j].insert(i);
            }
        }
    }

    ll r = A[0];
    reps(i,1,N) r = gcd(r,A[i]);

    if(r > 1) {
        cout << "not coprime" << endl;
        return ;
    } else {
        set<ll> s;
        rep(i,N) {
            for(auto f : factors[A[i]]) if(s.count(f)){
                cout << "setwise coprime" << endl;
                return;
            } else {
                s.insert(f);
            }
        }
        cout << "pairwise coprime" << endl;
    }
    



}


int main()
{
  solve();
	return 0;
}