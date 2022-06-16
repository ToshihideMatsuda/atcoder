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

//aとbの最大公約数を計算
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}


void solve() {
    ll N, A, B;
    cin >> N >> A >> B;

    // under N sum
    ll sum = N * (N + 1) / 2;

    // under A
    ll ANum = N / A;
    ll Asum = (A * ANum) * (ANum + 1) / 2 ;

    // under B
    ll BNum = N / B;
    ll Bsum = (B * BNum) * (BNum + 1) / 2 ;

    // under AB
    ll ABNum = N / ((A * B)/gcd(A,B));
    ll ABsum = (((A * B)/gcd(A,B)) *  ABNum) * (ABNum +1) / 2;

    ll ans = sum - Asum - Bsum + ABsum;

    cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}