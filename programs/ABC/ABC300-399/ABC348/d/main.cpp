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


#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
	ll H, W; cin >> H >> W;
	vector<string> A(H+2);
	string T = "";
	rep(i,W+2) T += "#";
	A[0] = T; A[H+1] = T;

	pair<ll,ll> s, g;
	rep(h,H){
		string a; cin >> a;
		A[h+1] = "#" + a + "#";
		rep(w,W) if(a[w] == 'S') {
			s = {h+1,w+1};
		} else if(a[w] == 'T') {
			g = {h+1,w+1};
		}
	}

	ll N; cin >> N;
	vector E = vector(H+1, vector(W+1,0));
	vector<tuple<ll,ll,ll>> RCE(N+1);
	rep(i,N) {
		ll r, c, e; cin >> r >> c >> e;
		E[r][c] = i+1;
		RCE[i+1] = {r,c,e};
	}

	E[g.first][g.second] = N+1;

	vector<ll> G[N+2];

	if(E[s.first][s.second] == 0) {
		out("No")
		return 0;
	}

	G[0].push_back(E[s.first][s.second]);

	ll dx[4] = {0,0,1,-1};
	ll dy[4] = {1,-1,0,0};
	reps(i,1,N+1) {
		auto[r,c,e] = RCE[i];
		vector visited = vector(H+1, vector(W+1,false));
		queue<tuple<ll,ll,ll>> Q;
		Q.push({r,c,e});
		visited[r][c] = true;
		while(Q.size() > 0) {
			auto [r,c,e] = Q.front();Q.pop();
			rep(j,4) if(A[r+dx[j]][c+dy[j]] != '#') {
				if(visited[r+dx[j]][c+dy[j]] == false) {
					visited[r+dx[j]][c+dy[j]] = true;
					if(E[r+dx[j]][c+dy[j]] > 0) {
						G[i].push_back(E[r+dx[j]][c+dy[j]]);
					}
					if(e-1 > 0) {
						Q.push({r+dx[j], c+dy[j], e-1});
					}
				}
			}
		}
	}

	vector visited = vector<bool>(N+2,false);
	queue<ll> Q;
	Q.push(0);
	visited[0] = true;
	while(Q.size() > 0) {
		auto q = Q.front();Q.pop();
		for(auto g:G[q])if(visited[g] == false) {
			visited[g] = true;
			Q.push(g);
		}
	}

	if(visited[N+1]) {
		out("Yes")
	} else {
		out("No")
	}


	


	


	return 0;
}