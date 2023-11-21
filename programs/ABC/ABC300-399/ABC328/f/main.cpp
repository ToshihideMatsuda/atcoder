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

#include <iostream>
#include <vector>
using namespace std;

template<class Abel> struct UnionFind {
	vector<int> par;
	vector<int> rank;
	vector<Abel> diff_weight;

	UnionFind(int n = 1, Abel SUM_UNITY = 0) {
		init(n, SUM_UNITY);
	}

	void init(int n = 1, Abel SUM_UNITY = 0) {
		par.resize(n); rank.resize(n); diff_weight.resize(n);
		for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
	}

	int root(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			int r = root(par[x]);
			diff_weight[x] += diff_weight[par[x]];
			return par[x] = r;
		}
	}

	Abel weight(int x) {
		root(x);
		return diff_weight[x];
	}

	bool issame(int x, int y) {
		return root(x) == root(y);
	}

	bool merge(int x, int y, Abel w) {
		w += weight(x); w -= weight(y);
		x = root(x); y = root(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) swap(x, y), w = -w;
		if (rank[x] == rank[y]) ++rank[x];
		par[y] = x;
		diff_weight[y] = w;
		return true;
	}

	Abel diff(int x, int y) {
		return weight(y) - weight(x);
	}
};


int main()
{
    ll N, Q; cin >> N >> Q;
    map<ll,ll> G[N+5];

    vector<ll> ans;
    UnionFind<ll> uf(N+5);

    reps(i,1,1+Q) {
        ll a, b, d;
        cin >> a >> b >> d;
        if(a == b) {
            if(d == 0) {
                ans.push_back(i);
            }
        } else {
        if( G[a].count(b) == false) { 
            if(uf.issame(a,b) == false) {
                G[a][b] = d;
                G[b][a] = -d;
                uf.merge(a,b,d);
                ans.push_back(i);
            } else if(uf.diff(a,b) == d){
                ans.push_back(i);
            }
        } else if (G[a][b] == d) {
            ans.push_back(i);
        }
        }
    }

    OUT(ans, " ")



	return 0;
}