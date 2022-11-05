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

#define MAX_N 2*100000+5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

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

template<typename T>
struct BIT {

private:
  ll N;
  vector<T> bit;

public:
  BIT(ll N) : N(N), bit(N+1) {}

private:
  T queryFromZero(ll i) {
    T sum = 0;
    while(i > 0) {
      sum += bit[i];
      i -= i & -i;
    }
    return sum;
  }

public:
/*
   bit[i] = +v 及びその上位にvを加算する
*/
  void add(ll i, T v) {
    while(i <= N) {
      bit[i] += v;
      i += i & -i;
    }
  }

/*
  bit[i]...bit[j]の和
*/
  T query(ll i, ll j) {
    return queryFromZero(j) - queryFromZero(i-1);
  }
  
// bit[i]
  T query(ll i) {
    return bit[i];
  }
};



void solve() {
  ll N; cin >> N;
  vector<ll> A(N+1); rep(i,N) cin >> A[i+1];
  vector<modint<MOD>> ans(N+1); ans[1] = A[1];

  BIT<ll> sum(MAX_N);
  BIT<ll> cnt(MAX_N);

  sum.add(A[1],A[1]);
  cnt.add(A[1],1);

  reps(i,2,N+1){
    modint<MOD> nx = ans[i-1] * (i-1) * (i-1);
    nx += 2*cnt.query(1,A[i]-1)*A[i] + A[i];
    nx += 2*sum.query(A[i],MAX_N);
    nx /= i*i;

    sum.add(A[i], A[i]);
    cnt.add(A[i], 1);
    ans[i] = nx;
  }
  
  reps(i,1,N+1) cout << ans[i].a << endl;
}


int main()
{
  solve();
	return 0;
}