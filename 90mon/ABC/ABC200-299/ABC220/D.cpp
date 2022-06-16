#include <iostream>
#include <vector>
#include <limits>

using namespace std;
typedef long long ll;

int A[100009];
ll dp[100009][10];
/*
dp[i][j]:i ban made mitatokino k no toorisuu
dp[i][j]=
for(int k = 0; k<10;k++){
	if((A[i] + k)%10==0) dp[i][j]+=dp[i-1][k]
	if((A[i] * k)%10==0) dp[i][j]+=dp[i-1][k]
}

*/

int main(){
	ll N;
    cin >> N;
    
    ll sumA=0ll;
    for(int i=1; i<=N;i++){
    	cin >> A[i];
    }
    
    //init
    for(int k=0; k<10;k++){
    	if(A[1]==k)
    	    dp[1][k]=1;
    }
    
    for(int i=2; i<=N;i++){
    	for(int k = 0; k<10;k++){   
    	    dp[i][(A[i] + k)%10]+=dp[i-1][k];
    	    dp[i][(A[i] + k)%10]%=998244353;
    	    dp[i][(A[i] * k)%10]+=dp[i-1][k];
    	    dp[i][(A[i] * k)%10]%=998244353;
    	}
    }
    
    for(int j=0; j<10;j++){
    	cout << dp[N][j] <<endl;
    }
    
    return 0;
}