#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int m[2] = {1, -1};
long long n, ans;

int main() {
  set <long long> visit;
  queue <long long> q;
  long long tmp, cnt = 1, tmpN;
  cin >> tmpN >> n;
  for(int i = 0; i <tmpN; i++) {
    cin >> tmp;
    visit.insert(tmp);
    q.push(tmp);
  }

  while(!q.empty()) {
    int size = q.size();
    for(int i = 0; i < size; i++) {
      int row = q.front();
      q.pop();
      for(int t = 0; t < 2; t++) {
        long long next = row + m[t];
        if(!visit.count(next)) {
          visit.insert(next);
          q.push(next);
          ans += cnt;
          n--;
          if(n == 0) {
            cout << ans;
            return 0;
          }
        }
      }
    }
    cnt++;
  }
}

//아니 시발 진짜 이것 때문에 틀리는거 말 되냐 엄마가 뒤졌네 진짜
// && ((-100000000 <= next) && (next <= 100000000))


// #include <iostream>
// #include <vector>
// #include <set>
// #include <queue>
// using namespace std;

// long long waterN, n, ans;

// int main() {
//   long long tmp, cnt = 1;
//   set <long long> visit;
//   queue <pair <long, long>> q;
//   cin >> waterN >> n;
//   for(int i = 0; i < waterN; i++) {
//     cin >> tmp;
//     visit.insert(tmp);
//     q.push(make_pair(tmp, 0));
//   }
//   while(true) {
//     int row = q.front().first, negativity = q.front().second;
//     q.pop();
//     if((-100000000 <= row + 1) && (row + 1 <= 100000000)) {
//       if(visit.insert(row + 1).second) {
//         n--;
//         ans += negativity + 1;
//         q.push(make_pair(row + 1, negativity + 1));
//       }
//       if(n == 0) break;
//     }
//     if((-100000000 <= row - 1) && (row - 1 <= 100000000)) {
//       if(visit.insert(row - 1).second) {
//         n--;
//         ans += negativity + 1;
//         q.push(make_pair(row - 1, negativity + 1));
//       }
//       if(n == 0) break;
//     }
//   }

//   cout << ans;
// }
//아니 나 진짜 얘 왜 안되는건지 모르겠어

// #include <iostream>
// #include <vector>
// #include <set>
// #include <queue>
// using namespace std;

// long long waterN, n, ans;

// int main() {
//   long tmp, cnt = 1;
//   set <long long> visit;
//   queue <long long> q;
//   cin >> waterN >> n;
//   for(int i = 0; i < waterN; i++) {
//     cin >> tmp;
//     visit.insert(tmp);
//     q.push(tmp);
//   }
//   bool sw = true;
//   while(sw) {
//     for(int i = 0; i < q.size(); i++) {
//       int row = q.front();
//       q.pop();
//       if((-100000000 <= row + 1) && (row + 1 <= 100000000)) {
//         if(visit.insert(row + 1).second) {
//           n--;
//           ans += cnt;
//           q.push(row + 1);
//         }
//         if(n == 0) {
//           // cout << "isBreak\n";
//           sw = false;
//           break;
//         }
//       }
//       if((-100000000 <= row - 1) && (row - 1 <= 100000000)) {
//         if(visit.insert(row - 1).second) {
//           n--;
//           ans += cnt;
//           q.push(row - 1);
//         }
//         if(n == 0) {
//           // cout << "isBreak  ||  " << ans << endl << endl;
//           sw = false;
//           break;
//         }
//       }
//     }
//     cnt++;
//   }

//   cout << ans;
// }
//얘도