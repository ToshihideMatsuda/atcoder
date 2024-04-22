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

#define MAX_N (5*100000+5)

string S; 
vector<ll> ldepth(MAX_N);
map<ll,vector<ll>> rdepth;
vector<ll> Next;
vector<ll> Reverse;

void dfs(ll l, ll r, bool reverse) {
	if((l <= r) == false) return;
	//out0("s = ")out(S.substr(l, r-l+1))

	ll l2 = l;
	while(true){
		if(S[l2] == '(') break;
		if(l2 == r) {
			if(reverse) for(int i = r; i >= l; i--) Next.push_back(i);
			else	 	for(int i = l; i <= r; i++) Next.push_back(i);
			return;
		}
		l2++;
	} 

	ll d = ldepth[l2];
	ll r2 = *( lower_bound(rdepth[d].begin(),rdepth[d].end(),l2) );

	if(reverse) {
		if(r2 != r) dfs(r2+1,r,reverse);
		
		dfs(l2+1, r2-1, !reverse);
		Reverse[l2+1] += 1;
		Reverse[r2] += -1;
		
		for(int i = l2-1; i >= l; i--)Next.push_back(i);
	}
	else {
		for(int i = l; i < l2; i++)Next.push_back(i);
		dfs(l2+1, r2-1, !reverse);
		Reverse[l2+1] += 1;
		Reverse[r2] += -1;		

		if(r2 != r) dfs(r2+1,r,reverse);
	}

}

int main()
{
	cin >> S;

	ll d = 0;
	rep(i,S.size()) {
		if(S[i] == '(') {
			d ++; 
		} else if(S[i] == ')'){
			rdepth[d].push_back(i);
			d --;
		}
		ldepth[i] = d;
	}


	Reverse.resize(S.size());
	dfs(0, S.size()-1, false);
	rep(i, S.size()-1) Reverse[i+1] += Reverse[i];

	for(auto i : Next) {
		if(S[i] != '(' && S[i] != ')') {
			if(Reverse[i] % 2 == 0) {out0(S[i]); }
			else {
				if('a' <= S[i] && S[i] <= 'z') {
					string ret(1,S[i] - 'a' + 'A');
					out0(ret)
				}
				else {
					string ret(1,S[i] - 'A' + 'a');
					out0(ret);
				}
			}
		}
	}
	cout << endl;

	
	return 0;
}

//dFGsdccCrFNNnplCtQPOKjsiIwwEysAve
//dFGsdccCrFNNnplCtQPOKjsiIwwEysAve