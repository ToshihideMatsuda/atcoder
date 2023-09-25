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

#define MAX_N 2*100000 + 5
#define INF 1 << 28

int main(){
    string S;
    cin >> S;

    int cnt = 0;
    rep(i,3) if(S[i] == 'R') cnt ++;
    if(cnt == 2) if(S[1] == 'S') cnt = 1;


    cout << cnt << endl;

    return 0;
}