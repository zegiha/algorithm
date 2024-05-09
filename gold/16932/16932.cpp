#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int n, m, ans;
vector <vector <int>> arr, g;
vector <int> gSum;
vector <pair <int, int>> b, e;

void add(vector <vector <bool>>* visit, vector <pair <int, int>>* added, int r, int c) {
  if(r + 1 < n) {
    if(!(*visit)[r + 1][c]) {
      added->push_back(make_pair(r + 1, c));
    }
  }
  if(r - 1 >= 0) {
    if(!(*visit)[r - 1][c]) {
      added->push_back(make_pair(r - 1, c));
    }
  }
  if(c + 1 < m) {
    if(!(*visit)[r][c + 1]) {
      added->push_back(make_pair(r, c + 1));
    }
  }
  if(c - 1 >= 0) {
    if(!(*visit)[r][c - 1]) {
      added->push_back(make_pair(r, c - 1));
    }
  }
}

void groupingBlock() {
  int gN = -1;
  vector <vector <bool>> visit;
  visit.resize(n + 1, vector <bool> (m + 1, false));
  for(int t = 0; t < b.size(); t++) {
    if(!visit[b[t].first][b[t].second]) {
      int sum = 0;
      stack <pair <int, int>> s;
      s.push(b[t]);
      visit[b[t].first][b[t].second] = true;
      gN++;
      while(!s.empty()) {
        int row = s.top().first, col = s.top().second;
        s.pop();
        sum++;
        g[row][col] = gN;
        vector <pair <int, int>> added;
        add(&visit, &added, row, col);
        for(int i = 0; i < added.size(); i++) {
          if(arr[added[i].first][added[i].second] == 1) {
            s.push(added[i]);
            visit[added[i].first][added[i].second] = true;
          }
        }
      }
      gSum.push_back(sum);
    }
  }
}

void addingToSpace() {
  vector <vector <bool>> visit;
  visit.resize(n + 1, vector <bool> (m + 1, false));
  for(int t = 0; t < e.size(); t++) {
    if(!visit[e[t].first][e[t].second]) {
      queue <pair <int, int>> q;
      q.push(e[t]);
      visit[e[t].first][e[t].second] = true;
      while(!q.empty()) {
        vector <bool> addVisit;
        vector <pair <int, int>> added;
        addVisit.resize(gSum.size(), false);
        int row = q.front().first, col = q.front().second, sum = 1;
        q.pop();

        add(&visit, &added, row, col);
        for(int i = 0; i < added.size(); i++) {
          int aRow = added[i].first, aCol = added[i].second;
          if(arr[aRow][aCol] == 0) {
            // cout << aRow << "  ||  " << aCol << endl << endl;
            q.push(added[i]);
            visit[aRow][aCol] = true;
          } else {
            if(!addVisit[g[aRow][aCol]]) {
              sum += gSum[g[aRow][aCol]];
              addVisit[g[aRow][aCol]] = true;
            }
          }
        }
        // cout << row << "  ||  " << col << "  ||  " << sum << endl;
        if(ans < sum) ans = sum;
        // cout << ans << endl << endl;
      }
    }
  }
}

int main() {
  cin >> n >> m;
  arr.resize(n + 1, vector <int> (m + 1, -1));
  g.resize(n + 1, vector <int> (m + 1, -1));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if(arr[i][j] == 1) b.push_back(make_pair(i, j));
      else e.push_back(make_pair(i, j));
    }
  }
  groupingBlock();
  addingToSpace();
  cout << ans;
}