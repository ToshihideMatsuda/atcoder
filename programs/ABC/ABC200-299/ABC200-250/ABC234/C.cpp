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

#define MAX_N 100 + 5
#define INF 1 << 28

ll K;

string binary(ll K){
    string ans = "";
    for (int i = 0; K>0 ; i++)
    {
        ans = to_string((K%2)*2) + ans;
        K = K/2;
    }
    return ans;
}

int main(){
    cin >> K;
    cout << binary(K) << endl;
    return 0;
}