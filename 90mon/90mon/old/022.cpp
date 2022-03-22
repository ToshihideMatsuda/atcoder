//
//  022.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/19.
//
/*
 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;

 // Input
 long long A,B,C;

 long long gcd(long long X,long long Y){
     if(X%Y==0)return Y;
     if(Y%X==0)return X;
     if(X>Y) return gcd(X%Y,Y);
     return gcd(X,Y%X);
 }

 int main() {

     cin >> A >> B >> C;
     
     long long gcdAB=gcd(A,B);
     long long gcdBC=gcd(C,B);
     long long gcdABC= gcd(gcdAB, gcdBC);
     
     long long answer = (A/gcdABC-1)+(B/gcdABC-1)+(C/gcdABC-1);
     cout << answer << endl;
     
     return 0;
 }

 */
