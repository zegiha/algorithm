#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, w, h;
vector <vector <int>> arr;
vector <pair <int, int>> wall;
vector <vector <bool>> visit;
pair <int, int> s, e;

bool isWall(int startRow, int startCol) {
    int endRow = startRow + h, endCol = startCol + w;
    for(int i = 0; i < wall.size(); i++) {
        if(
            ((startRow <= wall[i].first) && (wall[i].first <= endRow)) &&
            ((startCol <= wall[i].second) && (wall[i].second <= endCol))) return false;
    }
    return true;
}

void addToQ(queue <pair <int, int>>* q, int row, int col) {
    if((row + h) + 1 < n) {
        // cout << row + 1 << col << " row, col  ||  it can compare\n";
        if(isWall(row + 1, col) && !visit[row + 1][col]) {
            // cout << row + 1 << col << " row, col\n";
            visit[row + 1][col] = true;
            q->push(make_pair(row + 1, col));
        }
    }
    if((row) - 1 >= 0) {
        // cout << row - 1 << col << " row, col  ||  it can compare\n";
        if(isWall(row - 1, col) && !visit[row - 1][col]) {
            // cout << row - 1 << col << " row, col\n";
            visit[row - 1][col] = true;
            q->push(make_pair(row - 1, col));
        }
    }
    if((col + w) + 1 < m) {
        // cout << row <<  col + 1 << " row, col  ||  it can compare\n";
        if(isWall(row, col + 1) && !visit[row][col + 1]) {
            // cout << row <<  col + 1 << " row, col\n";
            visit[row][col + 1] = true;
            q->push(make_pair(row, col + 1));
        }
    }
    if((col) - 1 >= 0) {
        // cout << row << col - 1 << " row, col  ||  it can compare\n";
        if(isWall(row, col - 1) && !visit[row][col - 1]) {
            // cout << row << col - 1 << " row, col\n";
            visit[row][col - 1] = true;
            q->push(make_pair(row, col - 1));
        }
    }
}

int main() {
    cin >> n >> m;
    arr.resize(n + 1, vector <int> (m + 1, 0));
    visit.resize(n + 1, vector <bool> (m + 1, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) wall.push_back(make_pair(i, j));
        }
    }
    cin >> h >> w >> s.first >> s.second >> e.first >> e.second;
    h--;
    w--;
    s.first--;
    s.second--;
    e.first--;
    e.second--;

    int cnt = 0;
    queue <pair<int, int>> q;
    q.push(s);
    visit[s.first][s.second] = true;
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            if((row == e.first) && (col == e.second)) {
                cout << cnt;
                return 0;
            }
            addToQ(&q, row, col);
            // cout << row << col << "root row, col\n";
            // cout << "\nnext -----------------------------\n";
        }
        cnt++;
    }
    cout << -1;
}