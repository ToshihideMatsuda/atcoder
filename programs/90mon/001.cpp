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


ll N, L, K;
vector<ll> A; //A[0] = 0, A[1] = a1, ... , A[N] = an, A[N+1] = L; 切れ目の地点
vector<ll> B; //羊羹の長さ

void solve(){
    cin >> N >> L >> K;
    A.resize(N+2);

    A[0] = 0; A[N+1] = L;
    reps(i,1,N+1) cin >> A[i]; 

    reps(i,1,N+2) {
        B.push_back(A[i] - A[i -1]);
    } 


    ll low = 1, up = INF; //解は [low, up)に含まれる

    while(up - low > 1) {
        ll mid = (low + up)/2;

        bool ok = false;
        ll len = 0;
        ll cnt = 0;
        rep(i,B.size()) {
            len += B[i];
            if(len >= mid) {
                cnt ++;
                len = 0;
            }

            if(cnt >= K + 1) ok = true; //分割できた
            
        }

        if(ok) {
            //midで分割できた
            low = mid;
        } else {
            //midでは分割できなかった
            up = mid;
        }
    }

    cout << low << endl;

}


int main(){
    solve();
    return 0;
}

