#include <iostream>

using namespace std;

int n, ans;

void isSimilar(int sum) {
  int sumSimilar = sum - 100 > 0 ? sum - 100 : (sum - 100) * -1;
  int similar = ans - 100 > 0 ? ans - 100 : (ans - 100) * -1;
  if(sumSimilar < similar) ans = sum;
  else if((sumSimilar == similar) && sum > ans) ans = sum;
}

int main() {
  for(int i = 0; i < 10; i++) {
    int t;
    cin >> t;
    n += t;
    isSimilar(n);
  }
  cout << ans;
}

// #include <iostream>
// #include <algorithm>

// using namespace std;

// int arr[10], ans;

// void isSimilar(int sum) {
//   int sumSimilar = sum - 100 > 0 ? sum - 100 : (sum - 100) * -1;
//   int similar = ans - 100 > 0 ? ans - 100 : (ans - 100) * -1;
//   if(sumSimilar < similar) ans = sum;
//   else if((sumSimilar == similar) && sum > ans) ans = sum;
// }

// void solve(int index, int sum, int cnt) {
//   if(cnt == 10) return;
//   isSimilar(sum);
//   for(int i = index; i < 10; i++) {
//     solve(i + 1, sum + arr[i], cnt + 1);
//   }
// }

// int main() {
//   for(int i = 0; i < 10; i++) cin >> arr[i];
  
//   // sort(arr, arr + 10);
//   for(int i = 0; i < 10; i++) {
//     solve(i + 1, arr[i], 1);
//   }
//   cout << ans;
// }