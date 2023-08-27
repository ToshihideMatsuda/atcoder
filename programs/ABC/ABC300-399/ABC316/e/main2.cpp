#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;
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
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
	ll H, W; cin >> H >> W;
	vector<string> A = vector<string>(H+2);
	string T = string(W+2,'#');
	A[0] = T;
	A[H+1] = T;

	reps(i,1,H+1) {
		string a; cin >> a;
		a = "#" + a + "#";
		A[i] = a;
	}
	

	vector<tuple<ll,ll,char>> M;

	pair<ll,ll> s,g;
	reps(h,1,H+1)reps(w,1,W+1) {
		if(A[h][w] == '>' || A[h][w] == 'v' || A[h][w] == '<' || A[h][w] == '^') {
			M.push_back({h,w,A[h][w]});
			A[h][w] = '#';
		}else if(A[h][w] == 'S') {
			s = {h,w};
		}else if(A[h][w] == 'G') {
			g = {h,w};
		}
	}


	for(auto [h,w,c] : M) {
		if(c == '>') {
            w++;
			while(A[h][w] != '#') A[h][w++] = '!';
		} else if(c == '<') {
            w--;
			while(A[h][w] != '#') A[h][w--] = '!';
		} else if(c == 'v') {
            h++;
			while(A[h][w] != '#') A[h++][w] = '!';
		} else if(c == '^') {
            h--;
			while(A[h][w] != '#') A[h--][w] = '!';
		}
	}


	auto mp = vector(H+2,vector<ll> (W+2, -1));
	auto checked = vector(H+2,vector<bool> (W+2, false));


	ll dx[4] = {1,-1,0, 0};
	ll dy[4] = {0, 0,1,-1};

	queue<pair<ll,ll>> Q;
	Q.push(s);
	mp[s.first][s.second] = 0;
	checked[s.first][s.second] = true;

	while(Q.size() > 0) {
		auto [h,w] = Q.front();Q.pop();

		rep(i,4) if(checked[h+dx[i]][w+dy[i]] == false){
			if(A[h+dx[i]][w+dy[i]] != '#' && A[h+dx[i]][w+dy[i]] != '!') {
				
                mp[h+dx[i]][w+dy[i]] = mp[h][w] + 1;
                checked[h+dx[i]][w+dy[i]] = true;

				Q.push({h+dx[i],w+dy[i]});
			}
		}
	}

	out(mp[g.first][g.second])





	return 0;
}