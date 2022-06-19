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
    ll N;
    cin >> N;

    vector<double> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    deque<pair<double,ll>> T(N);
    rep(i,N) T[i] = make_pair(A[i]/B[i], i);
    
    double l = 0;
    ll indx = 0;
    while(T.size() > 1) {
        
        double tf = T.front().first;
        ll fi = T.front().second;
        double tb = T.back().first;
        ll bi = T.back().second;
        T.pop_front();
        T.pop_back();

        l += min(tf,tb) * B[fi];
        
        if( tf < tb ) {
            // front から燃え尽きる
            T.push_back(make_pair(tb - tf, bi));
        }
        else {
            // back から燃え尽きる
            T.push_front(make_pair(tf - tb, fi));
        }
    }


    double t =  T.front().first;
    ll i = T.front().second;

    l += t * B[i] / 2.0;

    cout << setprecision(15) << l << endl;

}

int main()
{
    solve();
	return 0;
}