#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

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
bool prime[1000000+9]; //エラトステネスの篩で計算
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