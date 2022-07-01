#include <bits/stdc++.h> 

using namespace std;

#define debug false

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 



#define INF ((1 << 31) - 1)
#define MINF (1 << 31)
#define INF_LL ((1LL << 63) - 1)
#define MINF_LL (1LL << 63)
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
    ll N;
    cin >> N;

    if(N == 0){
        cout << 0 << endl;
        return;
    }

    // 上解を求める
    ll R3 = ceil(cbrt(N));
    ll X = INF_LL;

    rep(b, R3+1) {
        ll ra = 0, la = R3+1; 
        while(la - ra > 1) {
            ll a = (ra + la) / 2;
            ll ch = (a+b)*(a*a+b*b);
 
            if(N < ch) {
                la = a;
                X  = min(X,ch);
            } 
            else if(N == ch)
            {
                cout << N << endl;
                return;
            }
            else if(ch < N) {
                ra = a;
            } 
        }
    }


    cout << X << endl;
}

int main(){
    solve();
    return 0;
}

