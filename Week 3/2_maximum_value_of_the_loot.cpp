#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using std::vector;
using namespace std;

/*double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  sort(valuePerUnit.begin(), valuePerUnit.end()); 

  while(capacity>=0){
    if(capacity==0){
      return value;
    }

  }

  return value;
}*/

int main() {
  int n;
  int capacity;
  double values=0.0;
  std::cin >> n >> capacity;
  vector<pair<int,int>> valuesWeight(n);
  vector<pair<double,int>> valuePerUnit(n);
  for (int i = 0; i < n; i++) {
    std::cin >> valuesWeight[i].first >> valuesWeight[i].second;
    valuePerUnit[i].first=1.00*valuesWeight[i].first/valuesWeight[i].second;
    valuePerUnit[i].second=valuesWeight[i].second;
  }

 	sort(valuePerUnit.begin(), valuePerUnit.end(),greater<pair<double,int>>());

  for(int i=0;i<valuePerUnit.size() && capacity>0;i++){
    values=values+min(valuePerUnit[i].second, capacity)*valuePerUnit[i].first;
    capacity-=min(valuePerUnit[i].second, capacity);
  }

  //double optimal_value = get_optimal_value(capacity, weights, values);

  //std::cout.precision(10);
  std::cout<<fixed<<setprecision(10)<<values<< std::endl;
  return 0;
}
