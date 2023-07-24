#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

#define debug false

#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 


typedef long long ll;

#define INF 1 << 28
#define MOD 998244353
#define MAX_N (2 * 100000 + 5)


int main(){

	ll t;cin>>t;
	rep(_,t){
		ll n;cin>>n;
		set<ll> G[n];
		rep(i,n-1){
			ll a,b;cin>>a>>b;
			a--;b--;
			G[a].insert(b);
			G[b].insert(a);
		}
		
		string s;
		cin>>s;
		
		vector<char> t(n,0);
		ll st=0;
		rep(i,n)if(G[i].size()==1){
			st=i;break;
		 }
		 queue<ll> Q;
		 Q.push(st);
		 t[st]='W';
		while(Q.size()>0){
			auto q=Q.front();Q.pop();
			
			for(auto g:G[q])if(t[g]==0){
				if(G[g].size()==1&&g!=st){
					if(s[g]!=t[q]){
						goto black;
					}
				}
				t[g]=s[q];
				Q.push(g);
			}
			
		}
		
		
		
		
		rep(i,n) cout<<t[i];
		cout<<endl;
		goto next;
		
		black:
		
		rep(i,n)t[i]=0;
		Q.push(st);
		 t[st]='B';
		while(Q.size()>0){
			auto q=Q.front();Q.pop();
			
			for(auto g:G[q])if(t[g]==0){
				if(G[g].size()==1&&g!=st){
					if(s[g]!=t[q]){
						cout<<(-1)<<endl;
						goto next;
					}
				}
				t[g]=s[q];
				Q.push(g);
			}
			
		}
		rep(i,n) cout<<t[i];
		cout<<endl;
		goto next;
		
		next:
		
		continue;
	}

    return 0;
}
