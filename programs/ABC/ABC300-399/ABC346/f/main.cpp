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
	ll N; cin >> N;
	string S, T; cin >> S >> T;
	set<ll> s; rep(i,S.size()) s.insert(S[i]);
	rep(i,T.size()) if(s.count(T[i]) == false) {
		out(0)
		return 0;
	} 

	// Tの全ての文字はSに含まれる。
	vector Scnt = vector(S.size(),vector(26,0));
	for(int i = S.size()-1;i > -1; i --) {
		if(i != S.size()-1) {
			rep(j,26) {
				Scnt[i][j] = Scnt[i+1][j];
			}
		}
		Scnt[i][S[i]-'a']++;
	}

	vector Sidx = vector(26,vector<ll>());
	rep(i,S.size()) Sidx[S[i]-'a'].push_back(i);

	ll lb = 0, ub = INF_LL;
	while(ub-lb > 1) {
		ll k = (ub+lb)/2;

		ll idx = 0;
		bool ok = true;
		rep(i, T.size()) {
			ll j = (idx % S.size());
			ll t = Scnt[j][T[i]-'a'];
			if(k <= t) {
				if(k == 1 && S[j] == T[i]) {
					idx++;
				} else {
					ll lb= j, ub = S.size();
					while(ub - lb > 1) {
						ll mid = (ub+lb)/2;
						if( k<= t-Scnt[mid][T[i]-'a'] ){
							ub = mid;
						} else {
							lb = mid;
						}
					}
					idx += (ub-j);
				}
			} else {

				ll q = (k-t)/Scnt[0][T[i]-'a'];
				ll r = (k-t)%Scnt[0][T[i]-'a'];
			
				if(r == 0) {
					idx += (S.size()-j) + ((q - 1) *S.size()) + Sidx[T[i]-'a'].back()+1 ;
				} else if(r > 0){
					idx += (S.size()-j) + (q * S.size()) + Sidx[T[i]-'a'][r-1]+1 ;
				}
			}

			if(N * S.size() < idx) {
				ok = false;
				break;
			}
		}

		if(ok) {
			lb  = k;
		} else {
			ub = k;
		}

	}


	out(lb)
	return 0;
}