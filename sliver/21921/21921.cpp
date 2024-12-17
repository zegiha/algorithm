#include <iostream>

using namespace std;

int arr[250'001], n, x;

int main() {
  cin >> n >> x;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int ans_visiter = 0, ans_period = 0;
  for(int i = 0; i < x; i++) ans_visiter += arr[i];
  ans_period++;

  int prev_visiter = ans_visiter;
  for(int i = x; i < n; i++) {
    int new_visiter = prev_visiter - arr[i - x] + arr[i];
    if(new_visiter > ans_visiter) {
      ans_visiter = new_visiter;
      ans_period = 1;
    } else if(new_visiter == ans_visiter) {
      ans_period++;
    }
    prev_visiter = new_visiter;
  }

  if(ans_visiter == 0) {
    cout << "SAD";
  } else {
    cout << ans_visiter << '\n' << ans_period;
  }
}