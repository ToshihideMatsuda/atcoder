#include <bits/stdc++.h> 
#include <unordered_map>
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

#define MAX_N 2*100000+5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

ll gcd(ll x,ll y){
	if(y==0)return x;
	return gcd(y, x%y);
}
 
void solve() {
	ll N; cin >> N ;
	vector<ll>AA(N);
	set<ll>s;
	rep(i,N){
		cin >> AA[i];
		s.insert(AA[i]);
	}
	if(s.size()==1){
		cout << 1 << endl;
		return;
	}
	
	vector<ll>A(N-1);
	rep(i,N-1)A[i] = abs(AA[i+1]-AA[0]);
	ll g = A[0];
	reps(i,1,N-1)g=gcd(g,A[i]);
	
	
	
	if(g>=2) cout<<1;
	else cout<<2;	
}

int main()
{
  solve();
	return 0;
}