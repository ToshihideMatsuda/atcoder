#include <unordered_map> 
using namespace std;

typedef long long ll;

//N以下の数について、素因数の数をcに登録
int c[10000000+9];
void elatsWithFactor(int N){
	for(int i= 2; i<N+1;i++){
		c[i]=0;
	}
	
	for(int i= 2; i<N+1;i++){
		if(c[i]==0){
			for(int j=i;j<N+1;j +=i){
				c[j] +=1;
			}
		}
	}
}

// 素因数分解関数
// f[n]= [ {p1,e1}, {p2,e2}, ..., {pm,em} ] : n = p1^e1 * p2^e2 * ... * pm^em
// f[n][p1] = e1, f[n][p2] = e2, ..., f[n][pm] = em
unordered_map<ll,ll> f[2*100000 + 5];
void factorial(ll N) {
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