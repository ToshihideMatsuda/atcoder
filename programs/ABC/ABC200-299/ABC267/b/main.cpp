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


void solve() {
  string S;cin>>S;
	bool c[7];rep(i,7)c[i]=true;
	
	if(S[0]=='0'){
		if(S[6]=='0')c[0]=false;
		if(S[3]=='0')c[1]=false;
		if(S[1]=='0'&&S[7]=='0')c[2]=false;
		if(S[4]=='0')c[3]=false;
		if(S[2]=='0'&&S[8]=='0')c[4]=false;
		if(S[5]=='0')c[5]=false;
		if(S[9]=='0')c[6]=false;
		rep(i,5)if(c[i]==true){
			if(c[i+1]==false){
				reps(j,i+2,7) if(c[j]){
					cout<<"Yes";
					return ;
				}
			}
		}
	}
	
	cout << "No";
	
}


int main()
{
  solve();
	return 0;
}