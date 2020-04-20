#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

void partition3(vector<int> &a, int left, int right, int &i,int &j){
  int pivot=a[left];
  int p=left;
  for(int s=left+1;s<=right;s++){
    if(a[s]<=pivot){
      p++;
      swap(a[s],a[p]);
    }
  }

  swap(a[left],a[p]);

  i=p-1;
  for(int s=left;s<p && i>=left && i>s;){
    if(a[p]==a[s]){
      swap(a[s],a[i]);
      i--;
    }
    else{
      s++;
    }
  }
  i++;
  j=p;
}

void quickSort(vector<int> &a,int left,int right){
  if(left>=right)
    return;
  int i,j;
  partition3(a,left,right,i,j);

  quickSort(a,left,i-1);
  quickSort(a,j+1,right);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  //randomized_quick_sort(a, 0, a.size() - 1);
  quickSort(a,0,a.size()-1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
