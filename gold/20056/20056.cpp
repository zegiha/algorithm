#include <iostream>
#include <vector>

using namespace std;

struct FIREBALL {
  int r;
  int c;
  int m;
  int s;
  int d;
};

int n, m, k, dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<FIREBALL> map[55][55];
vector<FIREBALL> fireball;

int adjustArea(int req) {
  if (req >= n) return req % n;
  if (req < 0) return (req + n) % n;
  return req;
}

void move_and_mark() {
  for (auto& fb : fireball) {
    int s = fb.s % n;
    fb.r = adjustArea(fb.r + dr[fb.d] * s);
    fb.c = adjustArea(fb.c + dc[fb.d] * s);
    map[fb.r][fb.c].push_back(fb);
  }
}

void changeFireball() {
  vector<FIREBALL> new_fireballs;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j].size() > 1) {
        int newMass = 0, newSpeed = 0;
        bool allEven = true, allOdd = true;

        for (auto& fb : map[i][j]) {
          newMass += fb.m;
          newSpeed += fb.s;
          if (fb.d % 2 == 0) allOdd = false;
          else allEven = false;
        }

        newMass /= 5;
        newSpeed /= map[i][j].size();
        
        if (newMass > 0) {
          for (int d = (allEven || allOdd) ? 0 : 1; d < 8; d += 2) {
            new_fireballs.push_back({i, j, newMass, newSpeed, d});
          }
        }
      } else if (map[i][j].size() == 1) {
        new_fireballs.push_back(map[i][j][0]);
      }
      map[i][j].clear();
    }
  }
  
  fireball = move(new_fireballs);
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int r, c, m, s, d;
    cin >> r >> c >> m >> s >> d;
    r--; c--;
    fireball.push_back({r, c, m, s, d});
  }

  while (k--) {
    move_and_mark();
    changeFireball();
  }
  
  int ans = 0;
  for (auto& fb : fireball) ans += fb.m;
  cout << ans;
}
