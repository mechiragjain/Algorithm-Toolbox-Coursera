#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> correct_sequence(int n){
  vector<int> sequence;
  int *arr = new int[n + 1];
  arr[0]=0;
  arr[1]=1;

  for(int i=2;i<n+1;i++){
    arr[i]=arr[i-1]+1;
    if(i%2==0){
      arr[i]=min(arr[i],arr[i/2]+1);
    } else if(i%3==0){
      arr[i]=min(arr[i],arr[i/3]+1);
    }
  }

  for(int i=n;i>1;){
    sequence.push_back(i);
    if(arr[i-1]==arr[i]-1){
      i-=1;
    } else if(i%2==0 && arr[i/2]==arr[i]-1){
      i/=2;
    } else if(i%3==0 && arr[i/3]==arr[i]-1){
      i/=3;
    }
  }
  if(n>=1){
    sequence.push_back(1);
    reverse(sequence.begin(),sequence.end());
  }
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  if(n<=0){
    cout<<0<<endl;
    cout<<0<<endl;
    return 0;
  }
  //vector<int> sequence = optimal_sequence(n);
  vector<int> sequence = correct_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
