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


void solve() {
    string S, T;
    cin >> S >> T;

    ll si = 0, ti = 0;
    while(si < S.size() && ti < T.size()) {
        if(S[si] == T[ti]) {
            if( si+1 < S.size() && ti + 1 < T.size() &&
                S[si] == S[si + 1] && T[ti] == T[ti + 1]) {
                
                char ss = S[si];
                ll cnt = 0;
                while(si+1 < S.size()  && S[si+1] == ss) {
                    si++;
                    cnt++;
                }

                rep(_,cnt) {
                    ti ++;
                    if(ti  < T.size() && T[ti] == ss) {
                        //ok
                    } else {
                        cout << "No" << endl;
                        return;
                    }
                }

                while(ti + 1 < T.size() && T[ti+1] == ss) {
                    ti++;
                }
            }

            si++;
            ti++;
            
        } else {
            cout << "No" << endl;
            return;
        }
    }

    if(si == S.size() && ti == T.size()) {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
}


int main()
{
  solve();
	return 0;
}