#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 2*100000+5

int main()
{
	ll N,M;cin>>N>>M;
	vector<ll> A(N+1);reps(i,1,N+1)cin>>A[i];
	
  //v[m]: m回目の0~Nの範囲の値
  vector<vector<ll>> v(M+1);
	reps(i,1,N+1){

    if(A[i] > N) continue;

    ll s = MAX(1,(-A[i]+i-1)/i);
    ll e = MIN(M,(N-A[i]+i-1)/i);

    reps(m, s, e+1) {
      ll value = A[i] + m * i;
      v[m].push_back(value);
    }
	}

	reps(m,1,M+1){
    ll mx = 0;
    ll size = v[m].size();
    rep(i,size) mx = MAX(mx, v[m][i]);
    vector<bool> exist(mx + 2);
    for(auto val : v[m]) exist[val] = true;
    rep(i,M+1) if(exist[i] == false) { 
      cout << i << endl;
      break;
    }
	}
	
	return 0;
}
