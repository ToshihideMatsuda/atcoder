#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

// Union-Findのfind関数（経路圧縮あり）
int find(map<int, int>& parent, int x) {
    if (parent.find(x) == parent.end()) {
        parent[x] = x;
    }
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    int Q;
    cin >> Q;
    vector<int> T(Q), G(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> T[i] >> G[i];
        --T[i]; // 0-indexedに調整
    }

    map<int, int> parent; // 座標の親を管理
    map<int, int> position_map; // 各高橋くんの現在位置
    set<int> occupied; // 占有されている座標
    long long total_movement = 0;

    // 初期位置の設定
    for (int i = 0; i < N; ++i) {
        int pos = X[i];
        position_map[i] = pos;
        occupied.insert(pos);
        parent[pos] = pos;
    }

    for (int i = 0; i < Q; ++i) {
        int t_i = T[i];
        int g_i = G[i];
        int current_pos = position_map[t_i];

        // 現在の位置を占有セットから削除
        occupied.erase(current_pos);
        parent.erase(current_pos);

        // 目的地が空いているか確認
        if (occupied.find(g_i) == occupied.end()) {
            position_map[t_i] = g_i;
            occupied.insert(g_i);
            parent[g_i] = find(parent, g_i + 1);
            total_movement += abs(current_pos - g_i);
        } else {
            // 衝突を解決
            int pos = g_i;
            vector<int> moved_positions;
            while (occupied.find(pos) != occupied.end()) {
                moved_positions.push_back(pos);
                pos = find(parent, pos + 1);
            }
            // 高橋くんを目的地またはその次の空いている場所に移動
            for (auto p : moved_positions) {
                parent[p] = pos;
            }
            position_map[t_i] = pos;
            occupied.insert(pos);
            parent[pos] = find(parent, pos + 1);
            total_movement += abs(current_pos - pos);
        }
    }

    cout << total_movement << endl;

    return 0;
}