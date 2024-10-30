#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cassert>
#include <tuple>
#include <functional>
#include <limits>

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


#define INF (2147483647)
#define MINF (-2147483648)
#define INF_LL  (9223372036854775807LL)
#define MINF_LL (-9223372036854775808LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

ll cnt = 0;
ll query(ll i, ll j) {
    cnt++;
    cout << "?" << " " << i << " " << j << endl;
    ll t; cin >> t;
    if(t == -1){
        exit(-1);
    } 
    return t;
}

int main()
{
    ll N, M, Q; cin >> N >> M >> Q;

    vector<ll> one,other;
    one.push_back(1);
    int i = 2;
    while(one.size() < M+1 && other.size() < M+1) {
        ll t = query(1,i);
        if(t == 0) {
            one.push_back(i);
        } else {
            other.push_back(i);
        }
        i++;
		if(N < i)break;
    }

    ll x = 0;

    vector<ll> wrong;
    if(one.size() >= M+1) {
        x = 1;
        wrong = (other);
    }
    else {
        x = *(other.begin());
        wrong = (one);
    }

    i = one.size()+other.size()+1;
        vector<vector<ll>> same = {};
        for(int j = i; j < N+1;j++) {
            same.push_back({j});
        }

        while(same.size()>1 && wrong.size() < M) {
            vector<vector<ll>> same2 = {};
            for(int k = 0; k < same.size()/2;k++) {
                ll t = query(same[2*k][0],same[2*k+1][0]);
                if(t == 0) {
                    if(same[2*k].size() + same[2*k+1].size() <= M) { 
                        vector<ll> group(same[2*k]);
                        for(auto s:same[2*k+1])group.push_back(s);
                        same2.push_back(group);
                    }
                } else {
                    ll t = query(x,same[2*k][0]);
                    if(t == 0) {
                        for(auto s:same[2*k+1])wrong.push_back(s);
                    } else {
                        for(auto s:same[2*k])wrong.push_back(s);
                    }
                }
            }

            if(same.size()%2 == 1) {
                same2.push_back(same.back());
			}

            same = move(same2);
        }
    
    ll t = query(x,same[0][0]);
    if(t == 1) {
        for(auto s:same[0])wrong.push_back(s);
    }


    cout << "!" << " ";
    OUT(wrong," ")
    cout << endl;



	return 0;
}