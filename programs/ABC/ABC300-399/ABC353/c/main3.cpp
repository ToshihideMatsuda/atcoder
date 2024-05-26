#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 100000000;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 配列をソート
    sort(A.begin(), A.end());

    // 後続要素との和を計算するための変数
    long long suffix_sum = 0;
    for (int i = 0; i < N; i++) {
        suffix_sum += A[i];
        if (suffix_sum >= MOD) {
            suffix_sum -= MOD;
        }
    }

    long long result = 0;
    for (int i = 0; i < N; i++) {
        suffix_sum -= A[i];
        if (suffix_sum < 0) {
            suffix_sum += MOD;
        }
        result += A[i] * (N - 1 - i) % MOD;  // 同じ値が繰り返される回数
        result %= MOD;
        result += suffix_sum;  // 残りの値との和
    }

    cout << result << endl;

    return 0;
}
