//
//  main.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/12.
//
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<long long> A,B;

int main(){
    std::cin >> n;
    long long a,b;
    for (int i = 0; i < n; i ++) {
        std::cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < n; i ++) {
        std::cin >> b;
        B.push_back(b);
    }
    
    std::sort(A.begin(),A.end(), less<long long>());
    std::sort(B.begin(),B.end(), less<long long>());
    
    long long sum = 0;
    for (int i = 0; i < n; i ++) {
        sum += (A[i] - B[i]) * ((A[i] > B[i]) ? 1 : -1);
    }
    
    std::cout << sum;

    return 0;
}
*/
