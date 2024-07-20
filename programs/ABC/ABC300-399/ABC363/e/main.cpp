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


#define INF (2147483647)
#define MINF (-2147483648)
#define INF_LL  (9223372036854775807LL)
#define MINF_LL (-9223372036854775807LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
    ll H, W, Y; cin >> H >> W >> Y;
    vector A = vector(H, vector<ll> (W,0));
    vector B = vector(H, vector<bool> (W,false));
    rep(i,H)rep(j,W) cin >> A[i][j];

    priority_queue<tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>> > Q;
    rep(i,H) {
        Q.push({A[i][0],i,0});
        B[i][0] = true;
        if(B[i][W-1] == false) {
            Q.push({A[i][W-1],i,W-1});
            B[i][W-1] = true;
        }
    }
    rep(i,W) { 
        if(B[0][i] == false) {
            Q.push({A[0][i],0,i});
            B[0][i] = true;
        }
        
        if(B[H-1][i] == false) {
            Q.push({A[H-1][i],H-1,i});
            B[H-1][i] = true;
        }
    }


    vector<ll> dx = {1 ,-1, 0, 0 };
    vector<ll> dy = {0 ,0,  1, -1};

    ll cnt = 0;
    reps(iii,1,Y+1) {
        auto [a,i,j] = Q.top();
        if(a <= iii) {
            while(Q.size() > 0) {
                auto [a,i,j] = Q.top();
                if(iii < a) break;

                Q.pop();

                queue<pair<ll,ll>> QQ;
                QQ.push({i,j});
                cnt++;
                while(QQ.size() > 0) {
                    auto [i,j] = QQ.front(); QQ.pop();
                    rep(k,4) {
                        ll x = i+dx[k];
                        ll y = j+dy[k];
                        if(0 <= x && x <= H-1 && 0 <= y && y <= W-1) {
                            if(A[x][y] <= iii && B[x][y] == false) {
                                B[x][y] = true;                    
                                cnt++;
                                QQ.push({x,y});
                            } else if(iii < A[x][y] && B[x][y] == false ) {
                                B[x][y] = true;
                                Q.push({A[x][y],x,y});
                            }
                        }
                    }
                }
            }
        }
        out(H*W-cnt)

    }


	return 0;
}