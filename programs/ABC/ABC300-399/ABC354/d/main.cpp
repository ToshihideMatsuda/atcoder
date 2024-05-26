#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    
    ll CA = C - A;
    A = ((A % 4) + 4) % 4;
    C = A + CA;
    
    ll DB = D - B;
    B = ((B % 2) + 2) % 2;
    D = B + DB;
    
    vector<ll> h(5);
    h[0] = (D / 2) * 3 + (D % 2 == 1 ? 2 : 0) - (B % 2 == 1 ? 2 : 0);
    h[1] = (D / 2) * 3 + (D % 2 == 1 ? 1 : 0) - (B % 2 == 1 ? 1 : 0);
    h[2] = (D / 2) * 1;
    h[3] = (D / 2) * 1 + (D % 2 == 1 ? 1 : 0) - (B % 2 == 1 ? 1 : 0);
    
    h[4] = h[0] + h[1] + h[2] + h[3];
    
    ll ans = 0;
    while (A % 4 != 0 && A < C) {
        ans += h[A % 4];
        A++;
    }
    
    ans += (C - A) / 4 * h[4];
    A += ((C - A) / 4) * 4;
    
    while ( A < C) {
        ans += h[A % 4];
        A++;
    }
    
    cout << ans << endl;
    return 0;
}