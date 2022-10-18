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

int N;
int x[MAX_N],y[MAX_N];

double distance(int i, int j) {
    int dx = x[i] - x[j];
    int dy = y[i] - y[j];
    return sqrt(dx*dx + dy*dy);
}

int main(){
    cin >> N;
    rep(i,N) {
        cin >> x[i] >> y[i];
    }

    double max =0.0;
    rep(i,N-1) {
        reps(j,1,N) {
            double l = distance(i,j);
            max = max < l ? l : max;
        }
    }

    cout << fixed;
    cout << setprecision(8) << max << endl;

    return 0;
}

