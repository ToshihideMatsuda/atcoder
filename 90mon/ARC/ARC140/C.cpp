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

ll N;
string S;

void solve() {
    ll N, X;
    cin >> N >> X;

    if(N % 2 == 1) {
        // 奇数の場合
        ll M = N/2;
        deque<ll>L,R;

        reps(x,1,N+1){
            if(X == x) continue;
            if(L.size() < M) L.push_back(x);
            else R.push_back(x);
        }

        cout << X << " ";
        rep(i,M) {    
            if(L.size() > 0 ) { cout << L.back()  << " "; L.pop_back(); }
            if(R.size() > 0 ) { cout << R.front() << " "; R.pop_front();}
        }
        cout << endl;
    } else {
        // 偶数の場合
        ll M = N/2;
        deque<ll>L,R;

        ll Ladd = 0; // X補正 (X < L.pop_back())

        reps(x,1,N+1){
            if(X == x) {
                if(L.size() < M) Ladd = 1;
                continue;
            }
            if(L.size() + Ladd < M) L.push_back(x);
            else R.push_back(x);
        }

        cout << X << " ";
        rep(i,M) {
            if(Ladd == 0) {
                if(L.size() > 0 ) { cout << L.back()  << " "; L.pop_back(); }
                if(R.size() > 0 ) { cout << R.front() << " "; R.pop_front();}
            } else {
                if(R.size() > 0 ) { cout << R.front() << " "; R.pop_front();}
                if(L.size() > 0 ) { cout << L.back()  << " "; L.pop_back(); }
            }
        }
        cout << endl;

    }
}


int main()
{
  solve();
	return 0;
}