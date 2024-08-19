#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）

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
#define MINF_LL (-9223372036854775807LL)
#define MOD 998244353

#define MAX_N (2*100000+5)

ll N, D; 
vector<ll> x,y;

ll f(ll X, ll Y) {
    ll d = 0;
    rep(i,N){
        d += abs(X-x[i]) + abs(Y- y[i]);
    }

    return d;
}

int main()
{
    cin >> N >> D;

    x.resize(N);
    y.resize(N);
    rep(i,N)  cin >> x[i] >> y[i];

    ll midX= 0, midY = 0;

 {
    ll lb = - 1e7, ub = 1e7;

    while(ub - lb > 5) {
        ll mid1 = (2*lb + ub)/3;
        ll mid2 = (lb + 2*ub)/3;

        ll v1 = f(mid1,0);
        ll v2 = f(mid2,0);

        if(v1 < v2) {
            ub = mid2;
        } else {
            lb = mid1;
        }
    }

    ll min = f(lb,0);
    midX = lb;
    reps(x,lb+1, ub+1) {
        ll g = f(x,0);
        if( g < min ) {
            min = g;
            midX = x;
        }
    }

 }

 {
    ll lb = - 1e7, ub = 1e7;

    while(ub - lb > 5) {
        ll mid1 = (2*lb + ub)/3;
        ll mid2 = (lb + 2*ub)/3;

        ll v1 = f(0,mid1);
        ll v2 = f(0,mid2);

        if(v1 < v2) {
            ub = mid2;
        } else {
            lb = mid1;
        }
    }

    ll min = f(0,lb);
    midY = lb;
    reps(x,lb+1, ub+1) {
        ll g = f(0,x);
        if( g < min ) {
            min = g;
            midY = x;
        }
    }

 }

    ll l = 0;

    while(f(midX+l+1,midY) <=D) {
        l++;
    }

    ll ans = 0;
    if(1 <= l) {
        ans = 1;
    }
    reps(i,2,l+1) {
        ans += i*4 - 4;
    }

    out (ans)



	return 0;
}