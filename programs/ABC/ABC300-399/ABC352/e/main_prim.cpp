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
vector<pair<ll, ll>> G[MAX_N]; // G[from] = { cost, to } 頂点 from->to の辺のコストがcost
bool used[MAX_N];
ll usedCnt =0;
ll N, M;

ll prim(ll s) {
    rep(i,MAX_N) used[i] = false;

    //最小全域木
    priority_queue  Q = priority_queue<
        pair<ll,ll>,
        vector<pair<ll,ll>>,
        greater<pair<ll,ll>>>(); // priority queue { c, v }

    //最大全域木
    /*
    priority_queue Q = priority_queue<
        pair<ll,ll>,
        vector<pair<ll,ll>>,
        less<pair<ll,ll>>>(); // priority queue { c, v }
    */
    

    //開始地点sから到達できる箇所のコストを登録
    for(auto pair:G[s]){
        Q.push(pair);
    }

    used[s] = true;
    usedCnt ++;

    ll ans = 0;
    
    while(usedCnt < N) {    //全てのVが登録されるまで実施
        //コスト最小辺を抽出
        auto pair = Q.top();Q.pop();
        auto v = pair.second;
        auto c = pair.first;

        if(used[v] == false) {
            used[v] = true;
            ans += c;       //コストを追加
            usedCnt ++;
            for(auto u : G[v]) Q.push(u); //辺を追加
        }
    }
    return ans;
}

int main()
{
	cin >> N >> M; 

	map<ll,map<ll,ll>> mp;

	vector<pair<ll,vector<ll>>> CA;

	rep(i,M) {
		ll k, c; cin >> k >> c;
		vector<ll> a(k); 
		cin >> a[0];
		reps(j,1,k) {
			cin >> a[j];
			G[a[0]].push_back({c,a[j]});
			G[a[j]].push_back({c,a[0]});
		}

	}

	queue<ll> Q;
	Q.push(1);
	used[1] = true;

	while(Q.size() > 0) {
		auto q = Q.front();Q.pop();
		for(auto [c,v] : G[q]) if(used[v] == false){
			used[v] = true;
			Q.push(v);
		}
	}

	reps(i,1,N+1) {
		if(used[i] == false) {
		out(-1)
		return 0;
		}
		used[i] = false;
	}

	out(prim(1))


	return 0;
}