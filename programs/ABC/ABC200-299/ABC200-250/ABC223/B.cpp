#include <bits/stdc++.h> 
#include <unordered_map>
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

#define MAX_N 2*1000000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}


void solve() {
    string S;
    cin >> S;

    vector<string> s;

    ll L = S.size();
    rep(_, L) {
        s.push_back(S);

        string T;
        T = T + S[L-1];
        rep(i, L-1) T = T + S[i];

        S = T;
    }


    sort(s.begin(),s.end());
    cout << s.front() << endl;
    cout << s.back() << endl;


}

int main()
{
    solve();
	return 0;
}