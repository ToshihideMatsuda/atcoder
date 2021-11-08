#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
int T[2*100000 + 1];
bool checked[2*100000 + 1];
vector<int> G[2*100000 + 1];


int main() {
    cin >> N;

    for (int i = 1; i < N+1; i++)
    {
        int K;
        cin >> T[i] >> K;
        for(int j = 0; j < K; j ++) {
            int A;
            cin >> A;
            G[i].push_back(A); // T[i] -> Aの有効グラフ
        }
    }

    long long time =0;
    queue<int> Q;
    Q.push(N);

    while(Q.size() > 0) {

        int to = Q.front(); Q.pop();
        if(checked[to] == true)
            continue;

        checked[to] = true;
        time += T[to];

        for(auto next :G[to]) {
            Q.push(next);
        }
    }

    
    cout << time;


    return 0;
}