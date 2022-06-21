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

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}

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
    ll N, K;
    string S;
    cin >> N >> K >> S;
    auto SS = runLengthEncoding(S);

    ll ans = 0;
    ll tmp = 0;
    ll k = 0;
    queue<pair<string,ll> > Q;
    for(auto s : SS) {
        string str  = s.first; 
        ll cnt      = s.second;
        
        Q.push(s);
        if(str == "1") {
            tmp += cnt;
        } else {
            k++;
            tmp += cnt;
            if(k > K) {
                pair<string,ll> q;
                do {
                    q = Q.front(); Q.pop();
                    tmp -= q.second;
                    if(q.first == "0") break; 
                } while(true);
                k--;
            } 
        }

        ans = max(ans,tmp);

    }
    cout << ans << endl;


}


int main()
{
  solve();
	return 0;
}