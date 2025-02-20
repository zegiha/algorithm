#include <iostream>
#include <cmath>

using namespace std;
using d = double;

int n, k, arr[501];
d ans = 2'100'000'000.0;

d pow_custom(d a) {
  return a * a;
}

d abs_custom(d a) {
  if(a < 0.0) return a * -1.0;
  return a;
}

d min_custom(d a, d b) {
  if(a < b) return a;
  return b;
}

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> arr[i];
  
  for(int i = 0; i <= n - k; i++) {
    for(int j = i + k; j <= n; j++) {
      d sum = 0.0, avg, sum2 = 0.0, avg2;

      for(int ii = i; ii < j; ii++) sum += arr[ii];
      avg = sum / ((d)(j - i));

      for(int ii = i; ii < j; ii++) sum2 += pow_custom(((d)arr[ii]) - avg);
      avg2 = sum2 / ((d)(j - i));

      ans = min_custom(ans, abs_custom(sqrt(avg2)));
    }
  }

  printf("%.11lf", ans);
}