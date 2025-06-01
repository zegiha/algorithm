#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair <int, int>;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

bool visited[101][101];

int arr[101][101], mr, mc;

void clearVisited() {
  for(int i = 0; i < 101; i++) {
    for(int j = 0; j < 101; j++)
      visited[i][j] = false;
  }
}

bool isArea(int r, int c) {
  return
  1 <= r && r <= mr &&
  1 <= c && c <= mc;
}

pair <vector <pii>, vector<pii>> getClusterAndGetlowestMinerals(int r, int c) {
  vector <pii> cluster(1, {r, c}), lowestMinerals(1, {r, c});

  queue <pii> q;
  clearVisited();

  q.push({r, c});
  visited[r][c] = true;

  int nr, nc;
  while(!q.empty()) {
    int r = q.front().first, c = q.front().second;
    q.pop();

    for(int d = 0; d < 4; d++) {
      nr = r + dy[d]; nc = c + dx[d];
      if(isArea(nr, nc) && !visited[nr][nc] && arr[nr][nc]) {
        q.push({nr, nc});
        visited[nr][nc] = true;

        cluster.push_back({nr, nc});
        if(nr < lowestMinerals[0].first) {
          lowestMinerals.clear();
          lowestMinerals.push_back({nr, nc});
        }
        else if(nr == lowestMinerals[0].first) {
          lowestMinerals.push_back({nr, nc});
        }
      }
    }
  }

  return {cluster, lowestMinerals};
}

int getDownLength(pii target) {
  int res = 0, r = target.first, c = target.second;
  while(r > 0) {
    res++;
    r--;
    if(arr[r][c] == 1) break;
  }

  return res-1;
}

void findAndDown(pii target) {
  int nr, nc;
  for(int d = 0; d < 4; d++) {
    nr = target.first + dy[d]; nc = target.second + dx[d];
    if(isArea(nr, nc) && arr[nr][nc]) {
      pair <vector <pii>, vector <pii>> clusterAndLowestMineral = getClusterAndGetlowestMinerals(nr, nc);

      vector <pii> cluster = clusterAndLowestMineral.first;
      vector <pii> lowestMinerals = clusterAndLowestMineral.second;

      if(cluster.size() == 0) continue;

      if(lowestMinerals[0].first > 1) {
        int downLength = 2'100'000'000;
        for(auto t: cluster) arr[t.first][t.second] = 0;
        for(auto t: cluster) downLength = min(getDownLength(t), downLength);
        for(auto t: cluster) arr[t.first - downLength][t.second] = 1;
      }
    }
  }
}

int breakAndGetBreakPoint(int r, int dir) {
  if(dir == 0) {
    for(int i = 1; i <= mc; i++) {
      if(arr[r][i] == 1) {
        arr[r][i] = 0;
        return i;
      }
    }
  } else {
    for(int i = mc; i >= 1; i--) {
      if(arr[r][i] == 1) {
        arr[r][i] = 0;
        return i;
      }
    }
  }

  return -1;
}

int main() {
  char c;
  cin >> mr >> mc;
  for(int i = mr; i > 0; i--) {
    for(int j = mc; j > 0; j--) {
      cin >> c;
      if(c == '.') arr[i][j] = 0;
      else arr[i][j] = 1;
    }
  }

  int n, t; cin >> n;
  bool dir = true;
  while(n--) {
    cin >> t;
    pii target = {t, breakAndGetBreakPoint(t, dir)};
    if(target.second != -1) findAndDown(target);
    dir = !dir;
  }

  for(int i = mr; i > 0; i--) {
    for(int j = mc; j > 0; j--) {
      if(arr[i][j]) cout << 'x';
      else cout << '.';
    }
    cout << '\n';
  }
}