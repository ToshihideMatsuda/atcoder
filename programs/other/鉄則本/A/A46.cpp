#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 300000 + 5

ll N;
vector<ll> X(159), Y(159), P(159);

ll randomLL(ll a, ll b) {
    return a + rand() % (b-a+1);
}

double getDistance(ll p, ll q) {
  return sqrt((X[q] - X[p]) * (X[q] - X[p]) + (Y[q] - Y[p]) * (Y[q] - Y[p]));
}

double getScore() {
  double score = 0;
  reps(i,1,N+2) {
    score += getDistance(P[i],P[i-1]);
  }
  return score;
}

void greedy() {
  set<ll> s;
  reps(i,2,N+1) s.insert(i);

  ll i = 1;
  ll pi  = 0;
  while(s.size() > 0) {
    P[pi++] = i;
    ll near = 0;
    ll d = INF_LL;

    for(auto p:s) if(p != i){
      ll dp2 = (X[i] - X[p]) * (X[i] - X[p]) + (Y[i] - Y[p]) * (Y[i] - Y[p]) ;
      if(dp2 < d) {
        d = dp2;
        near = p;
      }
    }
    i = near;
    s.erase(near);
  }
  P[pi++] = i;
  P[pi++] = 1;
}


void solve() {
  cin >> N;
  rep(i,N) cin >> X[i+1] >> Y[i+1];

  //山登り法
  greedy();
  double currentScore = getScore();

  rep(i,100000*15) {
    ll L = randomLL(1,N-1);
    ll R = randomLL(1,N-1);
    if(L > R) swap(L,R);

    //reverse関数は可変配列(vectorの場合push_backで作っているとめっちゃ遅くなる可能性あり) 
    reverse(P.begin()+L,P.begin()+R+1);

    double newScore = getScore();
    if(currentScore > newScore) {
      currentScore = newScore;
    } else {
      reverse(P.begin()+L,P.begin()+R+1);
    }
  }
  rep(i,N+1) cout << P[i] << endl;
}

int main()
{
  solve();
	return 0;
}