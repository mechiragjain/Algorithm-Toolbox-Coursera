#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  //if (left == right) return -1;
  //if (left + 1 == right) return a[left];

  //write your code here
  int n=a.size();
  map<int, int> frequencyOfElements;

  for(int i=0;i<n;i++){
    frequencyOfElements[a[i]]++;
  }

  for(int i=0;i<n;i++){
    if(frequencyOfElements[a[i]]>n/2){
      return 1;
    }
  }

  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size())) << '\n';
}
