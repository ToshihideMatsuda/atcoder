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



void solve() {
  ll H, W, A, B; cin >> H >> W >> A >> B;

  ll ans = 0;
  for(int i = 0; i < (1<<H*W); i++) {

    vector<vector<int>> room;
    int cnt = 0;
    rep(h,H){
      vector<int> line ;
      rep(w,W) line.push_back(0);
      line.push_back(1);
      room.push_back(line);
    }

    vector<int> line ;
    rep(w,W+1) line.push_back(1);
    room.push_back(line);

    if(i == 4095) {
      i = 4095;
    } 
    rep(b,H*W) 
    if( (i & (1 << b))  > 0 ){
      if(H == 1) {
        room[0][b] = 1;
      } else if(W == 1) {
        room[b][0] = 1;
      } else {
        room[b/W][b%W] = 1;
      }
      cnt++;
    }

    if(cnt != B) continue;

    queue<vector<vector<int>>> Q;
    Q.push(room);

    while(Q.size() > 0){
      vector<vector<int>> room =Q.front();Q.pop();

      rep(h,H) rep(w,W) if(room[h][w] == 0) {
        //横
        if(room[h][w+1] == 0) {
          vector<vector<int>> room2(room);
          room2[h][w] = 1; room2[h][w+1] =1;
          Q.push(room2);
        } 

        //縦　
        if(room[h+1][w] == 0) {
          room[h][w] = 1; room[h+1][w] =1;
          Q.push(room);
        }
        goto nextA;
      }

      //穴なし（密）
      ans ++;

      nextA:
      continue;
    }
  }

  cout << ans << endl;
}


int main()
{
  solve();
	return 0;
}