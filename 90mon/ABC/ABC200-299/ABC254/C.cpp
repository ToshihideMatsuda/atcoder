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


void solve() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N), AA(N);

    rep(i, N) {
        cin >> A[i];
        AA[i] = A[i];
    }

    sort(AA.begin(), AA.end());

    rep(i,K) {
        vector<ll> sA, sAA;
        for(int j = i; j < N; j += K) {
            sA.push_back(A[j]);
            sAA.push_back(AA[j]);
        }

        sort(sA.begin(), sA.end());

        rep(j,sA.size())  if(sA[j] != sAA[j]) NO();

    }
    YES();

}


int main()
{
  solve();
	return 0;
}