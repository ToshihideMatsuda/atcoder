#include <bits/stdc++.h> 

using namespace std;

#define debug false

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 



#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 10000 + 5
#endif

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}
void UNSOLVABLE() {
  cout << "UNSOLVABLE" << endl;
}


set<string> ans[21];
int N;

void calc(int n) {
    if(n == 2) {
        ans[2].insert("()");
        return;
    }

    if(ans[n-2].size() == 0) calc(n-2);
    for(auto S : ans[n-2]) ans[n].insert("("+ S + ")");

    for (int i = 2; i <= n-2; i+=2) {
        if(ans[n-i].size() == 0) calc(n-i);
        if(ans[i].size() == 0)   calc(i);

        for(auto S : ans[n-i]) for(auto T : ans[i] ) ans[n].insert(S + T);
    }   
    
}

void solve(){
    cin >> N;
    if(N%2 == 0)
    {
        
        calc(N);
        vector<string> A;
        for(auto S:ans[N]) A.push_back(S);
        sort(A.begin(),A.end());
        rep(i,A.size()) cout << A[i] << endl;
    }

}


int main(){
    solve();
    return 0;
}

