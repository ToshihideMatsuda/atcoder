#include<iostream>
typedef long long ll;

//aとbの最大公約数を計算
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

//aとbの最小公倍数
ll lcm(ll a, ll b) {
    return a*b/gcd(a,b);
}


//拡張ユークリッドの互除法
//ax+by=gcd(a,b)を計算（正直理解しづらい。。。）
ll extgcd(ll a, ll b, ll& x, ll& y) {
    int d = a;
    if(b !=0) {
        
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;    
    }
    else {
        //最終項
        x = 1;
        y = 0;
    }
    return d;
}


//拡張ユークリッドの互除法２(筆算形式)
//初期値a, bをどう組み合わせるとr_n-1,r_nになるのかをaxy, bxyで保持し続ける 
pair<ll , ll>xyAns;
ll extgcd2_aux(ll a, ll b, pair<ll , ll>axy, pair<ll, ll>bxy, bool swaped) {

    if(b == 0){
        //逆順になっているので元の順序に戻しておく
        if(swaped) {
            axy = {axy.second, axy.first};
        }
        xyAns = axy;
        return a;
    }
    else{
        ll q = a/b;
        ll r = a%b;
        return extgcd2_aux(
            b, 
            r, 
            bxy, //初項を表現するベクトル
            {axy.first - bxy.first*q, axy.second * q - bxy.second*q}, //第二項を表現するベクトル
            swaped);
    }
}

ll extgcd2(ll a, ll b) {
    bool swaped = a < b;
    if(swaped) swap(a, b);
    return extgcd2_aux(a,b,{1,0}, {0,1}, swaped);
}

void debuggcd(){

    cout << " gcd(2,5) = " << gcd(2,5) << endl;
    cout << " gcd(5,3) = " << gcd(5,2) << endl;


    cout << " gcd(15,10) = " << gcd(15,10) << endl;
    cout << " gcd(28,21) = " << gcd(28,21) << endl;

}

void debugextgcd(){
    ll x,y;
    cout << " extgcd(2,5,x,y) = " << extgcd(2,5,x,y) << endl;
    cout << "(x,y)=(" << x << "," << y << ")" << endl; 
    cout << " extgcd(5,3,x,y) = " << extgcd(5,3,x,y) << endl;
    cout << "(x,y)=(" << x << "," << y << ")" << endl; 

    cout << " extgcd(15,10,x,y) = " << extgcd(15,10,x,y) << endl;
    cout << "(x,y)=(" << x << "," << y << ")" << endl; 
    cout << " extgcd(28,21,x,y) = " << extgcd(28,21,x,y) << endl;
    cout << "(x,y)=(" << x << "," << y << ")" << endl; 
}
void debugextgcd2(){

    cout << " extgcd2(2,5) = " << extgcd2(2, 5) << endl;
    cout << "(x,y)=(" << xyAns.first << "," << xyAns.second << ")" << endl; 
    cout << " extgcd2(5,3) = " << extgcd2(5, 3) << endl;
    cout << "(x,y)=(" << xyAns.first << "," << xyAns.second << ")" << endl; 

    cout << " extgcd2(15,10) = " << extgcd2(15, 10) << endl;
    cout << "(x,y)=(" << xyAns.first << "," << xyAns.second << ")" << endl; 
    cout << " extgcd2(28,21) = " << extgcd2(28, 21) << endl;
    cout << "(x,y)=(" << xyAns.first << "," << xyAns.second << ")" << endl; 
    cout << " extgcd2(21,35) = " << extgcd2(35, 21) << endl;
    cout << "(x,y)=(" << xyAns.first << "," << xyAns.second << ")" << endl; 
    cout << " extgcd2(192,54) = " << extgcd2(192, 54) << endl;
    cout << "(x,y)=(" << xyAns.first << "," << xyAns.second << ")" << endl; 
    cout << " extgcd2(54,192) = " << extgcd2(54, 192) << endl;
    cout << "(x,y)=(" << xyAns.first << "," << xyAns.second << ")" << endl; 

}