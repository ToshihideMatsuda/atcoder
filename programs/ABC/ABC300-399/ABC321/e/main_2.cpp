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

// 多倍長テンプレ（デバッグだとダメかも）
/* ---------------------- ここから ---------------------- */
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;
/* ---------------------- ここまで ---------------------- */

int main()
{
    ll pow2[64];
    pow2[0] = 1;
    reps(i,1,64) pow2[i] = pow2[i-1] * 2;

    ll T; cin >> T;
    vector<Bint> v;
    while(T--) {
        Bint N, X; ll K; cin >> N >> X >> K;
        Bint ans = 0;
        
        Bint tmp = 0;


        

        while(X > 0 && K >= 0) {
            if(K < 63) {
                if(N < X * pow2[K]) {
                    // nop
                } else if( N < (X+1) * pow2[K] - 1 ){
                    ans += N - ( X * pow2[K] - 1 ) - tmp;
                } else {
                    ans += pow2[K] - tmp;
                }


                tmp = 0;

                if(0 <= K-2) {
                    if(N < X * pow2[K-2]) {
                        tmp = 0;
                    } else if( N < (X+1) * pow2[K-2] - 1 ){
                        tmp = N - ( X * pow2[K-2] - 1 );
                    } else {
                        tmp = pow2[K-2];
                    }
                }
            }

            X /= 2;
            K--;
        }

        v.push_back(ans);

    }

    OUT(v,endl)
	return 0;
}

//2642932442085843157
//27021597764222976