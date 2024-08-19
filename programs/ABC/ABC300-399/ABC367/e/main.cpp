#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out0(s) cout << s;
#define out(s)  cout << s << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) push_back(s)
/*
	vector<ll> X = {4,7,3,1,7,9,4};
	SORT(X, <)
	OUT(X,",") //1,3,4,4,7,7,9,

	SORT(X, >)
	OUT(X," ") //9 7 7 4 4 3 1
*/
#define SORT(A,R) std::sort((A).begin(),(A).end(), [](auto const& x, auto const& y) { return x R y; });
#define OUT(A,separate) for(auto a : A) { cout << a << separate; }


#define INF (2147483647)
#define MINF (-2147483648)
#define INF_LL  (9223372036854775807LL)
#define MINF_LL (-9223372036854775807LL)
#define MOD 998244353

#define MAX_N (2*100000+5)

ll p = 707972951LL;
ll s = 418311299LL;
ll N, K; 


int main()
{cin >> N >> K;
    vector<ll> X(N);rep(i,N) { cin >> X[i]; X[i]--; }
    vector<vector<ll>> Y(N);rep(i,N) Y[X[i]].push_back(i);
    vector<ll> A(N);rep(i,N) cin >> A[i];
    vector<ll> B(A);
    vector<ll> D;

    vector<ll> cnt(N);
  
    rep(i,N) cnt[X[i]] ++;

    vector<ll> target;
    rep(i,N) if( 2 <= cnt[i] ) target.push_back(i);
    if(target.size() == 0) rep(i,N)  target.push_back(i);
    
    vector<bool> visited(N,false);
    
    for(auto t: target) {
        visited[t] = true;
        vector<ll> h = {t};
        vector<ll> w = {t};

        while(X[w.back()] != w[0]) {
            if(2 <= Y[X[w.back()]].size()) {
                h.push_back(X[w.back()]);
            }
            w.push_back(X[w.back()]);
            
        }



    }




	return 0;
}