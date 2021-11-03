#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;

#define MAX_N  2*100000 + 10
int N;
long long a[MAX_N];
long long s[MAX_N];
unordered_map<long long,long long> cnt;


int main(){
    cin >> N;
    s[0] = 0;
    cnt[s[0]] += 1; 
    for(int i = 1; i< N+1; i++) {
        cin >> a[i]; 
        s[i] = a[i] + s[i-1];
        cnt[s[i]] += 1; 
    }

    long long sum = 0;

    for (auto pair : cnt) {
        sum = sum + pair.second * (pair.second - 1) / 2;
    }

    cout << sum << endl;

    return 0;
}
