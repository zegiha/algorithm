#include <stdio.h>
int main() {
  int n, arr[51], ans = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

  for(int i = 0; i < n; i++) {
    int cnt = 0;
    double deg = 2100000000.0;
    for(int j = i + 1; j < n; j++) {
      double height = (double)(arr[i] - arr[j]), width = (double)(j - i);
      if(height / width < deg) {
        deg = height / width;
        cnt++;
      }
    }

    deg = 2100000000.0;
    for(int j = i - 1; j >= 0; j--) {
      double height = (double)(arr[i] - arr[j]), width = (double)(i - j);
      if(height / width < deg) {
        deg = height / width;
        cnt++;
      }
    }
    if(cnt > ans) ans = cnt;
  }
  printf("%d", ans);
}