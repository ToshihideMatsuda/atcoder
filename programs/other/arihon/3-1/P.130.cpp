#include <iostream>
#include <vector>
#include <set>
#include <map>


#define MAX_N 200009

using namespace std;

int N =5;
int M =3;
vector<int> x = {1, 2, 8, 4, 9};
int main(){
    sort(x.begin(),x.end());

    int max = x[x.size() -1] - x[0];
    int min = 0;


    int tmp = (max + min)/2;
    int ans = -1;

    while(min != max) 
    {
        bool success = false;

        int cow = x[0];
        int cowCnt = 1;
        for(int i = 1; i < N; i++) {
            if(x[i] - cow >= tmp) {
                cowCnt++;
                cow = x[i];
            }

            if(cowCnt >= M) {
                success = true;
                break;
            }
        }

        if(success) {
            //より良い上限値を探す
            min = tmp + 1;
            tmp = (max + min)/2;
        }
        else {
            //解を小さい領域から探す。
            max = tmp - 1;
            tmp = (max + min)/2;
        }
    }

    cout << tmp << endl;

    return 0;
}
