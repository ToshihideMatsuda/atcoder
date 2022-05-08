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

#define MAX_N 2*1000000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}

//N以下の数について、素因数の数をcに登録
int prime[MAX_N];

void solve() {
    ll N;

    cin >> N;

	rep(i,MAX_N) prime[i] = 0;
	
	for(int i= 2; i < MAX_N; i++){
		if(prime[i]==0){
            ll cnt = 1;
			for(int j=i;j < MAX_N;j +=i){
				prime[j] +=cnt; 
                cnt ++;
			}
		}
	}

    ll cnt = 0;
    ll MAX = cbrt(N) + 2;
    reps(q, 2, MAX) { 
        if(prime[q] == 1) {
            for(ll p = 2;  p <= min(N/(q*q*q), q-1); p++) {
                if(prime[p] == 1) {
                    cnt ++;
                }
            }
        }
    }
    cout << cnt << endl;
}

int main()
{
    solve();
	return 0;
}