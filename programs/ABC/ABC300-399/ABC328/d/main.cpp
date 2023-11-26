#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out0(s) cout << s;
#define out(s)  cout << s << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) push_back(s)
/*
	vector<ll> X = {4,7,3,1,7,9,4};
	SORT(X, <)
	OUT(X,",") //1,3,4,4,7,7,9,

	SORT(X, >)
	OUT(X," ") //9 7 7 4 4 3 1
*/
#define SORT(A,R) std::sort((A).begin(),(A).end(), [](auto const& x, auto const& y) { return x R y; });
#define OUT(A,separate) for(auto a : A) { cout << a << separate; }


#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)


int main()
{
	string S;
	cin >> S;
	stack<char> sta;
	rep(i,S.size()) {
		sta.push(S[i]);

		while(sta.size() >= 3) {
			char c = sta.top(); sta.pop();
			char b = sta.top(); sta.pop();
			char a = sta.top(); sta.pop();
			if(a == 'A' && b == 'B' && c == 'C') {
				continue;
			} else {
				sta.push(a);
				sta.push(b);
				sta.push(c);
				break;
			}
		}		
	}

	stack<char> sta2;
	while(sta.size() > 0) {
		sta2.push(sta.top()); sta.pop();
	}


	while(sta2.size() > 0) {
		out0(sta2.top());sta2.pop();
	}
	
	

	return 0;
}