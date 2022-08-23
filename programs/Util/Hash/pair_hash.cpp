#include <bits/stdc++.h> 
typedef long long ll;
using namespace std;


// unordered_mapにてhashを使用するための方法方法
// unordered_map<pair<ll,ll>,ll, pair_hash_ll> dp[301]; // dp[n][x][y] = n回目で(x,y)にいる通り数
struct pair_hash_ll
{
    size_t operator() (const pair<ll, ll> &pair) const {
        return hash<ll>()(pair.first) + hash<ll>()(pair.second) * 99824354423518553;
    }
};

struct pair_hash_string
{
    size_t operator() (const pair<string, string> &pair) const {
        return hash<string>()(pair.first) ^ hash<string>()(pair.second);
    }
};
