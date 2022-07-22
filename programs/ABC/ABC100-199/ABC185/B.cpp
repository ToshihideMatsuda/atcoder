#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

#define debug false

#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 

typedef long long ll;
#define MOD 998244353

int main(){
	ll N,M,T;cin>>N>>M>>T;
	ll A[M+2],B[M+2];
	reps(i,1,M+1){
		cin>>A[i]>>B[i];
	}
	A[0]=0;B[0]=0;
	A[M+1]=T;B[M+1]=T;
	ll NN=N;
	reps(i,1,M+2){
		N -=(A[i] - B[i-1]);
		if(N<=0){
			cout<< "No"<<endl;
			return 0;
		}
		N+=(B[i] -A[i]);
		N=min(N,NN);
	}
	cout << "Yes" << endl;
	
    
    return 0;
}
