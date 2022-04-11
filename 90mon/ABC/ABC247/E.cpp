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


void solve(){
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<vector<int > > Aex;
    vector<int> tmp;
    rep(i,N) {

        int A;
        cin >> A;
        if(A < Y || X < A) {
            if(tmp.size() > 0) {
                Aex.push_back(tmp);
                tmp.clear();
            }
        } else {
            tmp.push_back(A);
        }
    }
    
    if(tmp.size() > 0) {
         Aex.push_back(tmp);
    }

    ll ans = 0;
    for(vector<int> A : Aex) {

        //[l,r)
        int l = 0, r = 1;
        unordered_map<int,int > mp;
        mp[A[l]] ++;

        while(l < A.size() && r <= A.size()) {
            if(mp[X] > 0 && mp[Y] > 0) {
                ans += A.size() - (r-1);
                
                mp[A[l]] --;
                l++;
                if(l == r) {
                    mp[A[r]]++;
                    r++;
                } 
            } else {
                mp[A[r]]++;
                r++;
            }
        }
    }

    cout << ans << endl;

}



int main(){
    solve();
    return 0;
}

