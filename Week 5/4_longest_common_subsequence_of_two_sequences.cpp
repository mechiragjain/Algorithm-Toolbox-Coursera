#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
  
  int arr[a.size()+1][b.size()+1];

  for(int i=0;i<=a.size();i++){
    for(int j=0;j<=b.size();j++){
      if(i==0 || j==0)
        arr[i][j]=0;
      else if(a[i-1]==b[j-1])
        arr[i][j]=1+arr[i-1][j-1];
      else{
        arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
      }
    }
  }

  return arr[a.size()][b.size()];
}

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }

  size_t m;
  cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    cin >> b[i];
  }

  cout << lcs2(a, b) << std::endl;
}
