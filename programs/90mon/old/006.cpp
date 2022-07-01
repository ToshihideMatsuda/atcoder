

//  main.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/12.
//
/*
#include <iostream>

using namespace std;

int main(){
    
    int n,k;
    string s;
    cin >> n >> k >> s;
    string tmpk = s.substr(0,k);
    
    int kcur = 0;
    
    for(int i = k; i < n; i++) {
        string ch = s.substr(i,1);
        string newStr = tmpk + ch;
        
        while(newStr.substr(kcur,1).c_str()[0] <= newStr.substr(kcur + 1,1).c_str()[0] &&
              kcur < k){
            kcur ++;
        }
        
        newStr.erase(kcur,1);
        if(kcur > 0) kcur--;
        tmpk = newStr;
    }

    std::cout << tmpk;
    std::cout << "\n";
    

    return 0;
}

*/
