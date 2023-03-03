#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>

#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out(s) cout << s << endl;
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)

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


void solve() {
    ll N, K; cin >> N >> K;
    string S; cin >> S;

    ll x = 0;
    rep(i,N) if(S[i] == 'X') x++;

    if(x < K) {
        K = N-K;
        x = N-x;
        string T;
        rep(i,N) if(S[i] == 'X') T.push_back('Y'); else T.push_back('X');
        S = T;
    }

    if(x == N) {
        if(K <= 1) {
            out(0)
        } else {
            out(K-1)
        }
        return;
    } 

    auto enc = runLengthEncoding(S);

    vector<ll> Xs;
    vector<ll> XsFC;
    vector<ll> Ys;
    rep(i,enc.size()) {
        auto e = enc[i];
        if(i == 0 || i == enc.size() - 1){
            if(e.first == "X") {
                XsFC.push_back(e.second);
                continue;
            }
        }

        if(e.first == "X") Xs.push_back(e.second);
        else Ys.push_back(e.second);
    }

    ll ans = 0;
    for(auto ys : Ys) ans += ys -1;

    sort(Xs.begin(),Xs.end());
    
    for(auto xs : Xs) {
        if(xs <= K) {
            K -= xs;
            ans += xs + 1;
        } else {
            ans += K;
            K = 0;
            break;
        }
    }

    if(K > 0) {
        ans += K;
    }

    out(ans)



}


int main()
{
  solve();
	return 0;
}
