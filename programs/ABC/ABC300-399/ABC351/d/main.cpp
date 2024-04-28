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
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
	ll H, W; cin >> H >> W;
	
	ll ans = 1;

	vector<string> S(H+2);
	string T; rep(i,W+2) T += "#";
	S[0] = T; S[H+1] = T; 

	reps(i,1,H+1) {
		string s; cin >> s;
		S[i] = "#" + s + "#";
	}

	ll dx[4] = {1,-1,0,0};
	ll dy[4] = {0,0,1,-1};
	reps(h,1,H+1) reps(w,1,W+1) if(S[h][w] == '#') {
		rep(i,4) {
			char c = S[h+dx[i]][w+dy[i]];
			if(c == '.') {
				S[h+dx[i]][w+dy[i]] = '$';
			}
		}

	}

	vector visited = vector(H+2,vector<bool>(W+2,false));

	reps(h,1,H+1) reps(w,1,W+1) if(visited[h][w] == false && S[h][w] == '.'){
		
		queue<pair<ll,ll>> Q;
		Q.push({h,w});
		visited[h][w] = true;
		ll cnt = 1;

		set<pair<ll,ll>> c;

		while(Q.size() > 0) {
			auto [p,q] = Q.front();Q.pop();
			if(S[p][q] == '.') {
				rep(i,4){ 
					if(S[p+dx[i]][q+dy[i]] != '#' && visited[p+dx[i]][q+dy[i]] == false && c.count({p+dx[i],q + dy[i]}) == false){
						Q.push({p+dx[i],q+dy[i]});
						cnt++;
						if(S[p+dx[i]][q+dy[i]] == '.') {
							visited[p+dx[i]][q + dy[i]] = true;
						} else {
							c.insert({p+dx[i],q + dy[i]});
						}
					}
				}
			}
		}



		ans = MAX(ans,cnt);
	}
	out(ans)

	return 0;
}