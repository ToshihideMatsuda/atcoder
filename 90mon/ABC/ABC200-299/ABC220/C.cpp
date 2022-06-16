#include <iostream>
#include <vector>
#include <limits>

using namespace std;
typedef long long ll;

int A[100009];

int main(){
	ll N,X;
    cin >> N;
    
    ll sumA=0ll;
    for(int i=1; i<=N;i++){
    	cin >> A[i];
    	sumA+=A[i];
    }
    cin >> X;
    
    ll q = X/sumA;
    ll rX = X%sumA;
    
    ll cnt = q*N; //Gurunkaisuu q
  
    int itr=1; 
    while(rX>=0){
    	rX-=A[itr++];
    	cnt++;
    }
    
    
    cout << cnt;
    
    
    
    return 0;
}