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
#define MOD (1000000000 + 7)

#define MAX_N (2*100000+5)

// 素因数分解の初期化関数
// f[n]= [ {p1,e1}, {p2,e2}, ..., {pm,em} ] : n = p1^e1 * p2^e2 * ... * pm^em
// f[n][p1] = e1, f[n][p2] = e2, ..., f[n][pm] = em
unordered_map<ll,ll> f[1000 + 5];
void factorial_init(ll N) {
    f[1][1] = 1;
    for(ll i = 2; i < N+1; i++) {
        if(f[i].size() == 0) {
            for(int j = i; j < N+ 1; j+= i) {
                ll tmp = j;
                ll cnt = 0;
                while(tmp % i == 0) {
                    tmp = tmp / i;
                    cnt ++;
                }
                f[j][i] = cnt;
            }
        }
    }
}

int main()
{
  ll N; cin >> N;
  factorial_init(N);

  unordered_map<ll,ll> all;

  reps(i,2,N+1) {
    for(auto idx = f[i].begin();idx != f[i].end(); ++idx) {
      auto [x, a] = *(idx);
      if(x > 1) {
        all[x] += a;
      }
    }
  }
  
  ll ans = 1;
  for(auto idx = all.begin();idx != all.end(); ++idx) {
      auto [x, a] = *(idx);
      ans *= (a+1);
      ans %= MOD;
  }

  out(ans)

	return 0;
}