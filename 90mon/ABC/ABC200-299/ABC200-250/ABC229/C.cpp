#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<pair<ll,ll>> v; 

int main (){
    ll n,w;
    cin >> n >> w;
    ll a,b;
    for(int i =0 ;i < n; i ++) {
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end(),greater<pair<ll,ll>>());

    ll oisisa = 0;
    int indx = 0;
    while(w > 0) {

        auto vv = v[indx];
        ll va = vv.first;
        ll vb = vv.second;

        if(w >= vb) {
            oisisa += va * vb;
            w = w - vb;
        } else {
            oisisa += va * w;
            w = 0;
            break;
        }
        indx ++;

        if(v.size() <= indx)
            break;
    }

    cout << oisisa << endl;


	return 0;
}