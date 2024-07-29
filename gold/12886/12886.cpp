#include <iostream>
#include <queue>

using namespace std;

bool visit[1501][1501];

bool solve(int a, int b, int c) {
  if((a + b + c) % 3 != 0) return false;

  queue <vector <int>> q;
  q.push({a, b, c});
  visit[a][b] = true;

  while(!q.empty()) {
    vector <int> f = q.front(); q.pop();
    a = f[0];
    b = f[1];
    c = f[2];

    if(a == b && b == c) return true;

    if(a != b) {
      int newA = a > b ? a - b : a + a;
      int newB = a > b ? b + b : b - a;

      if(!visit[newA][newB]) {
        q.push({newA, newB, c});
        visit[newA][newB] = true;
      }
    }

    if(a != c) {
      int newA = a > c ? a - c : a + a;
      int newC = a > c ? c + c : c - a;

      if(!visit[newA][newC]) {
        q.push({newA, b, newC});
        visit[newA][newC] = true;
      }
    }

    if(b != c) {
      int newB = b > c ? b - c : b + b;
      int newC = b > c ? c + c : c - b;

      if(!visit[newB][newC]) {
        q.push({a, newB, newC});
        visit[newB][newC] = true;
      }
    }
  }

  return false;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  cout << solve(a, b, c) ? 1 : 0;
}

// #include <iostream>
// #include <queue>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int maxStone;
// bool visit[1501][1501];
// queue <pair <int, int>> q;

// pair <int, int> getBS(int a, int b) {
//   if(a > b) return {a, b};
//   else return {b, a};
// }

// bool pushToQ_and_checkIsOver(pair <int, int> bs) {
//   bs.first -= bs.second;
//   bs.second *= 2;

//   if(!visit[bs.first][bs.second]) {
//     int bsThird = maxStone - bs.first - bs.second;
//     q.push(bs);
//     visit[bs.first][bs.second] = true;
//     visit[bs.first][bsThird] = true;

//     visit[bs.second][bs.first] = true;
//     visit[bs.second][bsThird] = true;
    
//     visit[bsThird][bs.first] = true;
//     visit[bsThird][bs.second] = true;
//   }

//   if(bs.first == bs.second && bs.first * 3 == maxStone) return true;
//   else return false;
// }

// bool provide_pushToQ_and_checkIsOver(int a, int b, int c) {
//   pair <int, int> bs;

//   if(a != b) {
//     bs = getBS(a, b);
//     if(pushToQ_and_checkIsOver(bs)) return true;
//   }
//   if(a != c) {
//     bs = getBS(a, c);
//     if(pushToQ_and_checkIsOver(bs)) return true;
//   }
//   if(b != c) {
//     bs = getBS(b, c);
//     if(pushToQ_and_checkIsOver(bs)) return true;
//   }

//   return false;
// }

// int main() {
//   pair <int, int> g;
//   cin >> g.first >> g.second >> maxStone;
//   maxStone += g.first + g.second;

//   q.push(g);

//   if(maxStone % 3 == 0) {
//     while(!q.empty()) {
//       pair <int, int> f = q.front(); q.pop();

//       if(provide_pushToQ_and_checkIsOver(f.first, f.second, maxStone - f.first - f.second)) {
//         cout << 1;
//         return 0;
//       }
//     }
//   }

//   cout << 0;
// }

//총 돌의 갯수는 변하지 않음을 이용하여 2차원 배열로

// #include <iostream>
// #include <queue>
// #include <vector>
// #include <algorithm>

// using namespace std;

// bool visit[501][501][501];
// queue <vector <int>> q;

// pair <int, int> getBS(int a, int b) { // big, small
//   if(a > b) return {a, b};
//   else return {b, a};
// }

// vector <int> getNewG(pair <int, int> bs, int item) {
//   vector <int> res (3);

//   res[0] = bs.first - bs.second;
//   res[1] = bs.second * 2;
//   res[2] = item;
//   sort(res.begin(), res.end());

//   return res;
// }

// void pushToQ(vector <int> newG) {
//   if(!visit[newG[0]][newG[1]][newG[2]]) {
//     q.push(newG);
//     visit[newG[0]][newG[1]][newG[2]] = true;
//   }
// }

// bool isOver(vector <int> newG) {
//   return newG[0] == newG[1] && newG[1] == newG[2];
// }

// bool pushToQ_And_CheckIsOver(vector <int> g) {
//   vector <int> newG;

//   if(g[0] != g[1]) {
//     newG = getNewG(getBS(g[0], g[1]), g[2]);
//     pushToQ(newG);
//     if(isOver(newG)) return true;
//   }

//   if(g[0] != g[2]) {
//     newG = getNewG(getBS(g[0], g[2]), g[1]);
//     pushToQ(newG);
//     if(isOver(newG)) return true;
//   }

//     if(g[1] != g[2]) {
//     newG = getNewG(getBS(g[1], g[2]), g[0]);
//     pushToQ(newG);
//     if(isOver(newG)) return true;
//   }

//   return false;
// }

// int main() {
//   vector <int> g (3);
//   cin >> g[0] >> g[1] >> g[2];

//   if(pushToQ_And_CheckIsOver(g)) {
//     cout << 1;
//     return 0;
//   }

//   while(!q.empty()) {
//     g = q.front(); q.pop();
//     if(pushToQ_And_CheckIsOver(g)) {
//       cout << 1;
//       return 0;
//     }
//   }

//   cout << 0;
// }