#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）
/* ---------------------- ここから ---------------------- */
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using bll = mp::cpp_int;
// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using real = mp::number<mp::cpp_dec_float<1024>>;
/* ---------------------- ここまで ---------------------- */

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
	ll N, X, Y; cin >> N >> X >> Y;
    vector<ll> Ax[2],Ay[2];
    rep(i,N) {
        ll a; cin >> a;
        if(i%4 == 0) Ay[0].push_back(a);
        else if(i%4 == 1) Ax[0].push_back(a);
        else if(i%4 == 2) Ay[1].push_back(a);
        else Ax[1].push_back(a);
    }

    map<ll,ll> mp_x, mp_y;
    for(int i = 0; i < (1 << Ax[0].size()); i ++ ) {
        ll v = 0;
        rep(j,Ax[0].size()) if( (i & (1 <<j) ) == 0 ) { 
            v += -1 * Ax[0][j]; 
        } else { 
            v += Ax[0][j]; 
        }
        mp_x[v] = i;
    }

    for(int i = 0; i < (1 << Ay[0].size()); i ++ ) {
        ll v = 0;
        rep(j,Ay[0].size()) if( (i & (1 <<j) ) == 0 ) { 
            v += -1 * Ay[0][j]; 
        } else { 
            v += Ay[0][j]; 
        }
        mp_y[v] = i;
    }

    vector<ll> ansX(2,-1), ansY(2,-1);
    
    for(int i = 0; i < (1 << Ax[1].size()); i ++ ) {
        ll v = 0;
        rep(j,Ax[1].size()) if( (i & (1 <<j) ) == 0 ) { 
            v += -1 * Ax[1][j]; 
        } else { 
            v += Ax[1][j]; 
        }

        if ( mp_x.count(X-v) ) {
            ansX[0] = mp_x[X-v];
            ansX[1] = i;
            break;
        }
    }

    for(int i = 0; i < (1 << Ay[1].size()); i ++ ) {
        ll v = 0;
        rep(j,Ay[1].size()) if( (i & (1 <<j) ) == 0 ) { 
            v += -1 * Ay[1][j]; 
        } else { 
            v += Ay[1][j]; 
        }

        if ( mp_y.count(Y-v) ) {
            ansY[0] = mp_y[Y-v];
            ansY[1] = i;
            break;
        }
    }

    if(ansX[0] == -1 || ansY[0] == -1) {
        out("No")
        return 0;
    }

    out("Yes")
    ll d = 0; // 0:R, 1:U, 2:L, 3:T
    rep(i,N) {
        if(i%2 == 0) {
            ll v = ansY[(i%4)/2]%2; 
            ansY[(i%4)/2] >>= 1;
            if(v == 0) { //minus
                if(d == 0) { // R
                    out0("R")
                } else { // L
                    out0("L")
                }
                d = 1;
            } else {
                if(d == 0) { // R
                    out0("L")
                } else { // L
                    out0("R")
                }
                d = 3;
            }
        } else {
            ll v = ansX[((i-1)%4)/2]%2; 
            ansX[((i-1)%4)/2] >>= 1;
            if(v == 0) { //minus
                if(d == 1) { // U
                    out0("R")
                } else { // T
                    out0("L")
                }
                d = 2;
            } else {
                if(d == 1) { // U
                    out0("L")
                } else { // T
                    out0("R")
                }
                d = 0;
            }
        }



    }


	return 0;
}