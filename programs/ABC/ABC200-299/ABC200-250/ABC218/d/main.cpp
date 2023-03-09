#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>


#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 


typedef long long ll;
using namespace std;

#define MAX_N 2000 + 5
#define INF 1 << 28

int N,x,y;
vector<pair<int,int>> p;
map<pair<int,int>,int> mp[MAX_N]; // mp[i][{x,y}]=j : 点 i -> 点j のベクトルが(x,y)


int main(){
    cin >> N;

    rep(i,N){ 
        cin >> x >> y;
        p.push_back({x,y});
    }

    rep(i,N-1) {
        reps(j,i+1,N){
            auto x1 = p[i].first, y1 = p[i].second;
            auto x2 = p[j].first, y2 = p[j].second;

            if(x1 == x2 || y1 == y2) { // x軸y軸と並行なものしか記録しない
                mp[i][{x1 - x2, y1 - y2}] = j;
                mp[j][{x2 - x1, y2 - y1}] = i;
            }
        }
    }

    ll cnt = 0;
    rep(i,N) {
        int x1,y1,x2,y2;
        for(auto [v1, j] :mp[i]) {      // 点i -> 点j のベクトルがv1=(x1,y1)
            tie(x1, y1) = v1; 
            for(auto [v2 ,k] :mp[j]) {  // 点j -> 点k のベクトルがv2=(x2,y2)
                tie(x2, y2) = v2;

                if( x1*x2 + y1*y2 == 0) {           // v1とv2は直行ベクトル
                    if( mp[k].count({-x1, -y1}) ){   // 点kからのベクトルに -v1が存在
                        auto m = mp[k][{-x1, -y1}];
                        if(mp[m].count({-x2, -y2}) ){ // 点mからのベクトルに -mが存在 
                            cnt ++;
                        }
                    }
                }
            }
        }
    }

    cout << cnt/8 << endl;




    return 0;
}

