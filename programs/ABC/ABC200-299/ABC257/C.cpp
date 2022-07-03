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

#define MAX_N 2*100000+5

ll N;
string S; 
vector<ll> W, Ws;
vector<ll> A, C;


void solve() {
    cin >> N >> S;
    W.resize(N);
    Ws.resize(N);
    A.resize(N);
    C.resize(N);
    rep(i,N) {
        cin >> W[i];
        W[i] *= 2;
        if(S[i] == '0') W[i] ++;
        Ws[i] = W[i];
    }

    sort(Ws.begin(),Ws.end());
    unordered_map<ll,ll> mp;
    rep(i,Ws.size())  mp[Ws[i]] = i;
    rep(i,W.size()) W[i] = mp[W[i]];

    rep(i,N) 
    {
      if(S[i] == '1') A[W[i]] += 1;
      if(S[i] == '0') C[W[i]] += 1;
    }

    rep(i,N-1) A[(N-1)-(i+1)] = A[(N-1)-(i+1)] + A[ (N - 1)  - i];
    rep(i,N-1) C[i+1]         = C[i+1]         + C[i];

    ll ans = 0;
    rep(i,N) ans = max(ans,A[i] + C[i]);
    cout << ans << endl;


}


int main()
{
  solve();
	return 0;
}