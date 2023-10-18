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

ll gcd(ll a, ll b)          /* ユークリッドの互除法 */
{   
    if(b == 0) return a;     /* 計算結果を返す */
    else return gcd(b, a%b); /* 互除法の反復 */                    
}

ll f(ll A, ll v) {
	if(A%v == 0) return 0;
	else return v - A%v;
}

int main()
{
	ll N; cin >> N;
	ll a, b, c; cin >> a >> b >> c;
	ll 	ab = (a * b)  / gcd(a, b),
		bc = (b * c)  / gcd(b, c),
		ca = (c * a)  / gcd(c, a),
		abc= (ab * c) / gcd(ab, c);

	vector<ll> A(N);
	vector<pair<ll,ll>> Aa(N), Ab(N), Ac(N), Aab(N),Abc(N),Aca(N),Aabc(N);
	rep(i,N){
		 cin >> A[i];
		 Aa[i] = {f(A[i],a),i};
		 Ab[i] = {f(A[i],b),i};
		 Ac[i] = {f(A[i],c),i};
		 Aab[i] = {f(A[i],ab),i};
		 Abc[i] = {f(A[i],bc),i};
		 Aca[i] = {f(A[i],ca),i};
		 Aabc[i] = {f(A[i],abc),i};
	}
	sort(Aa.begin(),Aa.end());
	sort(Ab.begin(),Ab.end());
	sort(Ac.begin(),Ac.end());
	sort(Aab.begin(),Aab.end());
	sort(Abc.begin(),Abc.end());
	sort(Aca.begin(),Aca.end());
	sort(Aabc.begin(),Aabc.end());

	ll ans = Aabc[0].first;
	if(N >= 2) {
		if(Aab[0].second != Ac[0].second) ans = MIN(ans, Aab[0].first + Ac[0].first);
		else ans = MIN3(ans, Aab[0].first + Ac[1].first, Aab[1].first + Ac[0].first);

		if(Abc[0].second != Aa[0].second) ans = MIN(ans, Abc[0].first + Aa[0].first);
		else ans = MIN3(ans, Abc[0].first + Aa[1].first, Abc[1].first + Aa[0].first);

		if(Aca[0].second != Ab[0].second) ans = MIN(ans, Aca[0].first + Ab[0].first);
		else ans = MIN3(ans, Aca[0].first + Ab[1].first, Aca[1].first + Ab[0].first);

		if(N >= 3) {
			rep(i,3)rep(j,3)rep(k,3) {
				if(Aa[i].second != Ab[j].second &&
			   	   Ab[j].second != Ac[k].second &&
			   	   Ac[k].second != Aa[i].second)  {
					ans = MIN(ans, Aa[i].first + Ab[j].first + Ac[k].first);
				}
			}
		}
	}
	out(ans)




	return 0;
}