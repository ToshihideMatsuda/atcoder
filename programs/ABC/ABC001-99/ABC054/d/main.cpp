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

#define MAX_N 
set<ll> G[10];

int main()
{
  ll N, Ma, Mb; cin >> N >> Ma >> Mb;
  vector<ll> a(N), b(N), c(N);
  map<pair<ll,ll>,ll> mp1, mp2;
  rep(i,N) {
    cin >> a[i] >> b[i] >> c[i];
  }


  ll h = N/2, r = N - h;
  for(int i = 0; i < (1 << h); i ++) {
    ll A = 0, B = 0, C= 0;
    rep(j,h) if( (i & (1 << j)) > 0 )  {
      A += a[j];
      B += b[j];
      C += c[j];
    }

    pair<ll,ll> D = {A,B};
    if(mp1.count(D) ) {
      mp1[D] = MIN(mp1[D],C);
    } else {
      mp1[D] = C;
    }

  }

  for(int i = 0; i < (1 << r); i ++) {
    ll A = 0, B = 0, C= 0;
    rep(j,r) if( (i & (1 << j)) > 0 )  {
      A += a[h+j];
      B += b[h+j];
      C += c[h+j];
    }

    pair<ll,ll>  D = {A,B};
    if(mp2.count(D) ) {
      mp2[D] = MIN(mp2[D],C);
    } else {
      mp2[D] = C;
    }

  }

  const ll top = 40 * 10;

  ll ans = INF_LL;

  reps(i,1, 1 + top) {
    pair<ll,ll> M = {Ma*i,Mb*i};
    if(mp1.count(M)) {
      ans = MIN(ans, mp1[M]);
    }
    if(mp2.count(M)) {
      ans = MIN(ans, mp2[M]);
    }
  }


  for(auto idx = mp1.begin();idx != mp1.end(); ++idx) {
    auto [m,c] = (*idx);
    auto [ma,mb] = m;
    ll maa = Ma-ma;
    ll mbb = Mb-mb;
    while(maa < 0 || mbb < 0){
      maa +=Ma;
      mbb +=Mb;
    } 


    rep(i,top) {
      pair<ll,ll> M = {maa+Ma*i,mbb+Mb*i};
      if(mp2.count(M)) {
        ans = MIN(ans, c + mp2[M]);
      }
    }
  }

  if(ans == INF_LL) ans =-1;
  out(ans)







	return 0;
}