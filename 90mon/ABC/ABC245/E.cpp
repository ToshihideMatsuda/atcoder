#include <bits/stdc++.h> 

using namespace std;

#define debug false

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 



#define INF ((1 << 30) + (1 << 29) + (1 << 28) ) 
#define MINF (1 << 31)
#define INF_LL ((1LL << 60) + (1LL << 59) + (1LL << 58) )
#define MINF_LL (1LL << 63)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 1500 + 5
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
pair <int,int> A, B;
char P[MAX_N][MAX_N];
int  D[MAX_N][MAX_N];


void solve(){

    cin >> N;
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;

    
    rep(i, N+2) rep(j, N+2) P[i][j] = '#';
    rep(i, N+2) rep(j, N+2) D[i][j] = -1;

    reps(i, 1, N+1) {
        string s;
        cin >> s;
        reps(j, 1, N+1)  P[i][j] = s[j-1];
    }

    queue<pair<int,int>> Q;
    Q.push(A);
    auto [ax, ay] = A;
    D[ax][ay] = 0;

    while(Q.size() > 0) {
        auto [x, y] = Q.front(); Q.pop();

        vector<int> dx = {1,1,-1,-1};
        vector<int> dy = {1,-1,1,-1};
        int d = D[x][y] + 1;
        rep(i,4) {
            int ddx = dx[i], ddy = dy[i];
            while(P[x+ddx][y+ddy] == '.') {
                if(D[x+ddx][y+ddy] != -1 && D[x+ddx][y+ddy] < d) {
                    break;
                }

                D[x+ddx][y+ddy] = d;
                Q.push({x+ddx, y+ddy});
                ddx += dx[i];
                ddy += dy[i];
            }
        }
    }

    cout << D[B.first][B.second] << endl;

}

int main(){
    solve();
    return 0;
}

