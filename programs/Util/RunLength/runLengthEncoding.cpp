#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 

// "aabbbbaaca" -> [("a",2),("b",4),("a",2),("c",1),("a",1)]
vector<pair<string,ll> > runLengthEncoding(string S) {
    vector<pair<string,ll> > ret;
    ll i = 0;
    while(i < S.size()) {
        ll cnt = 1;
        while(i+1 < S.size() && S[i] == S[i+1]) {
            cnt++;
            i++;
        }
        ret.push_back(make_pair(S.substr(i,1),cnt));
        i++;
    }
    return ret;
}

// [("a",2),("b",4),("a",2),("c",1),("a",1)] -> "aabbbbaaca"
string runLengthDecoding(vector<pair<string,ll> >S) {
    string ret;
    for(auto p : S) {
        rep(i,p.second) ret += p.first;
    }
    return ret;
}

// "aabbbbaaca" ->  a2b4a2c1a1
string runLengthEncodeToString(string S) {
    string ret;
    ll i = 0;
    while(i < S.size()) {
        ll cnt = 1;
        while(i+1 < S.size() && S[i] == S[i+1]) {
            cnt++;
            i++;
        }
        string ch = S.substr(i,1);
        ret += ch + to_string(cnt);
        i++;
    }
    return ret;
}