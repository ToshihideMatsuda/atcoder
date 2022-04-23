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

vector<int> A;
int N;


void solve(){
    ll N, K, X;
    cin >> N >> K >> X;

    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<ll> modA(N), divA(N);
    ll sumA = 0, divSumA =0;
    rep(i,N) {
        modA[i] = A[i] % X;
        divA[i] = A[i] / X;
        divSumA += divA[i];
        sumA +=  A[i];
    }

    ll ans = 0;
    if(K < divSumA) { // 何も考えずに充当
        ans = sumA - X * K;
    } else { // 優先度を考えて充当
        ans = sumA - X * divSumA;
        K = K - divSumA;

        sort(modA.begin(),modA.end(),greater<int>());

        int idx =0;

        while(K > 0 && idx < N) {
            ans = ans - modA[idx++];
            K--;
        }
    }

    cout << ans << endl;
}



int main(){
    solve();
    return 0;
}

