#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector <pair <long long, long long>> arr;
double ans;

int main() {
  scanf("%d", &n); arr.resize(n);
  for(int i = 0; i < n; i++) scanf("%ld %ld", &arr[i].first, &arr[i].second);


  for(int i = 0; i < n - 1; i++) {
    ans += ((double)arr[i].first + (double)arr[i + 1].first) * ((double)arr[i].second - (double)arr[i + 1].second);
  }
  ans += ((double)arr[n - 1].first + (double)arr[0].first) * ((double)arr[n - 1].second - (double)arr[0].second);

  ans /= 2.0;
  
  ans = round(ans * 10.0) / 10.0;

  if(ans < 0) ans *= -1;

  printf("%.1lf", ans);
}
