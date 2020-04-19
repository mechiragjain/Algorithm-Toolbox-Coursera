#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
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

long long fibonacci_sum(long long n) {

    n=n%pisano(10);
    if(n<=1)
      return n;
    long long first = 0;
    long long second = 1;

    long long res;
    long long sum=1;

    for (long long i = 2; i <= n; i++) {
        res = (first + second)%10;
        sum=(sum+res)%10;
        first = second;
        second = res;
    }

    return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n)<<" ";
    std::cout << fibonacci_sum(n);
}
