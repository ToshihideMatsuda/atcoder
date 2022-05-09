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


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*1000000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}


void solve() {
    ll N, K;
    cin >> N >> K;
    
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    ll X = 0, Y = 0;
    ll L = 0, R = 0;

    unordered_map<ll,pair<ll,ll>> mp;


    rep(i, min(K, N + 1) ) {
        if(mp.count(X%N)) 
        {
            Y = X - mp[X%N].first;
            R = L - mp[X%N].second;
            L = mp[X%N].second;

            break;
        }

        mp[X%N] = {X, L};
        X += A[X%N];
        L++;
    }

    X = 0;

    rep(_, L) X += A[X%N];
    if(R > 0) 
    {
        if( (K-L)/R > 0) X += ((K-L)/R) * Y;
        rep(_, (K-L)%R ) X += A[X%N];
    }

    cout << X << endl;

}

int main()
{
    solve();
	return 0;
}