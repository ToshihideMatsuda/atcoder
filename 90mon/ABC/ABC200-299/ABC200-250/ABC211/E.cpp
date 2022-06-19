#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define repmp(itr,mp)  for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 1000000000 + 7// 998244353

#define MAX_N 2 * 100000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}

vector<ll> G[MAX_N];
ll dist[MAX_N];
ll cnt[MAX_N];
ll N, M;


void solve() {
    rep(i,MAX_N) dist[i] = INF_LL;

    cin >> N >> M;

    rep(i,M) {
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<ll> Q;
    Q.push(1);
    dist[1] = 0;
    cnt[1] = 1;

    while(Q.size() > 0) {
        ll q = Q.front(); Q.pop();
        for(auto g : G[q]) {
            if(dist[g] == INF_LL) {
                dist[g] = dist[q] + 1;
                cnt[g] = cnt[q];
                Q.push(g);
            } else if (dist[g] == dist[q] + 1) {
                cnt[g] += cnt[q];
                cnt[g] %= MOD;
            }
        }
    }

    cout << cnt[N] << endl;

}

int main()
{
    solve();
	return 0;
}