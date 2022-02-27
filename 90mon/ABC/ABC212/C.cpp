#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

#define debug false

#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 


typedef long long ll;

#define INF 1 << 28
#define MINF -1*(1 << 28)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 2*100000 + 5
#endif


void solve(){
    int N,M;
    cin >> N >>	M;
    vector<int> A(N),B(M);
    rep(i,N) cin >> A[i];
    rep(i,M) cin >> B[i];
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int ans =abs(A[N-1]-B[M-1]);
    
    int iA=0,iB=0;
    while(iA<N&&iB<M){
    	int x=A[iA] - B[iB];
    	ans=min(ans,abs(x));
    	if(x==0){
    		cout<<0<< endl;
    		return;
    	}else if(x>0){
    		iB++;
    	} else {
    		iA++;
    	}
    }
    
    cout << ans << endl;
    
}


int main(){

#if debug == true
    while(true){
        cout << "---debugMode---" << endl;
#endif
        solve();
        cout << endl;
#if debug == true
    }
#endif

    return 0;
}

