#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}
int main()
{
    ll H, W, R, C;
    cin >> H >> W >> R >> C;

    if(H == 1 && W == 1) {
        cout << 0 << endl;
        return 0;
    } else if(H == 1) {
        if(C == 1 || C == W) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
        return 0;
    } else if(W == 1) {
        if(R == 1 || R == H) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
        return 0;
    } else if(
        (R == 1 && C == 1) ||
        (R == 1 && C == W) ||
        (R == H && C == 1) ||
        (R == H && C == W)
    ){
        cout << 2 << endl;
        return 0;
    } else if(
        R == 1 || R == H || 
        C == 1 || C == W
    ) {
        cout << 3 << endl;
        return 0;
    }

    cout << 4 << endl;

	return 0;
}