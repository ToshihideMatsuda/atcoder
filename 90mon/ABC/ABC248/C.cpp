/*
#include <bits/stdc++.h> 

using namespace std;

#define debug false

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 



#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 10000 + 5
#endif

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}
void UNSOLVABLE() {
  cout << "UNSOLVABLE" << endl;
}

void solve(){
  ll N, Q;
  cin >> N;
  ll A[N];
  vector<pair<ll,ll>> mp[N + 5];
  rep(i,N) {
    cin >> A[i];
    int s = mp[A[i]].size();
    mp[A[i]].push_back({i, s+1} );
  }
  rep(i,N) {
    int s = mp[i].size();
    mp[i].push_back({i, s+1} );
  }

  cin >> Q;

  rep(_,Q) {
    ll L,R,X;
    cin >> L >> R >> X;

    pair<ll,ll> l = {L,0LL}, r = {R,0LL};
    auto itL = lower_bound(mp[X].begin(), mp[X].end(), l) ;
    auto itR = lower_bound(mp[X].begin(), mp[X].end(), r) ;

    ll sR =  (*itR).second;
    ll sL =  (*itL).second;
    cout << sR - sL << endl;
    
  }
}



int main(){
    solve();
    return 0;
}

*/


#include <iostream>
#include <vector>
#include <map>
#include <cstdint>

template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};

using namespace std;

#define debug false

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 



#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 10000 + 5
#endif

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}
void UNSOLVABLE() {
  cout << "UNSOLVABLE" << endl;
}

ll dp[55][55 * 55];

void solve(){
  ll N, M, K;
  cin >> N >> M >> K;

  dp[0][0] = 1;
  rep(i,N) {
    reps(k, 1, K + 1) {
      ll sum = 0;
      reps(m, 1, M+1) {
        if(k - m >= 0) {
          sum += dp[i][k - m];
          sum %= MOD;
        }
      }

      dp[i+1][k] = sum;
      dp[i+1][k] %= MOD;
    }
  }

  ll ans = 0;

  reps(k,0,K+1) {
    ans += dp[N][k];
    ans = ans % MOD;
  }

  cout << ans << endl;
}



int main(){
    solve();
    return 0;
}

