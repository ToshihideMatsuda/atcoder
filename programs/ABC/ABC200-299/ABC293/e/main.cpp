#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ )
#define reps(i,m,n)  for(ll i = m; i < n; i++ )
#define rev(i,n)     for(ll i = n; i > -1; i--)
#define revs(i,m,n)  for(ll i = m; i > n; i--)
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out(s) cout << s << endl;
#define out2(s) cout << s;


typedef vector<vector<ll> > mat;
mat make_mat(ll N, ll M){
    return vector<vector<ll> >(N,vector<ll>(M));
}

/**
 * matrix multiple（行列積）
 * A: NxM matrix
 * B: MxK matrix
 * output: C=A*B(NxK matrix)
*/
mat mat_mul(mat A, mat B, ll MOD) {
    // 行列乗算
    ll N = A.size();
    ll M = A[0].size();
    ll M0 = B.size();
    ll K = B[0].size();
    if(M!=M0){
        out("invalid input")
        exit(1);
    }

    mat C = make_mat(N,K);
    //C=A*B (matrix)
	rep(n,N) rep(k,K) rep(m,M){
        C[n][k]+=A[n][m]*B[m][k];
    	C[n][k]%=MOD;
    }

    return C;
}

/**
 * matrix power（行列累乗）
 * A: NxN matrix
 * x: power
 * output: B=A^x(NxN matrix)
*/
mat mat_pow(mat  A, ll x, ll MOD) {
    // 行列累乗
    ll N = A.size();
    ll N0 = A[0].size();

    if(N!=N0){
    	out("invalid input")
        exit(1);
    }

    mat B = make_mat(N,N);

    // B=E(identity matrix)
    rep(i,N) B[i][i] = 1;

    while (x>0) {
        if ((x&1)>0) B = mat_mul(B, A, MOD);
        A = mat_mul(A, A, MOD);
        x >>= 1;
    }
    return B;
}

void fib(){
    //fib
    // f(n+2)= f(n+1) + f(n)

    mat F  = { {1,1}, {1,0} };
    mat F0 = { {1}, {1} };

    reps(n,1,20){
        mat b= mat_mul(mat_pow(F, n-1, 1L<<60),F0,1L<<60);
        out(b[0][0]);
    }
}

// 1+A+A^2+...+A^(X-1) % M
void mulsum(ll A, ll X, ll M){
    //a_n=Aa_(n-1)+1,a0=0
    //{a_n,1}={ {A, 1},{0,1} }{a_(n-1),1}
    //{a_X,1}={ {A, 1},{0,1} }^X * {a_0,1}
    
	mat mA = { {A, 1}, {0, 1} };
	mat mA0 = { {0}, {1} };
	out(mat_mul(mat_pow(mA, X, M),mA0,M)[0][0])
}

int main() {
    //fib();

    ll A,X,M;
    cin >> A>>X>>M;
    mulsum(A, X, M);

    return 0;
}
