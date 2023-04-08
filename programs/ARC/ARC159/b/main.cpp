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
#define out(s) out1(s)
#define out1(s) cout << s << endl;
#define out2(s,t) cout << s << t << endl;
#define out3(s,t,r) cout << s << t << r << endl;
#define out4(s,t,r,u) cout << s << t << r << u << endl;
#define out5(s,t,r,u,o) cout << s << t << r << u << o << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) push_back(s)

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (1000000+5)
//c[i] = true -> 素数
bool prime[1000000+9];
void EratosthenesPrime(ll N){
  rep(i,1000000+5) prime[i] = true;
  prime[0] = false;
  prime[1] = false;
	for(ll i= 2; i<N+1;i++){
		for(ll j=2*i;j<N+1;j +=i){
			prime[j] =false;
		}
	}
}


//aとbの最大公約数を計算
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}


// 素因数分解の初期化関数
// f[n]= [ {p1,e1}, {p2,e2}, ..., {pm,em} ] : n = p1^e1 * p2^e2 * ... * pm^em
// f[n][p1] = e1, f[n][p2] = e2, ..., f[n][pm] = em
unordered_map<ll,ll> f[2*100000 + 5];
void factorial_init(ll N) {
    f[1][1] = 1;
    for(ll i = 2; i < N+1; i++) {
        if(f[i].size() == 0) {
            for(int j = i; j < N+ 1; j+= i) {
                ll tmp = j;
                ll cnt = 0;
                while(tmp % i == 0) {
                    tmp = tmp / i;
                    cnt ++;
                }
                f[j][i] = cnt;
            }
        }
    }
}

//入力値cに対する素因数分解の関数。cとしては <= 10^12を想定。
//またエラトステネスの篩によって素数が計算されている前提
unordered_map<ll,ll> factorial(ll c) {
	// 素因数分解結果
	unordered_map<ll,ll> factor;
	for(ll i = 2; i < 1000000+9; i ++) {
		if(prime[i]){
			while( c % i == 0) {
				factor[i] ++;
				c /= i;
			}
		}
	}
	if(c > 1) factor[c] ++;
    return factor;
}



//idxを次の要素に進める。指数がfactorに指定された値を超えるとfalse
bool _next(vector<ll>& idx, unordered_map<ll,ll>& factor) {
	auto mpIdx = factor.begin();
	for(ll i = 0; i < idx.size(); i ++) {
		if(idx[i] < (*mpIdx).second) {
			idx[i] ++;
			return true;
		} else {
			idx[i] = 0;
		}
		mpIdx ++;
	}
	
	return false;
}

//factorの要素をidxの指数に従って掛け算する
ll _cal(vector<ll>& idx, unordered_map<ll,ll>& factor) {
	ll v = 1;
	auto mpIdx = factor.begin();
	for(ll i = 0; i < idx.size(); i ++) {
		ll time = idx[i];
		while(time--) v *=  (*mpIdx).first;
		mpIdx++;
	}
	return v;
}


//素因数分解：f[n]= [ {p1,e1}, {p2,e2}, ..., {pm,em} ] : n = p1^e1 * p2^e2 * ... * pm^em
//を入力として、そのすべての因数 1, p1, p1^2 , ..., p1^e1 * p2^e2 * ... * pm^em を計算する関数
vector<ll> allFactor(unordered_map<ll,ll> &factor) {
	vector<ll> idx(factor.size());
	vector<ll> ret;
	do{
		ret.push_back(_cal(idx,factor));
	} while(_next(idx,factor));

	return ret;
}

int main()
{
	EratosthenesPrime(MAX_N);
	ll A, B; cin >> A >> B;

	if(B < A) { // A < Bとする
		ll tmp = A;
		A = B;
		B = tmp;
	}
	ll g = gcd(A, B);

	ll a = A/g;
	ll b = B/g;

	ll ans = 0;

	while(a > 0 && b > 0) {
		ll c = b - a;
		if(c == 0){
			ans++;
			break;
		} else if(c == 1) {
			ans += MIN(a,b);
			break;
		}

		// 素因数分解結果
		unordered_map<ll,ll> factor = factorial(c);

		ll min = INF_LL;
		ll g2 = 0;

		for(ll gt: allFactor(factor)) {
			if(gt == 1) continue;
			if(a % gt < min ) {
				min = a%gt;
				g2 = gt;
			}

		}

		ans += (a%g2);
		a = (a-min) / g2;
		b = (b-min) / g2;

	}
	out(ans)

	return 0;
}