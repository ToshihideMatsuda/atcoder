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
    #define MAX_N 2*  100000 + 5
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

vector<int> G[2000 + 5];
bool checked[2000 + 5];
bool ans[2000 + 5][2000 + 5];
ll a=0;

void dfs(int pos, int start) {
    checked[pos] = true;
    for(int p: G[pos]) {
        if(checked[p]) continue;
        if(ans[start][p]) continue;
        ans[start][p]=true;
        a++;
        dfs(p,start);
    }
}

void solve(){
    int N, M;
    cin >>  N >> M;

    rep(i,M) {
        int A, B;
        cin >> A >> B;
        A--;B--;
        G[A].push_back(B);
    }
    rep(i,N) {
        rep(j,2005) checked[j] = false;
        ans[i][i] = true;
        a++;
        dfs(i, i); 
    }
    cout << a << endl;
}



int main(){
    solve();
    return 0;
}

