#include <iostream> 
#include <vector> 
using namespace std;

int main() {
int r,g,b,n,ans=0;
  cin>> r >>g>> b>>n;
  for(int i =0;i<=n/r;i++)
    for(int j =0;j<=(n-r*i)/b;j++)
      if((n-r*i-b*j)%g==0)ans++;
  cout << ans;
}