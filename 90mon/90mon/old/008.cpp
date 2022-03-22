//
//  main.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/12.
//

/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mod = (1000) * (1000) * (1000) + 7;
char atcoder[] = {'a','t','c','o','d','e','r'};

int main(){
    int n;
    cin >> n;
    char s[n];
    cin >> s;
    
    int dp[n];
    for (int i = 0; i < n; i ++) dp[i] = 0;
    int allSum = 0;
    
    for (int c = 0; c < 6; c++) {
        char ch = atcoder[c];
        char nxt = atcoder[c+1];
        int sumCh = 0;
        for (int i = 0; i < n; i ++) {
            if(s[i] == ch)
            {
                if(ch == 'a'){
                    sumCh ++;
                } else {
                    sumCh += dp[i];
                    sumCh %= mod;
                }
            } else if(s[i] == nxt) {
                dp[i] = sumCh;
                if(nxt == 'r') {
                    allSum += sumCh;
                    allSum %= mod;
                }
            }
        }
    }
    
    std::cout << allSum ;

    return 0;
}
*/
