#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;

#define MAX_N  2*100000 + 10
int N;
int a[100000 +1], b[100000 +1];

int G[100000 +1];

int main(){
    cin >> N;

    int center = 0;
    for( int i = 1; i < N; i ++) {
        cin >> a[i] >> b[i];
        G[a[i]] += 1;
        G[b[i]] += 1;
        
        if(G[a[i]] > 1) {
            center = a[i];
        }
        else if( G[b[i]] > 1)
        {
            center = b[i];
        }
    }

    bool star = true;
    for(int i = 1; i <= N; i ++) {
        if(i == center) {
            if(G[center] != N-1){
                cout << "No";
                return 0;
            }
        }
        else {
            if(G[i] != 1) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";



    return 0;
}
