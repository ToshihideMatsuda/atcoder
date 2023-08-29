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
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD (1000000000+7)

#define MAX_N (100000+5)

int main()
{
	string s,t;cin>>s>>t;
	for(int i=s.size()-t.size();i>-1;i--){
		bool ok=true;
		rep(j,t.size())if(s[i+j]=='?')continue;else if(s[i+j]==t[j])continue; else ok=false;
		if(ok){
			rep(j,t.size()) s[i+j]=t[j];
			rep(i,s.size())if(s[i]=='?')s[i]='a';
			out(s)
			return 0;
			break;
		}
	}
	out("UNRESTORABLE")
	return 0;
}
