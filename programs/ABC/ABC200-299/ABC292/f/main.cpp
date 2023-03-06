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

double f(double l, double r, double B)
{
  return cos(l) - B * cos(M_PI / 6.0 - r);
}

void solve()
{
  double A, B;
  cin >> A >> B;
  if (B < A)
    swap(A, B);

  // A <= B

  double tmpA = A;
  B /= A;
  A = 1;

  double d =  M_PI / 6.0;
  const double limit = 1.0/cos(d);

  double ans = 0;
  if (limit <= B)
  {
    ans = limit * tmpA;
  }
  else
  {
    // 1 <= B <= limit
    double lb = 0.0, ub = (15.0 / 360.0) * M_PI * 2.0;
    double d = 1.0;
    rep(i, 15) d *= 1.0 / 10.0;
 
    double x = (lb + ub) / 2;
    double v = f(x, x, B);
    while (abs(v) >= d)
    {
      if (0 < v)
      {
        lb = x;
      }
      else
      {
        ub = x;
      }
      x = (lb + ub) / 2;
      v = f(x, x, B);
    }
    ans = tmpA * B / cos(x);
  }

  outd(ans);
}

int main()
{
  solve();
  return 0;
}