#include <iostream>
#include <vector>
#include <set>
#include <map>


#define MAX_N 200009

using namespace std;

int n =10;
int S =15;
vector<int> a = {5,1,3,5,10,7,4,9,2,8};


/*
int n =5;
int S =11;
vector<int> a = {1,2,3,4,5};
*/

//しゃくとり方
int main(){
    
    int to = 0,from = 0, sum = 0, ans = 1 << 28;

    while(true) {
        while(sum <= S) {
            if(to > n) goto loop_end;
            sum += a[to++];
        }
        if(to > n) goto loop_end;

        ans = min(ans, to - from);
        sum -= a[from++];
    }
    loop_end:

    cout << ans << endl;

    return 0;
}
