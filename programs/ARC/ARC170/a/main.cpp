#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;

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

// "aabbbbaaca" -> [("a",2),("b",4),("a",2),("c",1),("a",1)]
vector<pair<string,ll> > runLengthEncoding(string S) {
    vector<pair<string,ll> > ret;
    ll i = 0;
    while(i < S.size()) {
        ll cnt = 1;
        while(i+1 < S.size() && S[i] == S[i+1]) {
            cnt++;
            i++;
        }
        ret.push_back(make_pair(S.substr(i,1),cnt));
        i++;
    }
    return ret;
}

int main()
{
	ll N; cin >> N;
	string S, T; cin >> S >> T;

	if(S==T) {
		out(0)
		return 0;
	}

	rep(i,N) {
		if(S[i] == 'B' && T[i] == 'B') continue;
		else if(S[i] =='A' && T[i] == 'B') {
			out(-1)
			return 0;
		} else {
			break;
		}
	}

	for(ll i = N-1; i > -1; i--) {
		if(S[i] == 'A' && T[i] == 'A') continue;
		else if(S[i] =='B' && T[i] == 'A') {
			out(-1)
			return 0;
		} else {
			break;
		}
	}

	string U = "";
	rep(i,N) if(T[i] != S[i]) U += S[i];

	ll ans = 0;

	auto List = runLengthEncoding(U);

	ll remainB = 0;
	rep(j,List.size()) {
		if(List[j].first == "A") {
			remainB = MAX(0, remainB - List[j].second);
			ans += List[j].second;
		} else {
			remainB += List[j].second;
		}
	}

	ans += remainB;

	out(ans)

	return 0;
}