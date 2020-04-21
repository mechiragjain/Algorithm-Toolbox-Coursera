#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  int ed[str1.length()+1][str2.length()+1];

  for(int i=0;i<=str1.length();i++){
    for(int j=0;j<=str2.length();j++){
      if(i==0)
        ed[i][j]=j;
      else if(j==0)
        ed[i][j]=i;
      else if(str1[i-1]==str2[j-1])
        ed[i][j]=ed[i-1][j-1];
      else
        ed[i][j]=1+min(min(ed[i][j-1],ed[i-1][j]),ed[i-1][j-1]);
    }
  }

  return ed[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
