//
//  main.cpp
//  testForAtCoder
//
//  Created by 松田敏秀 on 2021/10/12.
//

#include <iostream>

int h, w;

int matrix[1 << 11][1 << 11];
int sum[1 << 11];
int sumT[1 << 11];

int main() {
    // insert code here...
    
    std::cin >> h >> w;
    
    for (int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            std::cin >> matrix[i][j];
            sum[i] += matrix[i][j];
            sumT[j] += matrix[i][j];
        }
    }
    
    for (int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            int value = sum[i] + sumT[j] - matrix[i][j];
            if(j != 0){
                std::cout << " ";
            }
            std::cout << value;
        }
        std::cout << "\n";
    }
    
    return 0;
}
