#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define out(s)  cout << s << endl;
int main()
{
  ll x; cin >> x;

  ll ans = (x / 11) * 2;
  x %= 11;

  if(x == 0) {}
  else if(x <= 6) ans += 1;
  else ans += 2;

  out(ans)

	return 0;
}