#include <iostream>

int get_change(int m) {
  //write your code here
  int n=0;
  while(m>=0){
    if(m==0){
      return n;
    }
    if(m>0){
      n=n+(m/10);
      m=m-(m/10)*10;
      n=n+(m/5);
      m=m-(m/5)*5;
      n=n+(m/1);
      m=m-(m/1);
    }
    
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
