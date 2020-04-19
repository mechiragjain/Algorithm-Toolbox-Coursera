#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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

long long get_fibonacci_partial_sum(long long from, long long to) {
    long long period=pisano(10);

    to=to%period;
    from=(from)%period;

    if(to<from)
      to+=period;

    long long first = 0;
    long long second = 1;

    long long res;
    long long sum=0;

    for (long long i = 0; i <= to; i++) {
        if(i>=from){
          sum=(sum+first)%10;
        }
        res = (first + second)%10;
        first = second;
        second = res;
    }

    return sum%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
