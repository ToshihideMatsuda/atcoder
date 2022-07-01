#include <iostream>

#define MAX_N 100
#define MAX_W 100000

using namespace std;

int dp[MAX_N + 1];
int main () {
    memset(dp,dp + MAX_N,-2);

    cout << dp[3];
}

