#include <iostream> 
#include <vector> 
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


void solve() {
    ll N; cin >> N;
    vector<ll> ans(N+1);
    vector<ll> A(N+1);
    rep(i,N)cin >> A[i+1];
    
    
    ll M=0;
    for(ll i=N;i>0;i--){
    	//cout << "i="<<i <<endl;
    	ll tmp =0;
    	for(ll j=2*i;j<N+1;j+=i){
    		tmp += ans[j];
    		tmp %=2;
    	}
    	ans[i] = (tmp == A[i]) ? 0:1;
    	if(ans[i]==1) M++;
    }
    
    
    cout << M <<endl;
    reps(i,1,1+N)if(ans[i]==1)cout << i <<" "<<endl;
}


int main()
{
  solve();
	return 0;
}
