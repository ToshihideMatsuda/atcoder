#include <bits/stdc++.h> 

using namespace std;

#define debug false

#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 


typedef long long ll;

#define INF 1 << 28
#define MINF -1*(1 << 28)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 100000 + 5
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

int N;
int C[MAX_N];
vector<int> G[MAX_N];

unordered_map<int,int> mp;
vector<int> good;

void dfs(int v, int bf) {
    if(mp[C[v]] == 0) {
        good.push_back(v);
    }
    mp[C[v]] ++;
    for(int u : G[v]) {
        if(u == bf) {
            // 親の場合には何もしない
            continue;
        }
        dfs(u, v);
    }
    mp[C[v]] --;
}

void solve(){
    cin >> N;
    rep(i,N) cin >> C[i];
    rep(i,N-1) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);

    sort(good.begin(),good.end());

    for(int g : good) cout << g + 1 << endl;

}


int main(){

#if debug == true
    while(true){
        cout << "---debugMode---" << endl;
#endif
        solve();
        cout << endl;
#if debug == true
    }
#endif

    return 0;
}

