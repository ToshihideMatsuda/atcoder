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

int main() {
	int n; cin >> n;
	ll ans = 0;
	ll AB =0;
	ll tA  = 0;
	ll hB  = 0;
	rep(i,n){
		string s;
		cin>>s;
		rep(j,s.size()-1){
			if(s[j]=='A'&& s[j+1]=='B')ans++;
		}
		
		if(s.back()=='A'&&s.front()=='B')AB++;
		else if(s.back()=='A')tA++;
		else if(s.front()=='B')hB++;
	}
	
	if(AB > 0) {
		ans += (AB - 1);
		if(tA >0){
			ans +=1;
			tA--;
		}
		if(hB >0){
			ans +=1;
			hB--;
		}
	} 
	
	ans += min(tA,hB);
	
	cout << ans ;
}
