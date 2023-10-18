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
#define MOD 998244353

#define MAX_N (2*100000+5)


int main()
{
	ll n;cin>> n; string t;
	cin>> t;
	vector<ll> ans;
	rep(i,n){
		string s;
		cin>> s;
		if(t.size()==s.size()){
			ll c=0;
			rep(i,t.size())if(t[i]!=s[i])c++;
			if(c<=1)ans.push_back(i+1);
		}else if(t.size()+1==s.size()){
			bool d=false;
			rep(i,t.size()){
				if(d==false){
					if(t[i]!=s[i]){
						d=true;
						i--;
						continue;
					}
				}else{
					if(t[i]!=s[i+1]) goto next;
				}
			}
			ans.push_back(i+1);
		} else if(t.size()-1==s.size()){
			bool d=false;
			rep(i,s.size()){
				if(d==false){
					if(t[i]!=s[i]){
						d=true;
						i--;
						continue;
					}
				}else{
					if(t[i+1]!=s[i]) goto next;
				}
			}
			ans.push_back(i+1);
		}
		
		next:
		continue;
	}
	
	
	out(ans.size())
	rep(i,ans.size()){
		out0(ans[i])out0(" ")
	}
	
	
	return 0;
}
