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

set<ll> G[MAX_N] ;
ll H[MAX_N] ;
vector<bool> ch(MAX_N,false);


typedef vector<vector<char> > mat;
mat make_mat(ll N){
    return vector<vector<char> >(N, vector<char>(N, ' '));
}


ll N; string R, C; 


pair<ll,ll> next(ll x,ll y) {
	if(y == N-1) { return {x+1, 0}; }
	else return {x, y+1};
}

bool perfectOK(mat & M) {
	rep(i,N) {
		ll a =0, b = 0, c =0;
		rep(j,N) if(M[i][j] == 'A') a++; else if(M[i][j] == 'B') b++; else if(M[i][j] == 'C') c++;
		if(a == 1 && b == 1 && c == 1) continue;
		return false;
	}


	rep(j,N) {
		ll a =0, b = 0, c =0;
		rep(i,N) if(M[i][j] == 'A') a++; else if(M[i][j] == 'B') b++; else if(M[i][j] == 'C') c++;
		if(a == 1 && b == 1 && c == 1) continue;
		return false;
	}

	rep(i,N) {
		rep(j,N) if(M[i][j] != '.') {
			if(R[i] == M[i][j]) break;
			return false;
		}
	}


	rep(j,N) {
		rep(i,N) if(M[i][j] != '.') {
			if(C[j] == M[i][j]) break;
			return false;
		}
	}
	return true;
}

bool canNext(mat & M) {
	rep(i,N) {
		ll a =0, b = 0, c =0;
		rep(j,N) if(M[i][j] == 'A') a++; else if(M[i][j] == 'B') b++; else if(M[i][j] == 'C') c++;
		if(a <= 1 && b <= 1 && c <= 1) continue;
		return false;
	}


	rep(j,N) {
		ll a =0, b = 0, c =0;
		rep(i,N) if(M[i][j] == 'A') a++; else if(M[i][j] == 'B') b++; else if(M[i][j] == 'C') c++;
		if(a <= 1 && b <= 1 && c <= 1) continue;
		return false;
	}

	rep(i,N) {
		rep(j,N) if(M[i][j] == ' ') break; else if(M[i][j] != '.') {
			if(R[i] == M[i][j]) break;
			return false;
		}
	}


	rep(j,N) {
		rep(i,N) if(M[i][j] == ' ') break; else if(M[i][j] != '.') {
			if(C[j] == M[i][j]) break;
			return false;
		}
	}
	return true;
}

int main()
{
	cin >> N >> R >>C;
	
	queue<pair<mat,pair<ll,ll> > > Q;
	Q.push({make_mat(N), {0,0}});


	vector<char> kouho = {'A', 'B', 'C', '.'};
	while(Q.size() > 0) {
		auto [M, xy] = Q.front();Q.pop();
		auto [x, y] = xy;

		for(auto k : kouho) {
			auto M2 = M;
			M2[x][y] = k;
			
			if(x == N-1 && y == N-1) {
				if(perfectOK(M2)) {
					out("Yes")
					rep(i,N) {
						rep(j,N) out0(M2[i][j])
						cout << endl;
					}
					return 0;
				}
				continue;
			}

			if(canNext(M2)) {
				Q.push({M2,next(x,y)});
			}
		}
	}

	out("No")
	

	return 0;
}