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
#define MOD 1000000000 + 7

#define MAX_N 2*100000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}


string AGCT[4] = {"A", "G", "C", "T"};
string AGCT3[4*4*4]; //3桁AGCT全パターン
unordered_map<string,ll> mp;

// dp[i][j]
ll dp[105][4*4*4]; 


void solve() {
    ll N; cin >> N;
    // A, C, G, T 以外の文字を含まない。
    // ?AGC, ?ACG, ?GAC, A?GC, AG?C を部分文字列として含まない。
    // 
    
    rep(i,4)rep(j,4)rep(k,4) AGCT3[i*4*4+j*4+k] = AGCT[i] + AGCT[j] + AGCT[k];
    rep(i,4*4*4) mp[AGCT3[i]] = i;

    rep(i,4*4*4) dp[3][i] = 1;
    dp[3][mp["AGC"]] = 0;
    dp[3][mp["GAC"]] = 0;
    dp[3][mp["ACG"]] = 0;

    reps(n,4,N+1) {
        rep(i,4*4*4) {
            //calc dp[n][i] 
            unordered_map<string,bool> nx;
            rep(j,4) nx[AGCT[j]] = true;

            if(AGCT3[i].substr(1,2) == "AG") nx["C"] = false;
            if(AGCT3[i].substr(1,2) == "AC") nx["G"] = false;            
            if(AGCT3[i].substr(1,2) == "GA") nx["C"] = false;
            if(AGCT3[i][0] == 'A' && AGCT3[i][2] == 'G') nx["C"] = false; //A?GC
            if(AGCT3[i][0] == 'A' && AGCT3[i][1] == 'G') nx["C"] = false;  //AG?C

            string header = AGCT3[i].substr(1,2);
            rep(j,4) if(nx[AGCT[j]]) {
                dp[n][mp[ header + AGCT[j] ]] += dp[n-1][i];
                dp[n][mp[ header + AGCT[j] ]] %= MOD;
            }
            
        }
    }

    ll ans = 0;
    rep(i,4*4*4)  {
        ans += dp[N][i] ;
        ans %= MOD;
    }
    cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}