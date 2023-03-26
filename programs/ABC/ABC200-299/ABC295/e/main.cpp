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
#define inV(A) for (auto &i: A) { cin >> i; }
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


using mint = modint998244353;
mint binom[5010][5010];
void initBinom() {
    for (int i = 0; i < 5010; i++) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
        }
    }
}

int main()
{
	initBinom();
	ll N, M, K;
	cin >> N >> M >> K;

	vector<ll> A(N);
	inV(A)

	mint E = 0;
	// E[X] = Σ (i * P[X = i]) 
	//      = Σ (P[X >= i]) （丁寧に式変形するとこうなる）
	// を利用して解く

	reps(i,1,M+1) {
		// P[A_k >= i]となる確率（A_k 以降の後半部分 N+1-K 個がi以上 ）
		// <=> 「操作 1 を行ったあと、A_j >= i を満たすjがN+1−K 個以上ある確率」

		ll r = N+1-K; // N+1-K 個に対する残数
		ll z = 0;     // 0の個数

		for(auto j : A) {
			if(j >= i) r --;
			if(j == 0) z ++;
		}

		if(r <= 0) { //すでにN+1-K 個達成
			E += 1;
			continue;
		} else if(z < r) { //0が全てi以上になったとしても、i以上のものがN+1-K個より少ない
			continue;
		} else {
       		mint p = mint(M + 1 - i) / mint(M); // i以上になる確率 p（分母：1~MのM通り、分子：i~MのM+1-i通り）
			mint q = 1 - p; 					// i未満になる確率 q (1- p)
	        vector<mint> p_pow(z + 1, 1);  		// i以上になる確率の冪乗 p^0,p^1, ...., p^z
     	    vector<mint> q_pow(z + 1, 1);  		// i未満になる確率の冪乗 q^0,q^1, ...., q^z

			rep(j,z) p_pow[j+1] = p_pow[j] * p;
			rep(j,z) q_pow[j+1] = q_pow[j] * q;

			// i以上になる回数がj回(>=r), i未満になる回数がz-j回となる確率を、
			// p_powとq_powと２項係数をかけることによって算出
			reps(j,r,z+1) {
				E += p_pow[j] * q_pow[z-j] * binom[z][j];
			}
		}
	}

	out(E.val());


	return 0;
}