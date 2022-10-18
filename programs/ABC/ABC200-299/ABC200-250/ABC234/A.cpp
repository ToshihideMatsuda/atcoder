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

int t;

int f(int t){
    return t*t + 2 * t + 3; 
}


int main(){
    cin >> t;

    cout << f(f(f(t)+t)+f(f(t))) << endl;

    return 0;
}

