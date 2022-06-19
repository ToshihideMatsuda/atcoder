#include <bits/stdc++.h> 
#include <unordered_map> 
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}


void solve(){
  ll N, K;
  cin >> N >> K ;
  vector<pair<ll,ll>> ty;

  ty.push_back({1,0});
  rep(i,N) {
      ll t, y;
      cin >> t >> y;
      ty.push_back({t,y});
  }

  priority_queue<ll,vector<ll>,less<ll> > S; // 飛ばす加算演算
  ll T = 0;   // 値
  ll ans = MINF_LL; // max(T)
  ll cap = K; // Sの上限要素数（代入演算ごとに減っていく）
  ll num = 0;
  ll prev = 0;

  for(auto itr = ty.rbegin(); itr != ty.rend(); itr++) {
    ll t = (*itr).first;
    ll y = (*itr).second;

    if(t == 1) { //insert
        cap = K - num;

        if(S.size() > cap) {
            //cap超え
            ll add = S.top(); S.pop();
            T += add;
        }

        num++;
        if(cap < 0) break;
        T = T - prev + y;
        prev = y;
        ans = max(ans,T);
    } else { // add
        if(y >= 0) {
            T += y;
        } else {
            S.push(y);
            if(S.size() > cap) {
                //cap超え
                ll add = S.top(); S.pop();
                T += add;
            }
        }
    }
  }
  cout << ans << endl;



}


int main()
{
  solve();
	return 0;
}

