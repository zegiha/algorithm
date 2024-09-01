#include <iostream>
#include <algorithm>

using namespace std;

int n = 500001, arr[500001];

int getR(int find) {
  int l = 0, r = n - 1, mid;
  while(l <= r) {
    mid = (r - l) / 2 + l;
    if(arr[mid] > find) {
      r = mid - 1;
    } else if(arr[mid] < find) {
      l = mid + 1;
    } else if(arr[mid] == find) {
      if(mid != n - 1 && arr[mid + 1] == find) {
        l = mid + 1;
      } else {
        return mid;
      }
    }
  }
  return -1;
}
int getL(int find) {
  int l = 0, r = n - 1, mid;
  while(l <= r) {
    mid = (r - l) / 2 + l;
    if(arr[mid] > find) {
      r = mid - 1;
    } else if(arr[mid] < find) {
      l = mid + 1;
    } else if(arr[mid] == find) {
      if(mid != 0 && arr[mid - 1] == find) {
        r = mid - 1;
      } else {
        return mid;
      }
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int t; cin >> t;
  while(t--) {
    int f, l, r; cin >> f;
    l = getL(f);
    if(l != -1) {
      r = getR(f);
      cout << r - l + 1 << ' ';
    } else {
      cout << 0 << ' ';
    }
  }
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     int N, M;
//     cin >> N;
//     vector<int> cards(N);
//     for (int i = 0; i < N; ++i) {
//         cin >> cards[i];
//     }
    
//     cin >> M;
//     vector<int> queries(M);
//     for (int i = 0; i < M; ++i) {
//         cin >> queries[i];
//     }
    
//     sort(cards.begin(), cards.end());
    
//     for (int i = 0; i < M; ++i) {
//         auto lower = lower_bound(cards.begin(), cards.end(), queries[i]);
//         auto upper = upper_bound(cards.begin(), cards.end(), queries[i]);
//         cout << upper - lower << " ";
//     }
    
//     return 0;
// }