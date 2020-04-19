#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long pisano(long long m){
  long long minusTwo=0,minusOne=1;
  long long result;
  for(int i=0;i<m*m;i++){
    result=(minusOne+minusTwo)%m;
    minusTwo=minusOne;
    minusOne=result;
    if(minusOne==1 && minusTwo==0)
      return i+1;
  }
  return 0;
}


long long get_fibonacci_huge(long long n, long long m) {
  long long period = pisano(m);
  //std::cout<<period<<std::endl;
  n=n%period;
  if(n<=1)
    return n;
  long long minusTwo=0, minusOne=1, result=minusOne+minusTwo;
  for(int i=1;i<n;i++){
    result=(minusOne+minusTwo)%m;
    minusTwo=minusOne;
    minusOne=result;
  }
  return (result%m);
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
    return 0;
}
