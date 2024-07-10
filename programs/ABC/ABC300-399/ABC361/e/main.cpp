#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）
/* ---------------------- ここから ---------------------- */
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using bll = mp::cpp_int;
// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using real = mp::number<mp::cpp_dec_float<1024>>;
/* ---------------------- ここまで ---------------------- */

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
#define MINF_LL (-9223372036854775808LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<vector<pair<ll,ll>>> G;
vector<bool> visited;

ll N; 

// 重みつき無向グラフGの直径を求めるアルゴリズム
pair<ll,ll> dfs(ll v) {
    visited[v] = true;
    ll max_dist = 0;
    ll farthest = 0;
    for (auto [u, w] : G[v]) {
        if (!visited[u]) {
            auto [d, f] = dfs(u);
            ll dist = d + w;
            if (dist > max_dist) {
                max_dist = dist;
                farthest = f;
            }
        }
    }
    if(max_dist == 0) { // 子ノードがない場合
        farthest = v;
    }
    return make_pair(max_dist,farthest);
}

int main()
{
    cin >> N;
    G.resize(N+1);
    visited.resize(N+1);
    ll sum = 0;
    rep(i,N-1) {
        ll a, b, c;
        cin >> a>> b >> c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
        sum += c;
    }


    fill(visited.begin(), visited.end(), false);
    auto [d, farthest] = dfs(1);

    fill(visited.begin(), visited.end(), false);
    auto [d2, farthest2] = dfs(farthest);

    out(2 * sum - d2);
    



	return 0;
}