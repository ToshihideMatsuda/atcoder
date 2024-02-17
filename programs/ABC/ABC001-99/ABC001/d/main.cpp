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

string pad(ll m) {
	if(m < 10) return "000" + to_string(m);
	if(m < 100) return "00" + to_string(m);
	if(m < 1000) return "0" + to_string(m);
	return to_string(m);
}

int main()
{

	priority_queue<pair<ll,ll>, vector<pair<ll, ll>>, greater<pair<ll,ll> > > Q;
	ll n; cin >> n;
	rep(i,n) {
		string s;
		cin >> s;
		ll from = stoll(s.substr(0,4));
		ll from_h = from / 100;
		ll from_m = (( from % 100 ) / 5 )* 5;

		ll to = stoll(s.substr(5,4));

		ll to_h = to / 100;
		ll to_m = (((to % 100) + 4)/5) * 5;
		if(to_m == 60) {
			to_h++;
			to_m=0;
		}

		Q.push({from_h*100+from_m, to_h*100 + to_m});
	}

	while(Q.size() > 0) {
		auto q = Q.top(); Q.pop();
		if(Q.size() == 0) {
			out0(pad(q.first)) out0("-") out(pad(q.second))
			break;
		}
		auto p = Q.top(); Q.pop();

		if(p.first <= q.second) {
			Q.push({q.first,MAX(q.second,p.second)});
		} else {
			out0(pad(q.first)) out0("-") out(pad(q.second))
			Q.push(p);
		}
	}


	return 0;
}