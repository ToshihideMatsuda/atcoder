#include "bits/stdc++.h"
#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out(s) cout << s << endl;
#define out0(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD (1000000000+7)

#define MAX_N (4*100000+5)

// G[from]= {cost, to}

int main()
{
	ll t;cin>>t;
	while(t--){
  ll N;
  cin >> N;
  vector<ll>P(N);
		rep(i,N)cin>>P[i];
		bool ok =true;
		rep(i,N)if(i+1!=P[i])ok=false;
		if(ok){
			out(0);
			continue;
		}
		
		set<ll> s;
		
		rep(i,N){
			if(P[i]==i+1){
				if(s.size()==0){
					out(1);
					goto next;
				}
				
				auto p = s.rbegin();
				
				if(*p==i){
					out(1)
					goto next;
				}
				
			}
			s.insert(P[i]);
		}
		
		if(P[0] == N && P[N-1] == 1) {
			out(3)
			goto next;
		}


		
		out(2);
		next:
		continue;
	}
	
	return 0;
}
