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

// 素因数分解関数
// f[n]= [ {p1,e1}, {p2,e2}, ..., {pm,em} ] : n = p1^e1 * p2^e2 * ... * pm^em
// f[n][p1] = e1, f[n][p2] = e2, ..., f[n][pm] = em
unordered_map<ll,ll> f[MAX_N];
void factorial(ll N) {
    reps(i, 2, N+1) {
        if(f[i].size() == 0) {
            for(int j = i; j < N+ 1; j+= i) {
                ll tmp = j;
                ll cnt = 0;
                while(tmp % i == 0) {
                    tmp = tmp / i;
                    cnt ++;
                }
                f[j][i] = cnt;
            }
        }
    }
}

vector<ll> twice;


void solve() {
    ll N; cin >> N;
    factorial(N);
    reps(i,1,N+1) {
        if(i*i > N) break;
        twice.push_back(i*i);
    }

    ll ans = 0;

    reps(i,1,N+1) {
        ll j = 1;
        ll p,e;
        for(auto ff : f[i]) {
            ll p = ff.first;
            ll e = ff.second;

            if(e%2==1) {
                j *= p;
            }
        }

        for(auto t : twice)
            if(j * t <= N) {
                //cout << "(" << i << "," << j*t <<")" << endl;
                ans++;
            }
    }
    cout << ans << endl;


}


int main()
{
  solve();
	return 0;
}