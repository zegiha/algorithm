#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, arr[200][200], s, x, y;

void addToQ(vector <pair <int, pair <int, int>>> add, queue <pair <int, pair <int, int>>>* q) {
  sort(add.begin(), add.end());
  for(int i = 0; i < add.size(); i++) q->push(add[i]);
}
vector <pair <int, pair <int, int>>> getAdd(int v, int r, int c) {
  vector <pair <int, pair <int, int>>> ret;
  if(r + 1 < n) {
    if(arr[r + 1][c] == 0) {
      arr[r + 1][c] = v;
      ret.push_back(make_pair(v, make_pair(r + 1, c)));
    }
  }
  if(r - 1 >= 0) {
    if(arr[r - 1][c] == 0) {
      arr[r - 1][c] = v;
      ret.push_back(make_pair(v, make_pair(r - 1, c)));
    }
  }
  if(c + 1 < n) {
    if(arr[r][c + 1] == 0) {
      arr[r][c + 1] = v;
      ret.push_back(make_pair(v, make_pair(r, c + 1)));
    }
  }
  if(c - 1 >= 0) {
    if(arr[r][c - 1] == 0) {
      arr[r][c - 1] = v;
      ret.push_back(make_pair(v, make_pair(r, c - 1)));
    }
  }
  return ret;
}

void print() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}

int main() {
  vector <pair <int, pair <int, int>>> add;
  queue <pair <int, pair <int, int>>> q;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> arr[i][j];
      if(arr[i][j] != 0) add.push_back({arr[i][j], {i, j}});
    }
  }
  cin >> s >> y >> x; y--; x--;
  addToQ(add, &q);

  while(s-- && !q.empty()) {
    int size = q.size();
    for(int t = 0; t < size; t++) {
      int v = q.front().first, r = q.front().second.first, c = q.front().second.second;
      q.pop();
      addToQ(getAdd(v, r, c), &q);
      // print();
    }
  }
  cout << arr[y][x];
}

// #include <iostream>
// #include <queue>

// using namespace std;

// int n, k, arr[200][200], s, x, y;

// struct cmp{
//     bool operator()(pair <int, pair <int, int>> a, pair <int, pair <int, int>> b){
//         return a.first > b.first;
//     }
// };

// void addToQ(priority_queue <pair <int, pair <int, int>>, vector <pair <int, pair <int, int>>>, cmp>* q, int v, int r, int c) {
//   if(r + 1 < n) {
//     if(arr[r + 1][c] == 0) {
//       arr[r + 1][c] = v;
//       q->push(make_pair(v, make_pair(r + 1, c)));
//     }
//   }
//   if(r - 1 >= 0) {
//     if(arr[r - 1][c] == 0) {
//       arr[r - 1][c] = v;
//       q->push(make_pair(v, make_pair(r - 1, c)));
//     }
//   }
//   if(c + 1 < n) {
//     if(arr[r][c + 1] == 0) {
//       arr[r][c + 1] = v;
//       q->push(make_pair(v, make_pair(r, c + 1)));
//     }
//   }
//   if(c - 1 >= 0) {
//     if(arr[r][c - 1] == 0) {
//       arr[r][c - 1] = v;
//       q->push(make_pair(v, make_pair(r, c - 1)));
//     }
//   }
// }

// void print() {
//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < n; j++) {
//       cout << arr[i][j] << ' ';
//     }
//     cout << '\n';
//   }
//   cout << '\n';
// }

// int main() {
//   priority_queue <pair <int, pair <int, int>>, vector <pair <int, pair <int, int>>>, cmp> q;
//   cin >> n >> k;
//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < n; j++) {
//       cin >> arr[i][j];
//       if(arr[i][j] != 0) q.push(make_pair(arr[i][j], make_pair(i, j)));
//     }
//   }
//   cin >> s >> x >> y; x--; y--;

//   while(s-- && !q.empty()) {
//     int size = q.size();
//     for(int t = 0; t < size; t++) {
//       int v = q.top().first, r = q.top().second.first, c = q.top().second.second;
//       q.pop();
//       cout << v << "  ||  " << r << ' ' << c << '\n';
//       addToQ(&q, v, r, c);
//       print();
//     }
//   }
//   cout << arr[x][y];
// }

// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// int n, k, arr[200][200], s, x, y;

// void addToQ(queue <pair <int, pair <int, int>>>* q, int v, int r, int c) {
//   if(r + 1 < n) {
//     if(arr[r + 1][c] > v || arr[r + 1][c] == 0) {
//       arr[r + 1][c] = v;
//       q->push(make_pair(v, make_pair(r + 1, c)));
//     }
//   }
//   if(r - 1 >= 0) {
//     if(arr[r - 1][c] > v || arr[r - 1][c] == 0) {
//       arr[r - 1][c] = v;
//       q->push(make_pair(v, make_pair(r - 1, c)));
//     }
//   }
//   if(c + 1 < n) {
//     if(arr[r][c + 1] > v || arr[r][c + 1] == 0) {
//       arr[r][c + 1] = v;
//       q->push(make_pair(v, make_pair(r, c + 1)));
//     }
//   }
//   if(c - 1 >= 0) {
//     if(arr[r][c - 1] > v || arr[r][c - 1] == 0) {
//       arr[r][c - 1] = v;
//       q->push(make_pair(v, make_pair(r, c - 1)));
//     }
//   }
// }

// int main() {
//   queue <pair <int, pair <int, int>>> q;
//   cin >> n >> k;
//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < n; j++) {
//       cin >> arr[i][j];
//       if(arr[i][j] != 0) q.push(make_pair(arr[i][j], make_pair(i, j)));
//     }
//   }
//   cin >> s >> x >> y; x--; y--;
//   while(s-- && !q.empty()) {
//     int size = q.size();
//     for(int t = 0; t < size; t++) {
//       int v = q.front().first, r = q.front().second.first, c = q.front().second.second;
//       q.pop();
//       addToQ(&q, v, r, c);
//     }
//   }
//   cout << arr[x][y];
// }