#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;



int N=7;
vector<int> a = {1,8,8,8,1};


int main(){
    
    set<int> s;
    for(auto v :a) {
        s.insert(v);
    }

    int n = s.size();   // 全体のサイズ
    int to = 0,from = 0,num=0, ans = 1<<28;
    unordered_map<int,int> cnt;


    while(true) {
        while(num < n) {
            if(to >= a.size()) goto loop_end;            
            if(cnt[a[to]]==0) num++;
            cnt[a[to]]++; // 回数カウント
            to++;
        }
        ans = min(ans, to - from);
        cnt[a[from]] -= 1;
        if(cnt[a[from]] <= 0) {
            num--;
        }
        from ++;
    }
    loop_end:

    cout << ans << endl;

    return 0;
}
