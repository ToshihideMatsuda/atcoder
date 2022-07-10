#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5

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

void Yes() {
    cout << "Yes" << endl;
    exit(0);
}

void No() {
    cout << "No" << endl;
    exit(0);
}

void solve() {
    string S, T;
    cin >> S >> T;

    auto eS = runLengthEncoding(S);
    auto eT = runLengthEncoding(T);

    if(eS.size() == eT.size()) {
        rep(i,eS.size()) {
            if(eS[i].first != eT[i].first) No();
            if(eS[i].second > eT[i].second) No();
            if(eS[i].second == eT[i].second) continue;
            if(eS[i].second <  eT[i].second && 2<= eS[i].second) continue;
            No();
        }
        Yes();
    }
    No();
}


int main()
{
  solve();
	return 0;
}