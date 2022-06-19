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


void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    deque<ll> A, rA, B, rB;
    rep(i,N) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    rep(i,M) {
        ll b;
        cin >> b;
        B.push_back(b);
    }

    ll ans = 0;
    ll cnt = 0;
    // Aを目一杯借りる
    while(A.size()  > 0 && K >= A.front()) {
        ll a = A.front(); A.pop_front();
        K = K - a;
        rA.push_front(a);
        cnt++;
    }

    //B
    while(B.size()  > 0 && K >= B.front()) {
        ll b = B.front(); B.pop_front();
        K = K - b;
        rB.push_front(b);
        cnt++;
    }

    ans = cnt;

    // AをやめながらBを借りれるまで借りる
    while(true) {
        if(rA.size() == 0) break;
        if(rB.size() == M) break;

        ll a = rA.front(); rA.pop_front();
        K = K + a;
        cnt --;

        while(B.size()  > 0 && K >= B.front()) {
            ll b = B.front(); B.pop_front();
            K = K - b;
            rB.push_front(b);
            cnt++;
        }
        ans = max(cnt, ans);
    }


    cout << ans << endl;


}


int main()
{
  solve();
	return 0;
}