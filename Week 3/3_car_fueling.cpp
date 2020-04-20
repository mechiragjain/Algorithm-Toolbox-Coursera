#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int noOfRefills=0;
    int distTravel=0;
    int i;
    for(i=0;i<stops.size();i++){
      if(tank+distTravel<stops[i]){
        if(stops[i]-stops[i-1]>tank){
          break;
        }
        noOfRefills++;
        distTravel=stops[i-1];
      }
    }

    int n=stops.size()-1;

    if(tank+distTravel>=stops[n])
      return noOfRefills;
    return -1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+1);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);
    stops[n]=d;
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
