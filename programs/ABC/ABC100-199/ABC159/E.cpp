#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)

int main()
{
  ll H,W,K;cin>>H>>W>>K;
  vector<string>S(H+2);
  string z (W,'0');
  S[0] = z; S[H+1] = z;
  rep(i,H) cin >> S[i+1];


  ll ans = INF_LL;
  for(int i=0;i<(1<<(H-1));i++){
    ll tmp=0;
    vector<vector<ll>> wari;
    vector<ll> cur={1};
    int j=i*2;
    reps(h,1,H){
      if((j&(1<<h))>0){
        wari.push_back(cur);
        cur={h+1};
      }else{
        cur.push_back(h+1);
      }
    }
    wari.push_back(cur);
    tmp += wari.size() - 1;
    vector<ll> sum(wari.size(),0);

    rep(w,W){
      vector<ll> arr(wari.size(),0);
      rep(k,wari.size()){
        for(auto e:wari[k]) if(S[e][w]=='1') arr[k]++;
      }

      bool over = false;
      rep(k, arr.size()) {
        if(arr[k]>K){
          goto skip;
        } else if(arr[k] + sum[k] > K) {
          over = true;
        }
      }

      if(over) {
        tmp ++;
        sum = arr;
      } else {
        rep(k, arr.size()) sum[k] += arr[k];
      }
    }
    ans = MIN(ans,tmp);
    skip:
    continue;
  }

  out(ans)

  return 0;
}