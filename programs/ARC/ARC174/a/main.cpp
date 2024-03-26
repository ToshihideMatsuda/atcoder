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

int main()
{
	ll N; cin >> N;
	vector<ll> P(N) ;
	rep(i,N) cin >> P[i];
	string S; cin >> S;
	vector<bool> used(N,false);
	rep(i,N) P[i] --;
	
	//
	ll ans = 0;
	if(S[P[0]%N] == 'R' || S[P[0]%N] == '?') { // all R
		used[(P[0]+1)%N] = true;
		ll tmp = 1;
		reps(i,1,N) {
			if(S[P[i]%N] == 'L') {
				if(used[P[i]%N] == true && used[(P[i]+1)%N] == false) {
					//nop
				} else {
					goto next1;
				}
			} else if(S[P[i]%N] == 'R') { 
				if(used[(P[i]+1)%N] == false) {
					//nop
				} else {
					goto next1;
				}
			} else { 
				if(used[P[i]%N] == true && used[(P[i]+1)%N] == false){
					tmp *= 2;
					tmp %= 998244353;
				} else if(used[(P[i]+1)%N] == false){
					//nop
				} else {
					goto next1;
				}
			}
			used[(P[i]+1)%N] = true;

		}

		ans += tmp;
		ans %= 998244353;
	}
	next1:

	rep(i,N) used[i] = false;
	if(S[P[0]] == 'L' || S[P[0]] == '?') { // all L
		used[P[0]] = true;
		
		ll tmp = 1;
		reps(i,1,N) {
			if(S[P[i]%N] == 'R') {
				if(used[P[i]%N] == false && used[(P[i]+1)%N] == true) {
					//nop
				} else {
					goto next2;
				}
			} else if(S[P[i]%N] == 'L') { 
				if(used[P[i]%N] == false) {
					//nop
				} else {
					goto next2;
				}
			} else { 
				if(used[P[i]%N] == false && used[(P[i]+1)%N] == true){
					tmp *= 2;
					tmp %= 998244353;
				} else if(used[P[i]%N] == false){
					//nop
				} else {
					goto next2;
				}
			}
			used[P[i]%N] = true;
		}

		ans += tmp;
		ans %= 998244353;
	}
	
	next2:

	out(ans)


	return 0;
}