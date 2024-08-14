// #include <iostream>
// #include <vector>

// using namespace std;

// int n, m, k;

// vector <pair <int, int>> cdn;
// vector <vector <vector <int>>> arr;

// pair <int, int> dir[8] = {
//   {-1, 0},
//   {-1, 1},
//   {0, 1},
//   {1, 1},
//   {1, 0},
//   {1, -1},
//   {0, -1},
//   {-1, -1},
// };
// pair <int, int> move_and_getNewCdn(int row, int col) {
//   pair <int, int> res = {row, col};
//   int s = arr[row][col][1], d = arr[row][col][2];

//   for(int t = 0; t < arr[row][col][1]; t++) {
//     res.first += dir[d].first;
//     res.second += dir[d].second;
//   }

//   vector <int> tmp = arr[row][col];
//   arr[row][col] = vector <int> ();
//   arr[res.first][res.second] = tmp;

//   return res;
// }

// int main() {
//   cin >> n >> m >> k;
//   arr.resize(n, vector <vector <int>> (n));
//   for(int i = 0; i < m; i++) {
//     int row, col, mass, speed, direction;
//     cin >> row >> col >> mass >> speed >> direction;
//     row--; col--;
//     cdn.push_back({row, col});
//     arr[row][col].push_back(mass);
//     arr[row][col].push_back(speed);
//     arr[row][col].push_back(direction);
//   }

//   while(k--) {
//     for(int i = 0; i < m; i++) {
//       cdn[i] = move_and_getNewCdn(cdn[i].first, cdn[i].second);
//     }
    
//   }
// }