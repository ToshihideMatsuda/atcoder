#include<iostream>

//aとbの最大公約数を計算
long long gcd(long long a, long long b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

//拡張ユークリッドの互除法
//ax+by=gcd(a,b)を計算（正直理解しづらい。。。）
long long extgcd(long long a, long long b, long long& x, long long& y) {
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
pair<long long , long long>xyAns;
long long extgcd2_aux(long long a, long long b, pair<long long , long long>axy, pair<long long, long long>bxy, bool swaped) {

    if(b == 0){
        //逆順になっているので元の順序に戻しておく
        if(swaped) {
            axy = {axy.second, axy.first};
        }
        xyAns = axy;
        return a;
    }
    else{
        long long q = a/b;
        long long r = a%b;
        return extgcd2_aux(
            b, 
            r, 
            bxy, //初項を表現するベクトル
            {axy.first - bxy.first*q, axy.second * q - bxy.second*q}, //第二項を表現するベクトル
            swaped);
    }
}

long long extgcd2(long long a, long long b) {
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
    long long x,y;
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