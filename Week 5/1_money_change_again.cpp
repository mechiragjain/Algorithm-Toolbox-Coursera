#include <iostream>
#include<vector>

using namespace std;

int get_change(int m) {
  //write your code here
  int coins[3]={1,3,4};
  int NumCoins;

  vector<int> MinNumCoins(m+1,INT32_MAX);
  MinNumCoins[0]=0;
  for(int i=1;i<=m;i++){
    MinNumCoins[i]=INT32_MAX;
    for(int j=0;j<3;j++){
      if(i>=coins[j]){
        NumCoins=MinNumCoins[i-coins[j]]+1;
        if(NumCoins<MinNumCoins[i])
          MinNumCoins[i]=NumCoins;
      }
    }
  }

  return MinNumCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
