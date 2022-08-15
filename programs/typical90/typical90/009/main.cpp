#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5

double f(double s) {
  while(360 <= s) s -= 360;
  if(180 < s && s < 360) return 360 - s;
  else return s;
}

void solve() {
  ll N; cin >> N;
  // r =  sqrt(X*X + Y*Y), sinθ = y/r, θ = asin(y/r)
  vector<double> X(N), Y(N);
  rep(i,N) cin >> X[i] >> Y[i];
  
  double ans = 0;
  rep(i,N) {    
    vector<double> S; // S[i] = θ   0 <= θ <= 360
    S.push_back(MINF_LL);
    rep(j,N) if(i!=j){
      //偏角を求めるロジック
      double dx = X[j] - X[i];
      double dy = Y[j] - Y[i];
      double r = sqrt(dx*dx + dy*dy);
      //偏角を求めている
      double s = dy >= 0 ? (acos(dx/r) * 180.0/M_PI) : 360 - (acos(dx/r) * 180.0/M_PI) ;
      S.push_back(s); // -pi <= asin <= pi, 
    }
    sort(S.begin(),S.end());

    S[0] = S[S.size()-1]- 360.0; // 最大値のマイナス表現
    S.push_back(S[1] + 360.0);   // 最小値の360over

    reps(j,1,S.size()-1) {
      double s = S[j];
      double t  =  s <= 180.0 ? s + 180.0 : s - 180.0;
      auto idx = lower_bound(S.begin(),S.end(),t);
      double v0 = *idx, v1 = *(--idx);
      ans = MAX3(ans, f(abs(s - v0)), f(abs(s - v1)) );
    }
  } 

  cout << setprecision(15) << ans << endl;


}


int main()
{
  solve();
	return 0;
}