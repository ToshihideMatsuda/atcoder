//
//  main.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/12.
//
#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <map>
#include <regex>
#include <cmath>

using namespace std;

#define MOD 998244353

long long power(long long a,long long b, long long mod){
  long long x=1,y=a;
  while(b>0){       
    if(b & 1ll){    //bの最下位ビットが1　
      x=(x*y)%mod;  //そのビットの冪乗をかける
    }
    y=(y*y)%mod;    //yはa, a^2, a^4, a^8, ^16 と冪乗の、2の冪乗で増える
    b>>=1;          //bをビット減らす
  }
  return x%mod;     // b=00010111 (=23)_10の場合、x = a * a^2 * a^4 * a^16 =x^(1+2+4+16)=x^23
}


int main(){
  
  string s;
  cin >> s;
  if(s.size()==1){cout << s << '\n';return 0;} //パターン数2^0の場合


  long long res=0, //最終結果
  del=1,
  cur=0;

  vector<long long> debug;


  //ここの漸化式難しい。分母は2で固定で、分子のみ計算している
  //期待値をresに算出  
  for(int i=s.size()-1;i>=0;i--){ //最終項から見る
    //以下では、del=125, 
    //ce=1+5+25+125+125=261となるように計算している。そして、261/2 * 2^k-2 が下から4けための通り数


    cur+=del;cur%=MOD;          

    long long ce=(cur+del)%MOD;
    
    
    res+=(s[i]-'0')*ce; // s[i]-'0'は つまりstoi(s[i])
    res%=MOD;

    debug.push_back((s[i]-'0')*ce);

    cout << "cur:" <<cur << ", del:" << del << ", ce:" << ce << ", (s[i]-'0')*ce:" << debug.back() << ", res:" << res << endl;
     del*=5;del%=MOD;
  }


  res*=power(2,s.size()-2,MOD);res%=MOD;


  cout << res << '\n';
  return 0;
}
