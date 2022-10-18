#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>


#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 


typedef long long ll;
using namespace std;

#define MAX_N 5*100000 + 5
#define INF 1 << 28


ll X;

set<ll> all;
vector<ll> allv;


int main(){
    cin >> X;

    reps(i,1,10) {          // 初項が[1,9]
        reps(j,-9,9) {      // 項差が[-9,8]
            reps(k,1,19) {  // 長さが[1,18]
                //最終項が[0,9]に入ること
                int d_last = i + j*(k-1);
                if(0 <= d_last & d_last <=9 ){
                    int cur=i;
                    string tousaSuu = to_string(cur);
                    rep(m,k-1) {
                        cur += j ;
                        tousaSuu = tousaSuu + to_string(cur);
                    }
                    all.insert(stoll(tousaSuu));
                }
            }
        }
    }

    for(auto e : all) {
        allv.push_back(e);
    }


    sort(allv.begin(),allv.end());

    if(binary_search(allv.begin(),allv.end(),X)) {
        cout << *lower_bound(allv.begin(),allv.end(),X) << endl;
    }
    else {
        cout << *upper_bound(allv.begin(),allv.end(),X) << endl;
    }



    return 0;
}