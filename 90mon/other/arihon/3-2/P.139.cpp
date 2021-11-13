#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;



int N=14;
string cows ="BBFBFFBBFBFBBB";



int rev[15];

int check(int k) {

    for(int i = 0; i < N; i ++)rev[i] = 1;

    int ret = 0;
    int curRev = 1; //前向き:1 後ろ向き:-1
    for(int i = 0; i + k <= N; i++) {
        bool cowB = (curRev == 1  && cows[i] == 'B') ||
                    (curRev == -1 && cows[i] == 'F');     

        // 牛が後ろを向いている場合には機械を動作させる
        if(cowB) {
            ret ++;
            rev[i] = -1;

            //掛け合わせてムキを合わせる
            curRev = curRev * rev[i];
        }
        

        if(i - k + 1 >= 0) // K匹前の牛のrevの影響をなくす
        {
            curRev = curRev * rev[i-k+1] ;   
        }
    }

    //N-k番目から
    for(int i = N-k+1; i < N; i++) {
        bool cowB = (curRev == 1  && cows[i] == 'B') ||
                    (curRev == -1 && cows[i] == 'F');     

        // 後ろムキの牛が存在
        if(cowB) {
            return -1;
        }

        if(i - k + 1 >= 0) // K匹前の牛のrevの影響をなくす
        {
            curRev = curRev * rev[i-k+1] ;   
        }
    }
    return ret;
}

int main(){
    
    int M=1 << 28,K=0; 
    for(int k = 1; k <= N; k ++) {
        int m =check(k);
        if(m > 0) {
            if(M > m) {
                M =m;
                K =k;
            }
        }
    }
    cout << M << " " << K << endl;

    return 0;
}
