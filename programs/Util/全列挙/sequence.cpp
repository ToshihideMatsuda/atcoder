#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 

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