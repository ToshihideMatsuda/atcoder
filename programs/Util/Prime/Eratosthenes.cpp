#include <unordered_map> 
using namespace std;

typedef long long ll;

//エラトステネスの篩、prime[i] = true -> 素数
bool prime[1000000+9];
void EratosthenesPrime(ll N){
  if(N == -1) N = 1000000+5;
  rep(i,1000000+9) prime[i] = true;
  prime[0] = false;
  prime[1] = false;
	for(ll i= 2; i<N+1;i++){
		for(ll j=2*i;j<N+1;j +=i){
			prime[j] =false;
		}
	}
}


//エラトステネスの篩のバリエーション。N以下の数について、素因数の数をcに登録
int c[1000000+9];
void EratosthenesWithFactor(int N){
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

