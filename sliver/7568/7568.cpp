#include <iostream>

using namespace std;

int main() {
  int n; cin >> n;
  pair <int, int> arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

  for(int i = 0; i < n; i++) {
    int rank = 1;
    for(int j = 0; j < n; j++) {
      if(i != j) {
        if(arr[i].first < arr[j].first && arr[i].second < arr[j].second) rank++;
      }
    }
    cout << rank << ' ';
  }
}

// #include <iostream>
// #include <vector>
// #include <iterator>

// using namespace std;

// struct WH {
//   int weight;
//   int height;
// };
// struct BS {
//   WH big;
//   WH small;
// };

// int n;
// vector <pair <BS, vector <int>>> arr;

// bool isBig(WH big, WH compare) {
//   if(big.weight < compare.weight && big.height < compare.height) return true;
//   return false;
// }
// bool isSmall(WH small, WH compare) {
//   if(small.weight > compare.weight && small.height > compare.height) return true;
//   return false;
// }

// int getRank(int index) {
//   int res = 0;
//   for(int i = 0; i < arr.size(); i++) {
//     for(int j = 0; j < arr[i].second.size(); j++) {
//       if(arr[i].second[j] == index) return res + 1;
//     }
//     res += arr[i].second.size();
//   }
// }

// int main() {
//   cin >> n;
  
//   arr.resize(1);
//   cin >> arr[0].first.big.weight >> arr[0].first.big.height;
//   arr[0].first.small = arr[0].first.big;
//   arr[0].second.push_back(0);

//   for(int index = 1; index < n; index++) {
//     WH in; cin >> in.weight >> in.height;
    
//     int i = 0;
//     while(true) {
//       if(isBig(arr[i].first.big, in)) {
//         arr.insert(arr.begin() + i, {
//           {in, in},
//           vector <int> (1, index)
//         });
//         break;
//       } else if (isSmall(arr[i].first.small, in)) {
//         if(i == arr.size() - 1) {
//           arr.push_back({
//             {in, in},
//             vector <int> (1, index)
//           });
//           break;
//         } else i++;
//       } else {
//         arr[i].second.push_back(index);
//         if(arr[i].first.big.weight < in.weight) arr[i].first.big.weight = in.weight;
//         if(arr[i].first.big.height < in.height) arr[i].first.big.height = in.height;
//         if(arr[i].first.small.weight > in.weight) arr[i].first.small.weight = in.weight;
//         if(arr[i].first.small.height > in.height) arr[i].first.small.height = in.height;
//         break;
//       }
//     }
//   }
  
//   for(int i = 0; i < n; i++) {
//     cout << getRank(i) << ' ';
//   }
// }