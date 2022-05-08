#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}


ll N = (1LL << 20);

unordered_map<ll,ll> mp;
unordered_map<ll,ll> A;

ll update_mp (ll p) {
    ll val = 0;
    if( mp.count(p % N) == 0 ) {
        val = p % N;
    } else {
        val = update_mp(mp[p%N]);
    }
    mp[p % N] = val;

    return val;
}

int main()
{
    ll Q;
    cin >> Q;


    rep(_, Q) {
        ll t, x; 
        cin >> t >> x;
        if (t == 1) {
            update_mp(x % N);
            ll nx = mp[x % N];
            
            A[nx] = x;
            mp[nx] = (nx + 1) % N;
        } else {
            if(A.count(x % N) ) {
                cout << A[x % N] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

	return 0;
}