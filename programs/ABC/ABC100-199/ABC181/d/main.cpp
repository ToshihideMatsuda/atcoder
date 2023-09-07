#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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


int solve(string S)
{

	if(S.size() == 1) {
		if(S[0] == '8') {
			out("Yes")
			return 0;
		} else {
			out("No")
			return 0;
		}
	} else if(S.size() == 2) {
		ll v1 = stoll(S), v2 = (S[1] - '0') * 10 + (S[0] - '0');
		if( v1 % 8 == 0  || v2 % 8 == 0) {
			out("Yes")
			return 0;
		} else {
			out("No")
			return 0;
		}
	} else {
		vector<ll> c(10,0);
		rep(i,S.size()) {
			c[S[i] - '0'] ++;
		}

		for(int s = 112; s < 1000 ; s += 8) {
			bool ok = true;
			for(auto cc : to_string(s) ) if(cc == '0'){
				ok = false; break;
			}

			if(ok) {

			vector<ll> t(10,0);
			ll tmp = s;
			while(tmp > 0) {
				t[tmp % 10] ++;
				tmp /= 10;
			}

			reps(i,1,10) if(c[i] < t[i]) goto next;

			
			out("Yes")
			return 0;
			}

			next:
			continue;
		}

		out("No")
		return 0;
	}

	return 0;
}


int main()
{
	string S; cin >> S;
	solve(S);
	return 0;
}