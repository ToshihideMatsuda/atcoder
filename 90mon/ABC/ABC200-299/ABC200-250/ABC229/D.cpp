#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<pair<ll,ll>> v; 

int dp[2*100000 + 5]; 
//dp[i]:[0,i)の.の数

int main (){
    string s;
    int k;
    cin >> s >> k;

    dp[0] = 0;
    for(int i = 0; i < s.size(); i ++) {
        dp[i+1] = dp[i] +  (s[i] == '.' ? 1 : 0);
    }

    int i =0;


    int h = 0;
    int t = 0;

    int max = h - t;

    while(h < s.size()) {
        h ++;
        if(dp[h] - dp[t] > k) {
            t++;
        }
        else {
            max = max < h - t ? h - t :max;
        }
    }

    cout << max << endl;



	return 0;
}

