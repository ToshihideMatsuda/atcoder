#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）
/* ---------------------- ここから ---------------------- */
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


#define INF  (2000000000000000001LL)
#define MINF (-2000000000000000001LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
	string S; cin >> S;
	ll Q; cin >> Q;

	vector<ll> two(63);
	two[0] = S.size();
	ll T = 0;
	reps(i,1,63)  {
		two[i] = two[i-1] * 2; 
		if(1000000000000000000 < two[i]) {
			T = i;
			break;
		}
	}

	rep(_,Q) {

		ll K; cin >> K;
		if(K==13) {
			ll t = 0;
		}

		ll i = 1;
		ll t = T;
		while(two[0] <  K) {
			while(K <= two[t]) t--;
			K -= two[t];
			i *= -1;
		}

		if('a' <= S[K-1] && S[K-1] <= 'z'){
			if(i == 1) {
				cout << S[K-1] << " ";
			} else {
				cout << (char)(S[K-1]-'a'+'A') << " ";
			}
		} else {
			if(i == 1) {
				cout << S[K-1] << " ";
			} else {
				cout << (char)(S[K-1]-'A'+'a') << " ";
			}

		}

	}




	return 0;
}


/*
S
ST
STTS
STTS|TSST
STTSTSST|TSSTSTTS
*/

//a B A b A b a B A b a B a B A b %                      
//a B A b A b a B A b a B a B A b
                                                                                                                                                                                                                                                                                             