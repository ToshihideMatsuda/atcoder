//
//  main.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/12.
//
/*
#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n,a,b,c;
    vector<int> coin;
    std::cin >> n>> a >> b >> c;
     
    coin.push_back(a);
    coin.push_back(b);
    coin.push_back(c);
    
    std::sort(coin.begin(), coin.end(),greater<int>());
    
    int minCoin = INT_MAX;
    
    for(int i = 0; i < 10000; i++) {
        
        if(coin[0] * i > n){
            break;
        }
        
        for(int j = 0; j < 10000; j++) {
            if(coin[0] * i + coin[1] * j > n){
                break;
            }
            
            int k = (n - coin[0] * i - coin[1] * j) / coin[2];

            if( n ==  coin[0] * i + coin[1] * j + coin[2] * k ){
                
                if(minCoin > i + j + k) {
                    minCoin = i + j + k;
                }
                
            }
            
        }
    }
    
    std::cout << minCoin;
        
    return 0;
}
*/
