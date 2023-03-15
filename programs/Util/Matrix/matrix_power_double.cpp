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
#define out0(s) cout << s;
#define out2(s,t) cout << s << t << endl;
#define out3(s,t,r) cout << s << t << r << endl;
#define out4(s,t,r,u) cout << s << t << r << u << endl;
#define out5(s,t,r,u,o) cout << s << t << r << u << o << endl;



typedef vector<vector<double> > mat;
mat make_mat(ll N, ll M){
    return vector<vector<double> >(N,vector<double>(M));
}

/**
 * matrix multiple（行列積）
 * A: NxM matrix
 * B: MxK matrix
 * output: C=A*B(NxK matrix)
*/
mat mat_mul(mat A, mat B) {
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
    }

    return C;
}

/**
 * matrix power（行列累乗）
 * A: NxN matrix
 * x: power
 * output: B=A^x(NxN matrix)
*/
mat mat_pow(mat  A, ll x) {
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
        if ((x&1)>0) B = mat_mul(B, A);
        A = mat_mul(A, A);
        x >>= 1;
    }
    return B;
}


//以下テスト用コード

void round(){
    ll N = 20;
    //回転行列
    mat R  = { 
            {cos(2*M_PI/N), -sin(2*M_PI/N)}, 
            {sin(2*M_PI/N),cos(2*M_PI/N)} 
            };
    mat X = { {1}, {0} };

    reps(n,1,(N+2)*3){
        mat Y= mat_mul(mat_pow(R, n-1),X);
        if(abs(Y[0][0]) < 0.000000000001) Y[0][0] = 0;
        if(abs(Y[1][0]) < 0.000000000001) Y[1][0] = 0;
        out5("(", Y[0][0], ",", Y[1][0] , ")")
    }
}

int main() {
    //test
    round();

    //mulsum
    // 1+A+A^2+...+A^(X-1) % M
    // 1000000000 1000000000000 998244353
    // 919667211
    //mulsum(1000000000, 1000000000000, 998244353);

    return 0;
}
