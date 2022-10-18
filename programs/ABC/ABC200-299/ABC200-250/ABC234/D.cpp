#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>
#include <iomanip>


#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 


typedef long long ll;
using namespace std;

#define MAX_N 5*100000 + 5
#define INF 1 << 28


int N, K, p;
priority_queue<int, vector<int>,greater<int>> P;



int main(){
    cin >> N >> K;

    rep(i,K)  {
        cin >> p;
        P.push(p);
    }

    cout << P.top() << endl;
    rep(i,N-K) {
        cin >> p;
        if(P.top() < p) { 
            P.push(p);
            P.pop();
        }
        cout << P.top() << endl;
    }
    


    return 0;
}