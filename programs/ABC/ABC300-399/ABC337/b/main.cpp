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

// "aabbbbaaca" -> [("a",2),("b",4),("a",2),("c",1),("a",1)]
vector<pair<string,ll> > runLengthEncoding(string S) {
    vector<pair<string,ll> > ret;
    ll i = 0;
    while(i < S.size()) {
        ll cnt = 1;
        while(i+1 < S.size() && S[i] == S[i+1]) {
            cnt++;
            i++;
        }
        ret.push_back(make_pair(S.substr(i,1),cnt));
        i++;
    }
    return ret;
}


int main()
{	
	string S; cin >> S;	
	auto c = runLengthEncoding(S);
	if(c.size() == 3 && c[0].first == "A" && c[1].first == "B" && c[2].first == "C" ) {
		out("Yes")
	} else if(c.size() == 2 && (
		(c[0].first == "A" && c[1].first == "B") || 
		(c[0].first == "A" && c[1].first == "C")  ||
		(c[0].first == "B" && c[1].first == "C")  
		)) {
		out("Yes")
	} else if(c.size() == 1 && (c[0].first == "A" || c[0].first == "B" || c[0].first == "C" )) {
		out("Yes")
	}
	else {
		out("No")
	}

	return 0;
}
