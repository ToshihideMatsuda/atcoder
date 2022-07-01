#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>
#include <queue>;
using namespace std;

#define MAX_N  2*100000 + 10
int N, Q;

int main(){
    cin >> N >> Q;
    
    int G[N+1];
    int H[N+1];
    for( int i = 0; i <= N; i ++) {
        G[i] =0;
        H[i] =0;
    }
    
    
    for( int i = 1; i <= Q; i ++) {
        int query;
        cin >> query;
        if(query == 1){
            int x, y;
            cin >> x >> y;
            G[y] = x;
            H[x] = y;
            
        }else if(query == 2) {
            int x, y;
            cin >> x >> y;
            G[y] = 0;
            H[x] = 0;
        }else if(query == 3) {
            int x;
            cin >> x;
            
            int top = x;
            while(G[top] > 0) {
                top = G[top];
            }
            
            vector<int> A;
            int to = top;
            while(to > 0) {
                A.push_back(to);
                to =H[to];
            }
            cout << A.size() << " ";
            for(auto i : A){
                cout << i << " ";
            }
            cout << endl;
        }
    }


    return 0;
}
