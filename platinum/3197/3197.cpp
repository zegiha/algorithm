#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1500;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int R, C;
char lake[MAX][MAX];
bool visited[MAX][MAX];
bool swan_visited[MAX][MAX];
queue<pair<int, int>> water, swan;
queue<pair<int, int>> water_temp, swan_temp;
pair<int, int> swan_pos[2];

bool move_swan() {
    while (!swan.empty()) {
        int x = swan.front().first;
        int y = swan.front().second;
        swan.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (swan_visited[nx][ny]) continue;

            if (lake[nx][ny] == '.') {
                swan_visited[nx][ny] = true;
                swan.push({nx, ny});
            } else if (lake[nx][ny] == 'X') {
                swan_visited[nx][ny] = true;
                swan_temp.push({nx, ny});
            } else if (lake[nx][ny] == 'L') {
                return true;
            }
        }
    }
    return false;
}

void melt_ice() {
    while (!water.empty()) {
        int x = water.front().first;
        int y = water.front().second;
        water.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (visited[nx][ny]) continue;

            if (lake[nx][ny] == 'X') {
                lake[nx][ny] = '.';
                visited[nx][ny] = true;
                water_temp.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> R >> C;
    
    int swan_count = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> lake[i][j];
            if (lake[i][j] != 'X') {
                water.push({i, j});
                visited[i][j] = true;
            }
            if (lake[i][j] == 'L') {
                swan_pos[swan_count++] = {i, j};
            }
        }
    }

    swan.push(swan_pos[0]);
    swan_visited[swan_pos[0].first][swan_pos[0].second] = true;
    lake[swan_pos[1].first][swan_pos[1].second] = 'L'; // 두 번째 백조의 위치를 'L'로 유지

    int days = 0;
    while (true) {
        if (move_swan()) break;
        melt_ice();
        swan = swan_temp;
        water = water_temp;
        while (!swan_temp.empty()) swan_temp.pop();
        while (!water_temp.empty()) water_temp.pop();
        days++;
    }

    cout << days << endl;
    return 0;
}