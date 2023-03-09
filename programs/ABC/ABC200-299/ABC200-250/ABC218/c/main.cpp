#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>


#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 


typedef long long ll;
using namespace std;

#define MAX_N 200 + 5
#define INF 1 << 28

int N;

char S[MAX_N][MAX_N];
char T[MAX_N][MAX_N]; //固定


void moveToHead (char (&H)[MAX_N][MAX_N]) {

    int marginH = 0, marginW =0;
    reps(i,1,N+1) { 
        reps(j,1,N+1) if(H[i][j] == '#') goto nextCheck1;
        marginH++;
    }

    nextCheck1:

    reps(i,1,N+1) { 
        reps(j,1,N+1) if(H[j][i] == '#') goto nextCheck2;
        marginW++;
    }
    nextCheck2:


    reps(i,1,N+1) {
        if(i+marginH >= MAX_N) {
            rep(j,MAX_N) H[i][j] = '.'; 
        }
        else {
            rep(j,MAX_N) H[i][j] = H[i+marginH][j]; 
        }
    } 

    reps(i,1,N+1) {
        if(i+marginW >= MAX_N) {
            rep(j,MAX_N) H[j][i] = '.'; 
        }
        else {
            rep(j,MAX_N) H[j][i] = H[j][i+marginW]; 
        }
    } 
}


bool equalSandT() {
    /* T Move */ 
    moveToHead(T);

    /* S Move */ 
    moveToHead(S);

    reps(i,1,N+1) {
        reps(j,1,N+1) {
            if(S[i][j] !=  T[i][j]) return false;
        }
    }
    return true;
}

void rollingS() {
    char H[MAX_N][MAX_N];

    rep(i,MAX_N) rep(j,MAX_N) H[i][j] = '.'; 

    reps(i,1,N+1){ 
        reps(j,1,N+1)  { 
            H[N+1-j][i] = S[i][j];
        }
    }
    rep(i,MAX_N) rep(j,MAX_N) S[i][j] = H[i][j]; 
}


void debugPrint (char (&H)[MAX_N][MAX_N]) {

    cout << "---degug start---" << endl;
    reps(i,1,N+1){
        reps(j,1,N+1) cout <<  H[i][j];
        cout << endl;
    }
    cout << "---degug end---" << endl;
}


int main(){
    cin >> N;

    /*init*/ {
        rep(i,MAX_N) rep(j,MAX_N)  { 
            S[i][j] = '.'; 
            T[i][j] = '.'; 
        }

        reps(i,1,N+1) reps(j,1,N+1) {
            cin >>  S[i][j];
        }

        reps(i,1,N+1) reps(j,1,N+1) {
            cin >>  T[i][j];
        }
    }

    
    bool check =  equalSandT();

    rollingS();
    check |=  equalSandT();

    rollingS();
    check |=  equalSandT();

    rollingS();
    check |=  equalSandT();
    
    if(check) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}

