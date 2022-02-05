#include <iostream>
#include <vector>
#include <map>

#define rep(i,n) for(int i =0; i < n;i ++)

#define MAX_N 805
#define MAX_A 1000000005

using namespace std;
typedef long long ll;

int A[MAX_N][MAX_N];

int main(){
	int n,k;
	cin >> n>>k;
	
    int canBiggerThanAns = (k*k)/2;  // Xよりも大きいものの個数の敷居値
    int S[n+1][n+1];               // mdよりも大きいものの個数の２次元累積和
    
    rep(i,n+1) {
        S[i][0] = 0;
        S[0][i] = 0; 
    }

    rep(i,n) {
        rep(j,n) cin >> A[i][j];
    }

    //最小の中間値を探す。そのために、敷居値よりも大きいものの個数がlim(k^2/2+1)以上であればOK
    int ok = MAX_A;
    int ng = -1; //AとしてAll 0もあり得るので-1とする

    while((ng + 1) < ok) {
        int md = (ok + ng) / 2;
        
        rep(i,n) rep(j,n) {
            if(md < A[i][j]) //mdよりも大きい数の個数の２次元累積和
                S[i+1][j+1] = S[i][j+1] + S[i+1][j] - S[i][j] + 1;
            else
                S[i+1][j+1] = S[i][j+1] + S[i+1][j] - S[i][j];
        }
/*
        cout << endl;
        string log = "---(md,ok,ng)=(" + to_string(md) + "," + to_string(ok) + "," + to_string(ng) + ")---";
        cout << log << endl;
        rep(i,n+1) {
            rep(j,n+1) {
                cout << S[i][j] << " ";
            }
            cout << endl;
        }
*/
        
        bool mdIsOK =false;　//xよりも大きいものが多いので、まだOKの値は下げられない。NGをあげる。

        rep(i,n-k+1) rep(j,n-k+1) {
            int bigger = S[i+k][j+k]-S[i][j+k] -S[i+k][j] + S[i][j];
            //cout << "(lim,bigger)=(" << lim << "," << bigger << ")" << endl;
            //cout << "(i,j)=(" << i << "," << j << ")" << endl;
            if(bigger <= canBiggerThanAns)  { //xよりも大きいものが少ないので、まだOKの値を下げられる。
                mdIsOK = true; goto loop_break;
            }
        }
loop_break:

        if(mdIsOK){
            ok =  md;
        }
        else {
            ng = md;
        }
    }

    cout << ok << endl;

	
	return 0;
}
