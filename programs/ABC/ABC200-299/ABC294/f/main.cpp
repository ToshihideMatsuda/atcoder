#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define reps(i, m, n) for (ll i = m; i < n; i++)
#define rev(i, n) for (ll i = n; i > -1; i--)
#define revs(i, m, n) for (ll i = m; i > n; i--)
#define MAX(a, b) (a > b ? a : b)
#define MAX3(a, b, c) MAX(a, MAX(b, c))
#define MIN(a, b) (a < b ? a : b)
#define MIN3(a, b, c) MIN(a, MIN(b, c))
#define out(s) cout << s << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define out2(s) cout << s;
#define pb(s) push_back(s)

#define INF (1 << 30)
#define MINF -1 * (1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL -(1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2 * 100000 + 5)
vector<ll> G[MAX_N];
bool ck[MAX_N];
void clear() { rep(i, MAX_N) ck[i] = false; }
void readG(ll M)
{
  rep(i, M)
  {
    ll a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
}

double f(double x, double y) {
  return (100.0 * x)/(x+y);
}

int main()
{
  ll N, M, K; cin >> N >> M >> K;
  vector<pair<double,double>> AB, CD;
  rep(i,N) {
    double a, b; cin >> a >> b;
    AB.push_back({ a,b });
  }

  rep(i,M) {
    double a, b; cin >> a >> b;
    CD.push_back({ a, b });
  }

  //
  double lb = 0.0, ub = 1.0;
  while(ub - lb > 0.00000000000001) {
    double t = (lb+ub)/2;

    // t % 以上のものの個数
    ll x = 0;
    
    //ABに対して、t %を満たす際の余りの砂糖の量（a - b * t/(1-t)）を算出する。
    vector<double>V;
    rep(i,N) {
      double a, b;
      tie(a,b) = AB[i];

      V.push_back(a - (b * t/(1.0-t)) );
    }
    V.push_back(MINF_LL);
    V.push_back(INF_LL);

    sort(V.begin(),V.end());

    rep(i,M) {
      double c, d;
      tie(c,d) = CD[i];

      //t %を満たす際に足りない砂糖の量を算出。
      double s = (c - (d * t/(1.0-t)));

      ll no = 0, ok = V.size()-1;

      while(ok - no > 1) {
        ll m = (ok + no)/2;


        if(0 <= s + V[m]) {
          //足りている
          ok = m;
        } else {
          //足りない
          no = m;
        }
      }
      x += ((V.size()-1)-ok);
    }


    if(K <= x ) {
      lb = t;
    } else {
      ub = t;
    } 
  }

  outd(lb*100)

	return 0;
}