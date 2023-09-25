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
    int N;
    cin >> N;

    vector<int> L(N);
    rep(i,N) cin >> L[i];

    int cnt = 0;
    rep(i,N-2) {
        reps(j,i+1,N-1) {
            reps(k,j+1,N) {
                if(L[i] == L[j] || L[j] == L[k] || L[k] == L[i]) continue;

                int m=0;
                int o1=0,o2=0;

                if(L[i] > L[j] && L[i] > L[k]) {
                    m=i; o1 =j; o2 = k;
                } else if(L[j] > L[i] && L[j] > L[k]) {
                    m=j; o1 =i; o2 = k;
                } else {
                    m=k; o1 =i; o2 = j;
                }

                if(L[m] < L[o1] + L[o2]) cnt ++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}