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
    string s;
    cin >> s;

    if(s[0] == s[1] && s[1] == s[2])
        cout << 1;
    else if(s[0] == s[1]|| s[2] == s[1] || s[2] == s[0])
        cout << 3;
    else 
        cout << 6;

    return 0;
}
