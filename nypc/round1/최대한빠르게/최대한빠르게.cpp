// #include <iostream>
// #include <vector>

// using namespace std;
// using pii = pair <int, int>;

// const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

// int map[50][50], maxRow, maxCol, k;
// pii start, to;
// vector <pii> ans = {{-1, -1}};

// void input() {
//   cin >> maxRow >> maxCol >> k;
//   for(int i = 0; i < maxRow; i++) {
//     string t;
//     cin >> t;
//     for(int j = 0; j < maxCol; j++) {
//       char c = t[j];
//       switch (c) {
//         case '.': {
//           map[i][j] = 0;
//           break;
//         }
//         case '#': {
//           map[i][j] = -1;
//           break;
//         }
//         case '@': {
//           map[i][j] = 1;
//           break;
//         }
//         case 'S': {
//           map[i][j] = 0;
//           start = {i, j};
//           break;
//         }
//         default: {
//           map[i][j] = 0;
//           to = {i, j};
//         }
//       }
//     }
//   }
// }

// bool isArea(int r, int c) {
//   return 0 <= r && r < maxRow && 0 <= c && c < maxCol;
// }

// bool isBlocked(int r, int c, int d, int l) {
//   for(int i = 1; i <= l; i++) {
//     r += dy[d]; c += dx[d];
//     if(map[r][c] == -1) return true;
//   }
//   return false;
// }

// bool visited[32][50][50];
// vector <pii> trace(0);
// void dfs(int moveCnt, int r, int c, int cnt) {
//   // cout << moveCnt << ' ' << r << ' ' << c << ' ' << cnt << '\n';
//   if(r == to.first && c == to.second) {
//     if(trace.size() < ans.size() || ans[0].first == -1) {
//       ans = trace;
//     }
//     return;
//   }

//   if(ans[0].first != -1 && ans.size() < trace.size()) return;

//   for(int d = 0; d < 4; d++) {
//     for(int i = 1; i <= moveCnt; i++) {
//       int nr = r + dy[d] * i, nc = c + dx[d] * i;
//       if(isArea(nr, nc) && !visited[moveCnt][nr][nc] && !isBlocked(r, c, d, i)) {

//         bool sw = false;
//         visited[moveCnt][nr][nc] = true;
//         trace.push_back({i, d});
//         if(map[nr][nc] == 1) {
//           moveCnt++;
//           map[nr][nc] = 0;
//           sw = true;
//         }

//         dfs(moveCnt, nr, nc, cnt + 1);
//         if(sw) {
//           moveCnt--;
//           map[nr][nc] = 1;
//         }

//         trace.pop_back();
//         visited[moveCnt][nr][nc] = false;
//       }
//     }
//   }
// }

// char getDirection(int d) {
//   switch (d) {
//     case 0: return 'D';
//     case 1: return 'A';
//     case 2: return 'S';
//     default: return 'W';
//   }
// }

// int main() {
//   input();
//   cout << "check1\n";

//   dfs(1, start.first, start.second, 0);
//   cout << "check2\n";


//   cout << ans.size() << '\n';
//   for(pii i : ans) {
//     cout << getDirection(i.second) << ' ' << i.first << '\n';
//   }
// }

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
#include <cstdint>

struct Parent {
    int prev_idx = -1;
    char dir = 0;
    uint8_t step = 0;
};

struct State {
    int r, c, m; // 위치, 이동력
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C, K_ignore;
    if (!(std::cin >> R >> C >> K_ignore)) return 0;

    std::vector<std::string> grid(R);
    for (int i = 0; i < R; ++i) {
        std::cin >> grid[i];
    }

    auto inb = [&](int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    };

    const int dy[4] = {0, 0, 1, -1};
    const int dx[4] = {1, -1, 0, 0};
    const char dch[4] = {'D', 'A', 'S', 'W'};

    int sr=-1, sc=-1, tr=-1, tc=-1;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (grid[r][c] == 'S') { sr = r; sc = c; }
            else if (grid[r][c] == 'T') { tr = r; tc = c; }
        }
    }
    if (sr == -1 || tr == -1) { std::cout << -1 << "\n"; return 0; }

    // 방문: 각 위치에서 현재까지의 최대 이동력 기록
    std::vector<std::vector<int>> visited(R, std::vector<int>(C, -1));

    auto idx_of = [&](int r, int c) {
        return r * C + c;
    };
    auto decode = [&](int idx, int &r, int &c) {
        r = idx / C;
        c = idx % C;
    };

    std::deque<State> q;
    std::vector<Parent> parent(R * C * (R + C + 5)); // 넉넉하게

    int start_idx = idx_of(sr, sc);
    visited[sr][sc] = 1;
    q.push_back({sr, sc, 1});

    int goal_idx = -1, goal_m = -1;

    while (!q.empty()) {
        auto [r, c, m] = q.front(); q.pop_front();
        if (r == tr && c == tc) {
            goal_idx = idx_of(r, c);
            goal_m = m;
            break;
        }

        for (int d = 0; d < 4; ++d) {
            int nr = r, nc = c;
            int nm = m;
            for (int step = 1; step <= m; ++step) {
                nr += dy[d]; nc += dx[d];
                if (!inb(nr, nc) || grid[nr][nc] == '#') break;
                if (grid[nr][nc] == '@') nm++;

                if (nm > visited[nr][nc]) {
                    visited[nr][nc] = nm;
                    int nxt_idx = idx_of(nr, nc);
                    parent[nxt_idx + nm * R * C] = {idx_of(r, c) + m * R * C, dch[d], (uint8_t)step};
                    q.push_back({nr, nc, nm});
                    if (nr == tr && nc == tc) {
                        goal_idx = nxt_idx;
                        goal_m = nm;
                        goto END_BFS;
                    }
                }
            }
        }
    }
END_BFS:

    if (goal_idx == -1) {
        std::cout << -1 << "\n";
        return 0;
    }

    std::vector<std::pair<char,int>> path;
    int cur_idx = goal_idx + goal_m * R * C;
    while (parent[cur_idx].prev_idx != -1) {
        auto &p = parent[cur_idx];
        path.push_back({p.dir, p.step});
        cur_idx = p.prev_idx;
    }
    std::reverse(path.begin(), path.end());

    std::cout << path.size() << "\n";
    for (auto &mv : path) {
        std::cout << mv.first << ' ' << mv.second << "\n";
    }
    return 0;
}