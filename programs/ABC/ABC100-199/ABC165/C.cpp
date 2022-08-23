

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
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
ll N,M,Q;

// 増加列（1 <= A_1 <= A_2 <= .. <= A_N <= M）の全パターンをsetに詰めて返却
set<vector<ll>> createAllIncrementSeqence(ll N, ll M) {
  set<vector<ll>>s;
  vector<ll> A(N,1);  
  queue<vector<ll>>Q1;
  Q1.push(A);
  s.insert(A);
  while(Q1.size()>0){
  	auto q=Q1.front();Q1.pop();
  	rep(i,N){
  		vector<ll> p(q);

  		if(p[i]<M) reps(j,i,N)p[j]++;
  		
  		if(!s.count(p) && q.back() < M) {
            s.insert(p);
            Q1.push(p);
        } 
  	}
  }
  return s;
}

void solve() {
  cin>>N>>M>>Q;
  ll abcd[Q][4];
  rep(i,Q)rep(j,4)cin>> abcd[i][j];
  set<vector<ll>>s = createAllIncrementSeqence(N, M);
  
  ll ans = 0;
  for(auto A:s){
    /*
  	rep(i,A.size())cout<< A[i] <<" ";
  	cout<< endl;
    */
  	
  	ll sum =0;
  	rep(i,Q) if(A[abcd[i][1]-1]-A[abcd[i][0]-1]==abcd[i][2])sum+=abcd[i][3];
  	ans = max(ans,sum);
  }
  cout << ans;
}


int main()
{
  solve();
	return 0;
}