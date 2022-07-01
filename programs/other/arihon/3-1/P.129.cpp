#include <iostream>
#include <vector>
#include <set>
#include <map>


#define MAX_N 200009

using namespace std;


int N =4;
int K=11;
vector<double> L = {8.02, 7.43, 4.57, 5.39};
int main(){

    double max = 100000;
    double min = 0;
    double answer = (max + min)/2;

    int size = L.size();
    
    while( !(max - answer < 0.001 && answer - min < 0.001) ) {
        int honsuu = 0;
        int itr = 0;

        bool ok = true;
        while(true) {
            if(honsuu >= K){
                ok = true;
                break;
            }
            else if(itr >= size) {
                ok = false;
                break;
            }
            honsuu += (int)(L[itr++] / answer);
        }

        if(ok) {
            double tmp = answer;
            answer = (answer + max)/2;
            min = tmp;
        }
        else {
            double tmp = answer;
            answer = (answer + min)/2;
            max = tmp;
        }
    }

    printf("%.2f\n",answer * 100 / 100;

    return 0;
}
