#include <bits/stdc++.h> 
#include <unordered_map>
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
#define out(s) cout << (s) << endl;
#define out2(s) cout << (s);

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {

  // case 1: (sx, sy), (x, y) -> ( x + (x-sx), y + (y-sy)  ) = (2x-sx,2y-sy) = (2*(x-sx) + sx, 2*(y-tx) + tx)
  // case 2: (sx, sy), (x1, y1), (x2, y2)  -> ( 2*x2 - (2*x1 - sx),   2*y2 - (2*y1 - sx)  ) = ( 2*(x2-x1) + sx, 2*(y2-y1) + tx)

  ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
  ll a, b, c, d; cin >> a >> b >> c >> d;

  ll dx = tx - sx;
  ll dy = ty - sy;
  if(dx % 2 == 1 || dy % 2 == 1){
    out("No")
    return;
  } else if(dx != 0 && a == b) {
    out("No")
    return;
  } else if(dy != 0 && c == d) {
    out("No")
    return;
  }

  { //case2
  dx /= 2;
  dy /= 2;

  ll cnt = 0;

  vector<string> ans;
  while(dx != 0  || dy != 0) {
    ll x1 = dx > 0 ? a : b;
    ll y1 = dy > 0 ? c : d;
    string s = to_string(x1) + " " + to_string(y1);
    ans.push_back(s);

    ll x2 = 0, y2 = 0;
    if(dx == 0) { x2 = x1; } 
    else if(abs(dx) <= b-a){
      x2 = dx > 0 ? a + abs(dx) : b - abs(dx);
      dx = 0;
    } else {     
      x2 = dx > 0 ? b : a;
      dx = dx > 0 ? dx - (b-a) : dx + (b-a);
    }

    if(dy == 0) { y2 = y1; } 
    else if(abs(dy) <= d-c){
      y2 = dy > 0 ? c + abs(dy) : d - abs(dy);
      dy = 0;
    } else {     
      y2 = dy > 0 ? d : c;
      dy = dy > 0 ? dy - (d-c) : dy + (d-c);
    }
    s = to_string(x2) + " " + to_string(y2);
    ans.push_back(s);
    if(ans.size() > 1000000) {
      break;
    }
  }

  

  if(ans.size() <= 1000000) {
    out("Yes")
    rep(i,ans.size()) out(ans[i])
    return;
  }
  }


//ここまで来ていない
/*

  { //case1
  exit(-1);
  dx = tx + sx;
  dy = ty + sy;

  dx /= 2;
  dy /= 2;

  vector<string> ans;

  ll x = 0;
  if(a <= dx && b <= dx) { x = dx; } 
  else if(b < dx){
    x = b;
  } else { // dx < a
    x = a;
  }
  ll y = 0;
  if(c <= dy && d <= dy) { y = dx; } 
  else if(b < dy){
    y = d;
  } else { // dx < a
    y = c;
  }

  dx = dx - x;
  dy = dy - y;

  string s = to_string(x) + " " + to_string(y);
  ans.push_back(s);

  while(dx != 0  || dy != 0) {
    ll x1 = dx > 0 ? a : b;
    ll y1 = dy > 0 ? c : d;
    string s = to_string(x1) + " " + to_string(y1);
    ans.push_back(s);

    ll x2 = 0, y2 = 0;
    if(dx == 0) { x2 = x1; } 
    else if(abs(dx) <= b-a){
      x2 = dx > 0 ? a + abs(dx) : b - abs(dx);
      dx = 0;
    } else {     
      x2 = dx > 0 ? b : a;
      dx = dx > 0 ? dx - (b-a) : dx + (b-a);
    }

    if(dy == 0) { y2 = y1; } 
    else if(abs(dy) <= d-c){
      y2 = dy > 0 ? c + abs(dy) : d - abs(dy);
      dy = 0;
    } else {     
      y2 = dy > 0 ? d : c;
      dy = dy > 0 ? dy - (d-c) : dy + (d-c);
    }
    s = to_string(x2) + " " + to_string(y2);
    ans.push_back(s);
    if(ans.size() > 1000000) {
      break;
    }
  }

  if(ans.size() <= 1000000) {
    out("Yes")
    rep(i,ans.size()) out(ans[i])
    return;
  }

  }

    out("No")
*/
}


int main()
{
  solve();
	return 0;
}