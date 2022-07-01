#include <bits/stdc++.h> 
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

ll get10Keta(ll N) {
  ll k = 0;
  ll tmp = N; 
  while(tmp > 0) {
    tmp /= 10;
    k++;
  }
  return k;
}

ll getTen(ll N) {
  ll ten = 1; 
  while(N > 0) {
    ten *= 10;
    N--;
  }
  return ten;
}

vector<ll> factor[19];
void solve() {
  reps(i,2,19) for(int j = i-1; j >= 1; j--) if(i%j == 0) factor[i].push_back(j);

  ll T;
  cin >> T;
  //ll a;
  //cin >> a;
  //T = 1000;
  rep(_,T) {
    ll N;
    cin >> N;
    ll k = get10Keta(N);

    if(k == 2) { // 2桁
      ll a = N / 10;
      if(a + a*10 <= N) {
        cout << a + a*10 << endl;
      } else {
        cout << a -1 + (a-1)*10 << endl;
      }
      goto next;
    }
    else {
      ll ans = getTen(k-1) -1; 
      if(factor[k].size() > 0 ){
        for(auto f : factor[k]) {
          ll ten = getTen(k - f);
          rep(i,2) {
            ll start = N/ten - i;
            ll val = 0;
            rep(i, k/f) {
              ll ten = getTen(i * f);
              ll add = start * ten;
              val += add;
            }

            if(val <= N) {
              ans = max(ans,val);
            }
          }
        }
      }
      
      cout << ans << endl;
    }




    next: 
    continue;
  }


}


int main()
{
  solve();
	return 0;
}