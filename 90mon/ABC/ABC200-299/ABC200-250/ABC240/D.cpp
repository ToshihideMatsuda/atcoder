#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <numeric>

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

stack<tuple<int,int,int>> T; // ボールの種類、種類連続数、総ボール数

void solve(){
    int N;
    cin >> N;
    T.push({-1,0,0});
    rep(i,N) {
        int a;
        cin >> a;
        if(T.size() == 1){
            T.push({a,1,1});
        }
        else {
            int x, cnt, all;
            tie(x, cnt, all) = T.top();


            if(x == a) {
                if(cnt + 1 == a) {
                    //消える
                    T.pop();
                }
                else {
                    //追加
                    get<1>(T.top())++;
                    get<2>(T.top())++;
                }
            } else {
                //追加
                T.push({a,1,all+1});
            }
        }
        cout << get<2>(T.top()) << endl;
    }
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
