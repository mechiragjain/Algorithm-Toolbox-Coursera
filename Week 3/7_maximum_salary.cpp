#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>

using std::vector;
using std::string;

bool IsGreaterOrEqual(string &first, string &second){
  return (second+first>first+second);
}

string largest_number(vector<string> a) {
  //write your code here
  int n=a.size();
  for(size_t i=0;i<n;i++){
    for(size_t j=i+1;j<n;j++){
      if(IsGreaterOrEqual(a[i],a[j])){
        swap(a[i],a[j]);
      }
    }
  }
  
  
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
     ret << a[i];
   }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
