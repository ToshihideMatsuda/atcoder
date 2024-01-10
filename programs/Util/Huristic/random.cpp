#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// a以上b以下の整数をランダムに生成する関数
ll randomLL(ll a, ll b) {
    return a + rand() % (b-a+1);
}
